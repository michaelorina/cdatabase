CC = gcc
CFLAGS = -Iinclude -Wall -Werror -pthread
OBJ = src/db.o src/cache.o src/main.o
TARGET = cdatabase

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

src/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f src/*.o $(TARGET)