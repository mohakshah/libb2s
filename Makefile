CC = gcc
CFLAGS = -c -std=c99

prefix = /usr/local
TARGET_LIB = libb2s.a
PUBLIC_HEADER = src/blake2s.h

INSTALL = install
RM = rm -f
AR = ar
ARFLAGS = rcv

all: libb2s

libb2s: blake2s.o
	$(AR) rcv $(TARGET_LIB) blake2s.o

blake2s.o: src/blake2s-ref.c
	$(CC) $(CFLAGS) src/blake2s-ref.c -o blake2s.o

clean:
	$(RM) blake2s.o $(TARGET_LIB)

install: all
	$(INSTALL) -d -m 0755 $(prefix)/lib
	$(INSTALL) -d -m 0755 $(prefix)/include

	$(INSTALL) -m 0755 $(TARGET_LIB) $(prefix)/lib/
	$(INSTALL) -m 0644 $(PUBLIC_HEADER) $(prefix)/include/
