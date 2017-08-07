
objs = $(shell files=""; for file in `ls *.cpp *.c 2>/dev/null`; do obj=`echo $$file |sed -r 's/(.*)\.cpp/\1.o/g'`; files="$$files $$obj"; done ; echo $$files)

CXXFLAGS = -g

all: $(objs)

clean:
	rm -fr $(objs)
