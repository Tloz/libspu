CC = g++
CFLAGS=--std=c++11
LDFLAGS=-Lbin
CFLAGSSTRICT=-W -Wall -Wextra -pedantic
CFLAGSSUPERSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable
CFLAGSOPT=-O3

all: libspu tests

libspu: bin/libspu.a

bin/libspu.a: obj/version.o obj/random.o obj/base64.o obj/parser.o obj/2darray.o
	ar rcs $@ $^

tests: version random 2darray

######### PARTS ########
obj/version.o: src/version.cpp inc/version.h
	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

obj/random.o: src/random.cpp inc/random.h
	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

obj/base64.o: src/base64.cpp inc/base64.h
	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

obj/parser.o: src/parser.cpp inc/parser.h
	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

obj/2darray.o: src/2darray.cpp inc/2darray.h
	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

########################

######### TESTS ########
version: obj/version.o tests/version.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

random: obj/random.o tests/random.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

2darray: obj/2darray.o tests/2darray.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)


.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*