CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/memlog.o $(OBJ)/ImagemPPM.o $(OBJ)/ImagemPGM.o $(OBJ)/Main.o
HDRS = $(INC)/memlog.hpp $(INC)/msgassert.hpp $(INC)/ImagemPPM.hpp $(INC)/ImagemPGM.hpp
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/Main

all:  mem perf gprof

mem: $(EXE)
	$(EXE) -i sample/bolao.ppm -o output/bolao.pgm -p tmp/bolaolog.out -l

perf: $(EXE)
	$(EXE) -i sample/bolao.ppm -o output/bolao.pgm -p tmp/bolao.out
	$(EXE) -i sample/lagoa.ppm -o output/lagoa.pgm -p tmp/lagoa.out

gprof: $(BIN)/Main
	$(EXE) -i sample/lagoa.ppm -o output/lagoa.pgm -p tmp/bolaogprof.out
	gprof $(EXE) gmon.out > tmp/bolaogprof.txt

$(BIN)/Main: $(OBJS)
	$(CC) -pg -o $(BIN)/Main $(OBJS) $(LIBS)

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp 

$(OBJ)/ImagemPPM.o: $(HDRS) $(SRC)/ImagemPPM.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ImagemPPM.o $(SRC)/ImagemPPM.cpp 

$(OBJ)/ImagemPGM.o: $(HDRS) $(SRC)/ImagemPGM.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ImagemPGM.o $(SRC)/ImagemPGM.cpp 

$(OBJ)/Main.o: $(HDRS) $(SRC)/Main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Main.o $(SRC)/Main.cpp 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out tmp/*.out tmp/*.txt