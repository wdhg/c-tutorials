#include <stdio.h>
#include <stdlib.h>

char *createCommand(size_t size) {
  char *str;
  str = (char *)calloc(size, sizeof(char));
  return str;
}

char **createCommands(int n) {
  char **ptrs;
  ptrs = (char **)calloc((size_t)n, sizeof(char *));
  return ptrs;
}

char *getCommand(size_t size) {
  char *command = createCommand(size);
  printf("> ");
  fgets(command, size, stdin);
}

int main(int argc, char *argv[]) { return 0; }
