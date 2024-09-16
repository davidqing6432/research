
CC=gcc
CFLAGS=-fopenmp
TARGETS=main

all: $(TARGETS)

# Rule to compile each OpenMP program
%: %.c
	mkdir -p ../../bin/openmp
	$(CC) $(CFLAGS) -o ../../bin/openmp/$@ $<

run:
	../../bin/openmp/$(TARGETS)

clean:
	rm -f ../../bin/openmp/$(TARGETS)