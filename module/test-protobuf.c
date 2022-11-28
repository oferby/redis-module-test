#include <stdlib.h>
#include <cstdio>
#include "../proto/opensm.pb-c.h"
// #include <hiredis/hiredis.h>
// #include "redismodule.h"
#include "../common.h"
// #include <hiredis/hiredis_ssl.h>

/** Function to pass to protobuf functions to allocate memory. */
static void * protobuf_alloc_cb(void *allocator_data, size_t size)
{
    return calloc(1, size);
}

/** Function to pass to protobuf functions to free memory. */
static void protobuf_free_cb(void *allocator_data, void *pointer)
{
    free(pointer);
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

int main (int argc, char **argv) {

    void *buf = NULL;   /* Buffer to store serialized data */
    size_t len;         // buffer size
    size_t req_len = 0;

    StoreMessage msg = STORE_MESSAGE__INIT;
    msg.n_ports = 1;
    msg.ports = (Port**) calloc(1, sizeof(Port));

    Port *p;
    p = (Port*) calloc(1, sizeof(Port));
    port__init(p);
    p->portguid = 12345;

    msg.ports[0] = p;
    msg.timestamp = 9876;

    printf("portGUID = %li\n", msg.ports[0]->portguid);

    len = store_message__get_packed_size(&msg);
    buf = calloc(1, len);
    req_len = store_message__pack(&msg, (uint8_t*) buf);

    // back 


    StoreMessage *msg2 = NULL;
    const char   *ptr = NULL;


    msg2 = store_message__unpack(store_protobuf_allocator_get(), req_len, (uint8_t*) buf);


    printf("timestamp: %li\n", msg2->timestamp);
    printf("portGUID: %li\n", msg2->ports[0]->portguid);



}