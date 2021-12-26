#gcc src/* -o main -I/home/albvs/storage/programming/vcpkg/installed/x64-linux/include -L/home/albvs/storage/programming/vcpkg/installed/x64-linux/lib -lrabbitmq

#gcc src/* -o foo.o -I/home/albvs/storage/programming/vcpkg/installed/x64-linux/include
#gcc -L/home/albvs/storage/programming/vcpkg/installed/x64-linux/lib librabbitmq.a foo.o -o main

gcc src/*.c -o main
