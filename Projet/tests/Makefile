CC=g++
CCFLAGS= -Wall -std=c++11 -g
SRC:= $(wildcard ../*.cc )
SRC:= $(filter-out ../applicationJO.cc ../pageEvenements.cc ../pageBilleterie.cc, $(SRC))
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)


testcase.out : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase.out

depends:
	g++ -MM $(SRC) >.depends
-include .depends
