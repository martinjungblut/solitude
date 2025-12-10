#include <stdlib.h>

void release_resource(int *p) {
  // first free
  free(p);
}

void process_and_release(int *p) {
  // do something with the memory
  *p = 42;

  // first free
  release_resource(p);
}

void final_cleanup(int *p) {
  // second free
  free(p);
}

int main(void) {
  int *p = malloc(sizeof *p);
  if (!p) {
    return 1;
  }

  process_and_release(p); // first free
  final_cleanup(p);       // second free

  return 0;
}
