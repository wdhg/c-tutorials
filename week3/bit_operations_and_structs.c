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

void printBits16(uint16_t x) {
  uint16_t mask = 1 << 15;
  for (int i = 0; i < 16; ++i) {
    printf(x & mask ? "1" : "0");
    mask = mask >> 1;
  }
}

void splitBits(uint32_t x, uint16_t *first, uint16_t *second) {
  *first = x >> 16;
  *second = 0x0000ffff & x;
}

int main(int argc, char *argv[]) {
  printBits(N);
  uint16_t first, second;
  splitBits(N, &first, &second);
  printBits16(first);
  printf(" ");
  printBits16(second);
  printf("\n");
  printBits((((uint32_t)first) << 16) | second);
  return 0;
}
