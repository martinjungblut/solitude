void crash_here() {
  // volatile is needed as this code is optimised away if we use good
  // enough compiler flags
  volatile char *ptr = (char *)(0xDEADBEEF);
  char c = *ptr;
  (void)c;
}

int main() {
  crash_here();
}
