OBJECT=./BigInt/BigInt.o
BigIntCli:$(OBJECT) BigIntCli.o
	g++ -o BigIntCli BigIntCli.o $(OBJECT)
BigIntCli.o:BigIntCli.cpp
	g++ -o BigIntCli.o -c BigIntCli.cpp -g
clean:
	rm BigIntCli *.o
