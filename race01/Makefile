CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
OUT = part_of_the_matrix

all: $(OUT)

$(OUT): src/*.c
	$(CC) $(CFLAGS) -o $@ $^

uninstall:
	rm -f $(OUT)

clean:

reinstall: uninstall all
