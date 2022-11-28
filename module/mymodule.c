
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "redismodule.h"
#include "../common.h"
#include "../proto/opensm.pb-c.h"

#define PORT_KEY_PREFIX "PORT"
#define NODE_KEY_PREFIX "NODE"

/** Function to pass to protobuf functions to allocate memory. */
static void * protobuf_alloc_cb(void *allocator_data, size_t size)
{
    return RedisModule_Calloc(1, size);
}

/** Function to pass to protobuf functions to free memory. */
static void protobuf_free_cb(void *allocator_data, void *pointer)
{
    RedisModule_Free(pointer);
}

struct ProtobufCAllocator* store_protobuf_allocator_get()
{
    static struct ProtobufCAllocator protobuf_allocator = {
        .alloc = protobuf_alloc_cb,
        .free = protobuf_free_cb,
        .allocator_data = NULL
    };

    return &protobuf_allocator;
}


int setPort(RedisModuleCtx *ctx, Port* port) {
    
    uint8_t*      buf;
    char* c_key;

    size_t t = sizeof(PORT_KEY_PREFIX)+ sizeof(port->portguid) + 1;

    c_key = calloc(1, t);
    sprintf(c_key, "%s:%ld", PORT_KEY_PREFIX,  port->portguid);

    RedisModuleString* str_for_key = RedisModule_CreateString(ctx, c_key, t);
    
    RedisModuleKey *key = RedisModule_OpenKey(ctx, str_for_key, REDISMODULE_WRITE);
    if (RedisModule_KeyType(key) == REDISMODULE_KEYTYPE_EMPTY) {
        size_t len = port__get_packed_size(port);
        buf = calloc(1, len);
        size_t pack_len = port__pack(port, buf);
        RedisModuleString* str = RedisModule_CreateString(ctx, buf, pack_len);
        RedisModule_StringSet(key, str);
    } else {
        return 1;
    }
    
    return t;
}



int SetPortRedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    // RedisModule_Log(ctx, "warning ", "got SET command");

    StoreMessage* msg = NULL;
    size_t        len = 0;
    const char*   ptr = NULL;


    ptr = RedisModule_StringPtrLen(argv[1], &len);

    msg = store_message__unpack(store_protobuf_allocator_get(), len, (uint8_t*)ptr);

    int val = 0;

    for (int i = 0; i < msg->n_ports; i++) {

        Port* p = msg->ports[i];
        val+=setPort(ctx, p);

    }

    RedisModule_ReplyWithLongLong(ctx, val);
    return REDISMODULE_OK;

}

int GetPortRedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    size_t        len = 0;
    const char*   ptr = NULL;
    char* c_key;

    ptr = RedisModule_StringPtrLen(argv[1], &len);

    size_t t = sizeof(PORT_KEY_PREFIX)+ len;
    c_key = calloc(1, t);
    sprintf(c_key, "%s:%s", PORT_KEY_PREFIX,  ptr);

    RedisModuleString* str_for_key = RedisModule_CreateString(ctx, c_key, t);
    
    RedisModuleKey *key = RedisModule_OpenKey(ctx, str_for_key, REDISMODULE_READ);
    if (RedisModule_KeyType(key) == REDISMODULE_KEYTYPE_EMPTY) {
        // RedisModule_ReplyWithCString(ctx, c_key);
        RedisModule_ReplyWithLongLong(ctx, t);    
    } else {
        size_t str_len = RedisModule_ValueLength(key);
        char* str = RedisModule_StringDMA(key, &str_len, REDISMODULE_READ);
        RedisModule_ReplyWithCString(ctx, str);
        // RedisModule_ReplyWithLongLong(ctx, str_len);    
    }
    
    return REDISMODULE_OK;

}



int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    if (RedisModule_Init(ctx,STORE_COMMAND_PREFIX,1,REDISMODULE_APIVER_1)
        == REDISMODULE_ERR) return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, STORE_COMMAND_SET,
        SetPortRedisCommand, "fast write pubsub",
        0, 0, 0) == REDISMODULE_ERR)
        return REDISMODULE_ERR;
    
    if (RedisModule_CreateCommand(ctx, STORE_COMMAND_GET,
        GetPortRedisCommand, "fast readonly",
        0, 0, 0) == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    return REDISMODULE_OK;
}