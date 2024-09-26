# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -fstack-protector-strong -no-pie

# Target executable lsname
TARGET = ret2win2

# Source files
SRCS = challenge.c

# Object files (auto-generated from source files)
OBJS = $(SRCS:.c=.o)

# Rule to build the target executable
$(TARGET): $(OBJS)
        $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
        rm -f $(OBJS) $(TARGET)

# Phony targets (to avoid conflict with actual files)
.PHONY: clean
