#include <stdio.h>
int main() {
  int n = 30;

  for (int i = 0; i < n; i++)
    printf(" ");
  printf("*\n");

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      printf(" ");
    }
    printf("*");
    for (int j = 0; j < 2 * i - 1; j++) {
      printf(" ");
    }
    printf("*\n");
  }
  return 0;
}