CC=g++
CFLAGS=-Wall

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)


all: $(OBJS)
	$(CC) -o test $(OBJS) $(LDFLAGS) -lcppunit

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test $(OBJS)
