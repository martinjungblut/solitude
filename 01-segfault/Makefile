CC=clang
CFLAGS_DEBUG=-g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fstack-protector-strong
CFLAGS_RELEASE=-O2 -DNDEBUG -Wall -Wextra -fomit-frame-pointer -fno-stack-protector -U_FORTIFY_SOURCE

all: segfault-debug segfault-release

segfault-debug: main.c
	$(CC) $(CFLAGS_DEBUG) main.c -o $@

segfault-release: main.c
	$(CC) $(CFLAGS_RELEASE) main.c -o $@

build-debug: segfault-debug
build-release: segfault-release

clean:
	@rm -rf segfault-debug segfault-release *.txt

.PHONY: all build-debug build-release clean
