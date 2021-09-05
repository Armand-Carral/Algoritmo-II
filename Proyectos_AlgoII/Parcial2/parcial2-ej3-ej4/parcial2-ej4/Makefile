CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
SOURCES = balanced.c helpers/stack.c helpers/queue.c #Aqui agrego los .c
OBJECTS = $(SOURCES:.c=.o)
TARGET = balanced  #Aquir agrego el nombre del ejecutable

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

run:
	./$(TARGET) "{[2 * 3) + 4] - (7* 8)} / 2"
