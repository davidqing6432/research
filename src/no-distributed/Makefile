
CC=gcc
TARGETS=main

all: $(TARGETS)

# Rule to compile each OpenMP program
%: %.c
	mkdir -p ../../bin/no-distributed
	$(CC) $(CFLAGS) -o ../../bin/no-distributed/$@ $<

clean:
	rm -f ../../bin/no-distributed/$(TARGETS)