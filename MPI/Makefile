# export OMPI_CXX=G++-10
# mpirun -np 5 ./StandardScaler
COMPILE_COMMAND := mpicxx

all: StandardScaler

StandardScaler: StandardScaler.cpp
	$(COMPILE_COMMAND) StandardScaler.cpp Service.cpp dataSet.cpp -o StandardScaler