# Use a base image with C development tools
FROM ubuntu:latest

# Set the maintainer label
LABEL maintainer="your_email@example.com"

# Update the package list and install essential development tools and Java
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    make \
    cmake \
    wget \
    git \
    curl \
    vim \
    openmpi-bin \
    libopenmpi-dev \
    libomp-dev \
    default-jdk

# Set JAVA_HOME environment variable
ENV JAVA_HOME="/usr/lib/jvm/default-java"
ENV PATH="$JAVA_HOME/bin:$PATH"

# Download and install the pre-built Lingua Franca CLI
RUN curl -Ls https://install.lf-lang.org | bash -s cli

# Set environment variables for MPI
ENV PATH="/usr/lib/openmpi:/usr/lib/openmpi/bin:$PATH"

# Set environment variables for Lingua Franca CLI
ENV PATH="/usr/local/bin/lf-cli/bin:$PATH"

# Create a working directory
WORKDIR /app

# Copy the test suite (your C code) into the container
COPY . /app

# Set the default command to open a bash terminal
CMD ["/bin/bash"]
