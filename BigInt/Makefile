test : test.o bigInt.o 
	g++ -o test test.o bigInt.o 

test.o : test.cpp 
	g++ -o test.o -c test.cpp -g

bigInt.o : include/bigInt.cpp include/seqlist.h include/utility.h
	g++ -o bigInt.o -c include/bigInt.cpp -g

.PHONY : clean 

clean :
	rm -fr test.o test bigInt.o
