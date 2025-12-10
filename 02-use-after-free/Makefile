CC=clang
CFLAGS_DEBUG=-g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fstack-protector-strong -fsanitize=address,leak
CFLAGS_RELEASE=-O2 -DNDEBUG -Wall -Wextra -fomit-frame-pointer -fno-stack-protector -U_FORTIFY_SOURCE

all: use-after-free-debug use-after-free-release

use-after-free-debug: main.c
	$(CC) $(CFLAGS_DEBUG) main.c -o $@

use-after-free-release: main.c
	$(CC) $(CFLAGS_RELEASE) main.c -o $@

build-debug: use-after-free-debug
build-release: use-after-free-release

clean:
	@rm -rf use-after-free-debug use-after-free-release *.txt

.PHONY: all build-debug build-release clean
