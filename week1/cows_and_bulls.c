#include <stdio.h>

#define SIZE 4

int anotherGame(void) {
  char buffer[256];
  do {
    printf("Play again? (y/n): ");
    scanf("%s", buffer);
  } while (buffer[0] != 'y' && buffer[0] != 'n');
  return buffer[0] == 'y';
}

void readGuess(int *guess) {
  for (int i = 0; i < SIZE; i++) {
    do {
      scanf("%i", &guess[i]);
    } while (guess[i] < 1 || guess[i] > 9);
  }
}

int blackScore(int *guess, int *code) {
  int score = 0;
  for (int i = 0; i < SIZE; i++) {
    score += code[i] == guess[i];
  }
  return score;
}

int whiteScore(int *guess, int *code) {
  int score = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i != j && code[i] == guess[j]) {
        score++;
      }
    }
  }
  return score;
}

void printScore(int *guess, int *code) {
  printf("(%i, %i)\n", blackScore(guess, code), whiteScore(guess, code));
}

int main(void) {
  printf("-- COWS AND BELLS --\n");
  int codes[5][SIZE] = {
      {1, 8, 9, 2}, {2, 4, 6, 8}, {1, 9, 8, 3}, {7, 4, 2, 1}, {4, 6, 8, 9}};
  int guess[SIZE];
  for (int i = 0; i < sizeof(codes) / sizeof(codes[0]); i++) {
    printf("Game started\n");
    readGuess(guess);
    while (blackScore(guess, codes[i]) != SIZE) {
      printScore(guess, codes[i]);
      readGuess(guess);
    }
    printf("You have guessed correctly!\n");
    if (i < SIZE - 1 && !anotherGame()) {
      break;
    }
  }
  return 0;
}
