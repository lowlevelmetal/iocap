CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2

BININT := bin-int
SRCS := $(wildcard src/*.c)
OBJS := $(subst src,$(BININT),$(SRCS:.c=.o))
EXEC := iocap

$(EXEC): init $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

bin-int/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

init:
	mkdir -p bin-int

clean:
	rm -f $(OBJS) $(EXEC)
	rmdir $(BININT)
