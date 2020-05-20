#include <stdio.h>

char *createCommand(size_t size) {
  char *str;
  str = (char *)calloc(size);
  return str;
}

char **createCommands(int n) {
  char **ptrs;
  ptrs = (char **)calloc((size_t)sizeof(char *) * n);
  ptrs = (char **)
}

char *getCommand(size_t size) {
  char *command = createCommand(size);
  printf("> ");
  fgets(command, size, stdin);
}

int main(int argc, char *argv[]) { return 0; }
