# export OMPI_CXX=G++-10
# mpirun -np 2 ./StandardScaler
FLAGS := -O3 -fopenmp -m64 -std=c++14
COMPILE_COMMAND := mpicxx $(FLAGS)

all: StandardScaler

StandardScaler: StandardScaler.cpp
	$(COMPILE_COMMAND) StandardScaler.cpp Service.cpp dataSet.cpp -o StandardScaler