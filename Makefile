# Entry point for Make-ing.

.PHONY: all lf-cent lf-decent lf-unfed mpi openmp no-distributed clean

# CURRENTLY NO LF IMPLEMENTATIONS. UNCOMMENT WHEN IMPLEMENTED.

# all: lf-cent lf-decent lf-unfed mpi openmp no-distributed
all: mpi openmp no-distributed
	echo ""

# lf-cent:
# 	$(MAKE) -C src/lf-cent

# lf-decent:
# 	$(MAKE) -C src/lf-decent

# lf-unfed:
# 	$(MAKE) -C src/lf-unfed

# run:
# 	$(MAKE) -C src/lf-cent run
# 	$(MAKE) -C src/lf-decent run
# 	$(MAKE) -C src/lf-unfed run
# 	$(MAKE) -C src/mpi run
# 	$(MAKE) -C src/openmp run
# 	$(MAKE) -C src/no-distributed run

run:
	echo "No Distributed Implementation:"
	$(MAKE) -C src/no-distributed run
	echo ""
	echo "MPI Implementation:"
	$(MAKE) -C src/mpi run
	echo ""
	echo "OpenMP Implementation:"
	$(MAKE) -C src/openmp run

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