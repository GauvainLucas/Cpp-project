CC=g++
CCFLAGS= -Wall -std=c++11 -g
LIBFLAGS= 
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= eco.out


testcase:
	cd tests ; make
test : testcase
	./tests/testcase.out

all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@  

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) *.*~
distclean :
	cd tests; make clean
	rm -f $(OBJ) $(EXEC) *.*~	
