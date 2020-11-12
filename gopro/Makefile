CC=g++
LDFLAGS=-lcurl
GTEST_FLAGS=-lgtest -lpthread

.PHONY: test example timelapse

all: test example timelapse

test:
	$(CC) gopro.cpp test_gopro.cpp HTTPRequest.cpp $(LDFLAGS) $(GTEST_FLAGS) -o gtest

example:
	$(CC) gopro.cpp main.cpp HTTPRequest.cpp $(LDFLAGS) -o example 

timelapse:
	$(CC) gopro.cpp timelapse.cpp HTTPRequest.cpp $(LDFLAGS) -o timelapse
