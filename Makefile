# Entry point for Make-ing.

.PHONY: all lf-cent lf-decent lf-unfed mpi openmp no-distributed clean

all: lf-cent lf-decent lf-unfed mpi openmp no-distributed

lf-cent:
	$(MAKE) -C src/lf-cent

lf-decent:
	$(MAKE) -C src/lf-decent

lf-unfed:
	$(MAKE) -C src/lf-unfed

mpi:
	$(MAKE) -C src/mpi

openmp:
	$(MAKE) -C src/openmp

no-distributed:
	$(MAKE) -C src/no-distributed

clean:
	$(MAKE) -C src/lf-cent clean
	$(MAKE) -C src/lf-decent clean
	$(MAKE) -C src/lf-unfed clean
	$(MAKE) -C src/mpi clean
	$(MAKE) -C src/openmp clean
	$(MAKE) -C src/no-distributed clean