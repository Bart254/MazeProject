SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRCS:.c=.o)
CC = gcc
EXEC = maze
CFLAGS = -Wall -Werror -Wextra -pedantic
LIB = -lm -lSDL2 -lSDL2_image

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(EXEC)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
