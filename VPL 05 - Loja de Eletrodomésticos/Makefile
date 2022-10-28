CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main

fogao:
	$(CC) $(CFLAGS) -c src/fogao.cpp -o build/fogao.o

geladeira:
	$(CC) $(CFLAGS) -c src/geladeira.cpp -o build/geladeira.o

estoque:
	$(CC) $(CFLAGS) -c src/estoque.cpp -o build/estoque.o


main: fogao geladeira estoque
	$(CC) $(CFLAGS) build/fogao.o build/geladeira.o build/estoque.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
