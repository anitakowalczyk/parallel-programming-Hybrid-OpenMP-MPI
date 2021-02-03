FLAGS := -O3 -fopenmp -m64 -std=c++14
COMPILE_COMMAND := g++-10 $(FLAGS)

all: StandardScaler

StandardScaler: StandardScaler.cpp
	$(COMPILE_COMMAND) -o StandardScaler StandardScaler.cpp Service.cpp dataSet.cpp