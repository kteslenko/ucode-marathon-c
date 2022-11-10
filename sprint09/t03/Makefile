CC = clang
CFLAGS = -c -std=c11 -Wall -Wextra -Werror -Wpedantic
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=obj/%.o)

all: MINILIBMX

MINILIBMX: $(OBJECTS)
	ar rsc minilibmx.a $^

obj/mx_atoi.o obj/mx_printint.o: inc/header.h

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -o $@ $<

obj:
	mkdir -p $@

uninstall:
	rm -rf obj
	rm -f minilibmx.a

clean:
	rm -rf $(OBJECTS)

reinstall: uninstall all
