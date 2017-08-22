.PHONY: all
.PHONY: lasync
.PHONY: laclient
.PHONY: libs
.PHONY: ut
.PHONY: binaries

CXXFLAGS = -g -fpermissive -lpthread -I lib lib/*.o

all: binaries

binaries: lasync laclient

lasync: libs lasync.cpp
	$(CXX) $(CXXFLAGS) lasync.cpp -o $@ 

laclient: libs laclient.cpp
	$(CXX) $(CXXFLAGS) laclient.cpp -lpthread -o $@ 

ut:
	cd ut; $(MAKE)

libs:
	cd lib; $(MAKE)

clean:
	rm -fr lasync laclient
	cd ut; $(MAKE) clean
	cd lib; $(MAKE) clean
