OBJECT=./BigInt/BigInt.o
BigIntSer:$(OBJECT) BigIntSer.o
	g++ -o BigIntSer BigIntSer.o $(OBJECT)
BigIntSer.o:BigIntSer.cpp
	g++ -o BigIntSer.o -c BigIntSer.cpp -g
clean:
	rm BigIntSer *.o
