gcc *.c ../proto/*.c -c -fPIC
gcc *.o /root/dev/protobuf-c/protobuf-c/.libs/protobuf-c.o   -shared -o mymodule.so
