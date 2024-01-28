CC=g++
CCFLAGS= -Wall -std=c++11 -g
LIBFLAGS= 
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= applicationJO.out


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) *.*~
distclean :
	make clean
	rm -f $(OBJ) $(EXEC) *.*~	
