# edit this makefile so that running make compiles your enigma program

CC = g++
CFLAGS = -Wall
DEPS = Enigma.h Mapping.h Rotor.h Plugboard.h Reflector.h
OBJ = Main.o Enigma.o Mapping.o Rotor.o Plugboard.o Reflector.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

enigma: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -rf enigma *.o

.PHONY: clean
