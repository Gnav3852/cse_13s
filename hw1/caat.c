#include <stdio.h>

int main(void) {
  char c;
  while ((c = getchar()) != EOF) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      putchar(c);
      putchar(c);
    } else {
      putchar(c);
    }
  }

  return 0;
}
