test:test.o BigInt.o
	g++ -o test test.o BigInt.o -g
test.o:test.cpp
	g++ -o test.o -c test.cpp -g
BigInt.o:BigInt.cpp utili.h
	g++ -o BigInt.o -c BigInt.cpp -g
.PHONY:clean
clean:
	rm -rf *.o test
