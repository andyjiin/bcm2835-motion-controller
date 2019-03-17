TARGET = main

SRC = src
INC = inc
BIN = bin

# Directories
COMMON = common
HAL = hal

SOURCE = $(wildcard $(COMMON)/$(SRC)/*.c) \
         $(wildcard $(HAL)/*.c) \
         $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)

CC = gcc
CLFAGS = -Wall

$(BIN)/$(TARGET) : $(OBJECT)
	$(CC) -o $@ $^

$(BIN)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : help run

run : $(BIN)/$(TARGET)
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECT) $(BIN)/$(TARGET)

help :
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"