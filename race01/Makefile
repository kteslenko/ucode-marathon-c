CC = clang
CFLAGS = -c -std=c11 -Wall -Wextra -Werror -Wpedantic
OUT = part_of_the_matrix
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=obj/%.o)

all: $(OUT)

$(OUT): $(OBJECTS)
	$(CC) -o $@ $^

obj/utils.o obj/number.o obj/mx_strtrim.o obj/mx_strdup.o obj/mx_printstr.o obj/mx_printlong.o obj/mx_printerr.o obj/mx_atoi.o obj/main.o: inc/header.h

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -o $@ $<

obj:
	mkdir -p $@

uninstall:
	rm -rf obj
	rm -f $(OUT)

clean:
	rm -f $(OBJECTS)

reinstall: uninstall all
