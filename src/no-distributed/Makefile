
CC=gcc
TARGETS=main

all: $(TARGETS)

# Rule to compile each OpenMP program
%: %.c
	mkdir -p ../../bin/no-distributed
	$(CC) -o ../../bin/no-distributed/$@ $<

run:
	../../bin/no-distributed/$(TARGETS)

clean:
	rm -f ../../bin/no-distributed/$(TARGETS)