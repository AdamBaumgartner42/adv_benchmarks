# Use Ubuntu as the base image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    libglib2.0-dev \
    libfdt-dev \
    libpixman-1-dev \
    zlib1g-dev \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip \
    wget \
    sudo \
    vim \
    curl \
    gdb \
    make \
    kmod \
    # -----------------------
    # Compiler: 64 bit x86
    gcc-x86-64-linux-gnu \
    # Compiler: 64 bit ARM  
    gcc-aarch64-linux-gnu \
    # Compiler: 64 bit RISCV 
    gcc-riscv64-linux-gnu \
    # Compiler: 32 bit MIPS 
    gcc-mips-linux-gnu \
    # -----------------------
    # Emulator: 64 bit x86
    qemu-system-x86 \
    # Emulator: 64 bit ARM
    qemu-system-aarch64 \
    # Emulator: 64 bit RISCV
    qemu-system-riscv64 \
    # Emulator: 32 bit MIPS
    qemu-system-mips \
    # Emulator: unknown
    qemu-user \
    # Emulator: unknown
    qemu-user-static
    # -----------------------

# Create a user and set up home directory
ARG USERNAME=nbeser1
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Add the user to the kvm group for KVM access
RUN groupadd kvm || true
RUN usermod -aG kvm $USERNAME

USER $USERNAME
WORKDIR /home/$USERNAME

# Set the working directory and open bash
WORKDIR /home/$USERNAME
CMD ["bash"]
