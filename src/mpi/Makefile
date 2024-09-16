
CC=mpicc
TARGETS=main

all: $(TARGETS)

# Rule to compile each OpenMP program
%: %.c
	mkdir -p ../../bin/mpi
	$(CC) -o ../../bin/mpi/$@ $<

# CURRENTLY DANGEROUS: --allow-run-as-root
run:
	mpirun --allow-run-as-root -np 4 ../../bin/mpi/$(TARGETS)

clean:
	rm -f ../../bin/mpi/$(TARGETS)