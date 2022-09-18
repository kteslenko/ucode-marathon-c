CC = clang
CFLAGS = -c -std=c11 -Wall -Wextra -Werror -Wpedantic
OBJDIR = obj
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=$(OBJDIR)/%.o)

all: MINILIBMX

MINILIBMX: $(OBJECTS)
	ar rsc minilibmx.a $^

$(OBJDIR)/mx_atoi.o $(OBJDIR)/mx_printint.o: inc/header.h

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR):
	mkdir -p $@

uninstall:
	rm -rf $(OBJDIR)
	rm -f minilibmx.a

clean:
	rm -rf $(OBJDIR)

reinstall: uninstall all
