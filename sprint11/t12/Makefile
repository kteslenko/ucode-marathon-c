CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
OUT = playlist

all: $(OUT)

$(OUT): src/*.c
	$(CC) $(CFLAGS) -o $@ $^

uninstall:
	rm -f $(OUT)

clean:

reinstall: uninstall all
