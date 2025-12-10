#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 10

static void greet_user(const char *input) {
  int authenticated = 0;
  char name_buf[MAX_NAME];

  // intentionally dangerous: no bounds checking
  // bug: if input is longer than max_name - 1, we overflow name_buf
  // and start corrupting 'authenticated', and then the stack frame
  strcpy(name_buf, input);

  printf("hello, %s!\n", name_buf);

  if (authenticated) {
    printf("you are authenticated. this means the 'authenticated' variable has been corrupted.\n");
  } else {
    printf("access denied. the 'authenticated' variable has NOT been corrupted.\n");
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  greet_user(argv[1]);
  return EXIT_SUCCESS;
}
