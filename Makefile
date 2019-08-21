# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -ggdb -O0 -Qunused-arguments -std=c99 -Wall -Werror
CFLAGS+ = -g

output: main.o message.o calculator.o
        g++ -std=c++11 -g main.o message.o calculator.o -o output.out

main.o: main.cpp
        g++ -std=c++11  -g -c main.cpp

message.o: message.cpp message.h
        g++ -std=c++11 -g -c message.cpp

calculator.o: calculator.cpp calculator.h
        g++ -std=c++11 -g -c calculator.cpp
clean:
        rm *.o output.out
