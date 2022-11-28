
#include <stdlib.h>
#include "redismodule.h"
#include "../common.h"
#include "../proto/opensm.pb-c.h"


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

int SetPortRedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    // RedisModule_Log(ctx, "warning ", "got SET command");

    StoreMessage *msg = NULL;
    size_t        len = 0;
    const char   *ptr = NULL;

    ptr = RedisModule_StringPtrLen(argv[1], &len);

    msg = store_message__unpack(store_protobuf_allocator_get(), len, (uint8_t*)ptr);

    int val = msg->timestamp;

    // RedisModule_ReplyWithString(ctx, argv[0]);
    RedisModule_ReplyWithLongLong(ctx, val);
    return REDISMODULE_OK;

}

int GetPortRedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    RedisModule_Log(ctx, "warning ", "got GET command");

    RedisModule_ReplyWithCString(ctx, "OK");

    
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