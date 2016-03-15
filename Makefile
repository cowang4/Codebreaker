CC = g++
CFLAGS = -Wall

decode: main.o
	$(CC) $(CFLAGS) -o decode main.o

main.o: main.cpp freq.h grade.h guess.h
	$(CC) $(CFLAGS) -c main.cpp

encode: encode.o
	$(CC) $(CFLAGS) encode.o -o encode

encode.o: encode.cpp
	$(CC) $(CFLAGS) -c encode.cpp

clean:
	rm *.o encode decode
