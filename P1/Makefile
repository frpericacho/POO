CXX = clang++
STD = c++17
CXXFLAGS = -std=${STD} -g -Wall -pedantic -Wextra
CPPFLAGS = -DP1 -I../Tests-auto -I.
VPATH = ../Tests-auto:.
SRC = fecha.cpp test-auto.cpp test-caso0-fecha-auto.cpp test-P1-consola.cpp cadena.cpp test-caso0-cadena-auto.cpp

RMV = rm -f
OBJ := $(SRC:.cpp=.o)
EXE = test-P1-consola
AUTO = test-auto

all: ${EXE} ${AUTO}

run-auto: ${AUTO}
	./$<

run-console: ${EXE}
	./$<

run-dsl: fecha_check cadena_check
	./fecha_check fecha.cpp -- -std=${STD}
	./cadena_check cadena.cpp -- -std=${STD}

fecha_check: fecha_check.cpp 
	$(MAKE) -f Make_check.mk


${EXE}: fecha.o test-P1-consola.o
	$(CXX) $(CXXFLAGS) $^ -o $@

${AUTO}: test-caso0-cadena-auto.o test-auto.o fecha.o cadena.o test-caso0-fecha-auto.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJ): $(SRC)

cadena_check: cadena_check.cpp
	${MAKE} -f Make_check.mk

clean: 
	$(RMV) *.o
	$(MAKE) -f Make_check.mk clean