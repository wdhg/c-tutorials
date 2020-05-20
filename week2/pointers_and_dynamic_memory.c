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
  return command;
}

char **getCommands(int n, size_t size) {
  char **commands = createCommands(n);
  for (int i = 0; i < n; i++) {
    printf("> ");
    commands[i] = getCommand(size);
  }
  return commands;
}

void printCommands(char **commands, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s\n", *commands[i]);
  }
}

void freeCommands(char **commands, int n) {
  for (int i = 0; i < n; i++) {
    free(commands[i]);
  }
}

int main(int argc, char *argv[]) { return 0; }