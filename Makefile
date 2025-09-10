# Root-level Makefile

# Default target (change PROJECT to the folder you want to build)
PROJECT ?= week1

# Source files (all .c files in the project folder)
SRC := $(wildcard $(PROJECT)/*.c)

# Output binary
BIN := $(PROJECT)/$(PROJECT).exe

# Compiler
CC := gcc

# Default rule
all: build

# Compile
build: $(BIN)

$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN)
	@echo "Compiled $(BIN)"

# Run
run: build
	@echo "Running $(BIN)..."
	@$(BIN)

# Clean
clean:
	del $(PROJECT)\*.exe
	@echo "Cleaned $(PROJECT) binaries"

.PHONY: all build run clean
