#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int sum_array(const int *arr, size_t n) {
  int sum = 0;

  for (size_t i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}

int main(void) {
  const size_t n = 4;

  int *numbers = malloc(n * sizeof(int));
  if (!numbers) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < n; i++) {
    // [1, 2, 3, 4]
    numbers[i] = i + 1;
  }

  // free the memory
  free(numbers);

  // keep using the dangling pointer
  // this is the classic heap use-after-free
  // normally, the result would be 10 (1 + 2 + 3 + 4)
  int result = sum_array(numbers, n);

  // using `result` in I/O makes this access "observable",
  // so it won't be optimised away by the compiler
  printf("sum is %d\n", result);

  return 0;
}
