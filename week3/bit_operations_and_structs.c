#include <stdint.h>
#include <stdio.h>

#define N 1288243249

void printBits(uint32_t x) {
  int i;
  uint32_t mask = 1 << 31;
  for (i = 0; i < 32; ++i) {
    if (i == 16)
      printf(" ");
    printf(x & mask ? "1" : "0");
    x = x << 1;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  printBits(N);
  return 0;
}
