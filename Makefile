CC = g++
CFLAGS=--std=c++11
LDFLAGS=-Lbin -lspu
CFLAGSSTRICT=-W -Wall -Wextra -pedantic
CFLAGSSUPERSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable
CFLAGSOPT=-O3

all: libspu test

libspu: bin/libspu.a

test: bin/libspu.a main.cpp
	$(CC) $^ $(LDFLAGS) -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

bin/libspu.a: obj/random.o obj/base64.o
	ar rcs $@ $^

######## PARTS ########
obj/random.o: src/random.cpp inc/random.h
	$(CC) -c $< -o $@ $(CFLAGS)


obj/base64.o: src/base64.cpp inc/base64.h
	$(CC) -c $< -o $@ $(CFLAGS)


########################


.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*