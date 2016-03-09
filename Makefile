decode: main.o
	g++ main.o -o decode

main.o: main.cpp
	g++ -c main.cpp

encode: encode.o
	g++ encode.o -o encode

encode.o: encode.cpp
	g++ -c encode.cpp

clean:
	rm *.o encode decode
