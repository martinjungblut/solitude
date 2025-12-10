CC=clang
CFLAGS_DEBUG=-g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fstack-protector-strong -fsanitize=address,leak
CFLAGS_RELEASE=-O0 -DNDEBUG -Wall -Wextra -fomit-frame-pointer -fno-stack-protector -U_FORTIFY_SOURCE

all: stack-buffer-overflow-debug stack-buffer-overflow-release

stack-buffer-overflow-debug: main.c
	$(CC) $(CFLAGS_DEBUG) main.c -o $@

stack-buffer-overflow-release: main.c
	$(CC) $(CFLAGS_RELEASE) main.c -o $@

build-debug: stack-buffer-overflow-debug
build-release: stack-buffer-overflow-release

clean:
	@rm -rf stack-buffer-overflow-debug stack-buffer-overflow-release *.txt

.PHONY: all build-debug build-release clean
