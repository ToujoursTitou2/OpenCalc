CORES := $(shell nproc)

CFLAGS := -Wall -Wextra

all: calc

calc:
	gcc $(CFLAGS) main.h main.c -o calc -pthread -lm -O3 -march=native -mtune=native -fopenmp -DNUM_THREADS=$(CORES) 
	mv calc /usr/local/bin
