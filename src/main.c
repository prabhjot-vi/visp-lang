#include "arena.h"

#include <stdio.h>
#include <string.h>

enum TOKEN {
  TOKEN_NUMBER,

  TOKEN_LPAREN,
  TOKEN_RPAREN,

  TOKEN_ADD,
  TOKEN_SUB,
  TOKEN_MUL,
  TOKEN_DIV,

  TOKEN_PRINT
};

int main() {

  /* char *expr = "(+ 2 3)"; */

  struct Arena a;
  arena_new(&a, sizeof(char) * 10);

  char *h = arena_allocate(&a, sizeof(char) * 2);
  memcpy(h, "Hi", sizeof(char) * 2);

  printf("%s\n", h);

  arena_free(&a);
  
  return 0;
}
