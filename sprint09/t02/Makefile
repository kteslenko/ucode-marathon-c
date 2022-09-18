CC = clang
CFLAGS = -c -std=c11 -Wall -Wextra -Werror -Wpedantic
SOURCES = $(addprefix src/,mx_atoi.c mx_isspace.c mx_printint.c mx_strcmp.c mx_strlen.c mx_isdigit.c mx_printchar.c mx_printstr.c mx_strcpy.c)
OBJECTS = mx_atoi.o mx_isspace.o mx_printint.o mx_strcmp.o mx_strlen.o mx_isdigit.o mx_printchar.o mx_printstr.o mx_strcpy.o

all: MINILIBMX

MINILIBMX: inc/header.h $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)
	mkdir -p obj
	mv $(OBJECTS) obj
	ar rsc minilibmx.a $(addprefix obj/,$(OBJECTS))

uninstall:
	rm -rf obj
	rm -f minilibmx.a

clean:
	rm -rf $(addprefix obj/,$(OBJECTS))

reinstall: uninstall all
