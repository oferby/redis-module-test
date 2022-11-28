run create_module.sh


Test:

 g++ test-protobuf.c ../proto/opensm.pb-c.c -o test  -lhiredis -lprotobuf-c

 