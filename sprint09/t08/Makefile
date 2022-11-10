CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
CALC = calc
HEADERS = $(wildcard inc/*.h)
SOURCES = $(wildcard src/*.c)

all: $(CALC)

$(CALC): $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

uninstall:
	rm -f $(CALC)

clean:

reinstall: uninstall all
