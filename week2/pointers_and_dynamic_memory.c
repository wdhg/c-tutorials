#include <stdio.h>
#include <stdlib.h>

char *createCommand(size_t size) {
  char *str;
  str = calloc(size, sizeof(char));
  return str;
}

char **createCommands(int n) {
  char **ptrs;
  ptrs = calloc((size_t)n, sizeof(char *));
  return ptrs;
}

char *getCommand(size_t size) {
  char *command = createCommand(size);
  printf("> ");
  fgets(command, size, stdin);
  return command;
}

char **getCommands(int n, size_t size) {
  char **commands = createCommands(n);
  for (int i = 0; i < n; i++) {
    commands[i] = getCommand(size);
  }
  return commands;
}

void printCommands(char **commands, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s", commands[i]);
  }
}

void freeCommands(char **commands, int n) {
  for (int i = 0; i < n; i++) {
    free(commands[i]);
  }
  free(commands);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    puts("Arguments: <number of commands> <max size of command>");
    return 1;
  }
  int n;
  size_t size;
  sscanf(argv[1], "%i", &n);
  sscanf(argv[2], "%lu", &size);
  if (n < 3) {
    puts("First argument must be greater than or equal to 3");
    return 1;
  }
  if (size < 50) {
    puts("Second argument must be greater than or equal to 50");
    return 1;
  }
  char **commands = getCommands(n, size);
  printCommands(commands, n);
  freeCommands(commands, n);
  return 0;
}
