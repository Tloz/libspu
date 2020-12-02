CC=g++
CFLAGS=--std=c++1z
LDFLAGS=-Lbin
CFLAGSSTRICT=-W -Wall -Wextra -pedantic
CFLAGSSUPERSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable
CFLAGSOPT=-O3

all: libspu tests

init:
	mkdir tmp bin out lib

archive: libspu header LICENSE version
	@mv tmp/libspu.h inc/libspu.h
	@ln out/libspu.a libspu.a
	tar -czf out/libspu.v$(shell ./bin/version).tar.gz LICENSE libspu.a inc/*.h
	@rm -rf inc/libspu.h
	@rm libspu.a

header: inc/version.h inc/random.h inc/parser.h inc/matrix2d.h
	@cat $^ > tmp/libspu.h

libspu: out/libspu.a

out/libspu.a: obj/version.o obj/random.o obj/parser.o obj/matrix2d.o
	ar rcs $@ $^

tests: version random matrix2d

######### PARTS ########
obj/version.o: src/version.cpp inc/version.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/random.o: src/random.cpp inc/random.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)

#obj/base64.o: src/base64.cpp inc/base64.h
#	$(CC) -c $< -o $@ $(CFLAGS)  $(CFLAGSSTRICT)

obj/parser.o: src/parser.cpp inc/parser.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/matrix2d.o: src/matrix2d.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)


########################

######### TESTS ########
version: obj/version.o tests/version.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

random: obj/random.o tests/random.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

#base64: obj/base64.o tests/base64.cpp
#	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

matrix2d: obj/matrix2d.o tests/matrix2d.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)



.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*
	@rm -rf out/*
	@rm -rf libspu.*
