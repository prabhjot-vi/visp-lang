#include <stdio.h>
#include <string.h>

#include "arena.h"
#include "str.h"

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
  struct Arena arena;
  arena_new(&arena, sizeof(size_t) * 100);

  struct String *expr = string_new(&arena, "(+ 2 3)");

  for (size_t index = 0; index < expr->length; ++index) {
    char ch = string_at(expr, index);

    printf("%c\n", ch);
  }
  
  arena_free(&arena);
  return 0;
}
