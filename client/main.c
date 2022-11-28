#include <stdlib.h>
#include "../proto/opensm.pb-c.h"
#include <hiredis/hiredis.h>
#include "../common.h"
// #include <hiredis/hiredis_ssl.h>


void print_usage() {
    printf("USAGE: client [ip] [port]");
}


int set_port_command(redisContext *c) {

    redisReply *reply;

    void *buf = NULL;   /* Buffer to store serialized data */
    size_t len;         // buffer size

    StoreMessage msg = STORE_MESSAGE__INIT;
    msg.n_ports = 1;
    msg.ports = (Port**) calloc(1, sizeof(Port));

    Port p = PORT__INIT;
    p.portguid = 123456789;

    msg.ports[0] = &p;
    msg.timestamp = 9876;

    len = store_message__get_packed_size(&msg);
    buf = calloc(1, len);
    store_message__pack(&msg, (uint8_t*) buf);

    reply = (redisReply*) redisCommand(c, "%s %s", STORE_COMMAND_SET, buf);

    if (reply->len > 0)
        printf("SET: %s\n", reply->str);
    else
        printf("SET (int): %lli\n", reply->integer);
    
    free(buf);
    freeReplyObject(reply);
    return 0;
     
}

int get_port_command(redisContext *c, const char* key) {

    redisReply *reply;

    reply = (redisReply*) redisCommand(c, "%s %s", STORE_COMMAND_GET, key);
    printf("GET: %s\n", reply->str);    

    return 0;

}


int main (int argc, char **argv) {

    int err;
    redisContext *c;
    const char *hostname = (argc > 1) ? argv[1] : "192.168.67.183";

    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    puts("connected...");


    err = set_port_command(c);

    // puts("back...");


    // err = get_port_command(c);

    redisFree(c);
    

}