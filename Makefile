LDLIBS=-lSDL2

all: example

example: xsdl.c

clean:
	$(RM) example example.o xsdl.o
