CC=clang
#CFLAGS_DEBUG=-g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fstack-protector-strong -fsanitize=address,leak
CFLAGS_DEBUG=-g3 -O0 -Wall -Wextra -fno-omit-frame-pointer -fstack-protector-strong
CFLAGS_RELEASE=-O0 -DNDEBUG -Wall -Wextra -fomit-frame-pointer -fno-stack-protector -U_FORTIFY_SOURCE

all: double-free-debug double-free-release

double-free-debug: main.c
	$(CC) $(CFLAGS_DEBUG) main.c -o $@

double-free-release: main.c
	$(CC) $(CFLAGS_RELEASE) main.c -o $@

build-debug: double-free-debug
build-release: double-free-release

clean:
	@rm -rf double-free-debug double-free-release *.txt

.PHONY: all build-debug build-release clean
