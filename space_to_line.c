#include <stdio.h>

int main(void) {

    int true = 1;
  while(true){
      char holder = getchar();
    switch(holder){
        case ' ':
            putchar('\n');
            break;
        case '.':
            true = 0;
            break;
        default:
            putchar(holder);
            break;

    }
  }            putchar('\n');
  return 0;
}