#include <stdio.h>
#include <stdlib.h>

char *create_command(size_t size) {
  char *str;
  str = calloc(size, sizeof(char));
  return str;
}

char **create_commands(int n) {
  char **ptrs;
  ptrs = calloc((size_t)n, sizeof(char *));
  return ptrs;
}

char *get_command(size_t size) {
  char *command = create_command(size);
  printf("> ");
  fgets(command, size, stdin);
  return command;
}

char **get_commands(int n, size_t size) {
  char **commands = create_commands(n);
  for (int i = 0; i < n; i++) {
    commands[i] = get_command(size);
  }
  return commands;
}

void print_commands(char **commands, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s", commands[i]);
  }
}

void free_commands(char **commands, int n) {
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
  char **commands = get_commands(n, size);
  print_commands(commands, n);
  free_commands(commands, n);
  return 0;
}
