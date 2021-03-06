CC = g++
CFLAG = --std=c++11
OBJ = main.o \
      diamondsquare.o \
      heightmapDrawer.o \
      lodepng.o
HEADERS = $(wildcard *.h)
EXEC = ds

all : main

%.o : %.cpp
	$(CC) -c $< -o $@ $(CFLAG)

main : $(OBJ) $(HEADERS)
	$(CC) -o $(EXEC) $(OBJ)

.PHONY : clean
clean :
	rm $(EXEC) $(OBJ)
