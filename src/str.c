#include <stdio.h>
#include <string.h>

#include "str.h"
#include "arena.h"

struct String *string_new(struct Arena *arena, const char *raw_string) {
  if (arena == NULL || raw_string == NULL) {
    exit(1);
  }

  size_t raw_string_length = strlen(raw_string);
  
  struct String *string =
      arena_allocate(arena, sizeof(struct String) + raw_string_length);
  string->length = raw_string_length;
  string->buffer = (char *)(string + sizeof(struct String));
  strcpy(string->buffer, raw_string);

  return string;
}

char string_at(struct String *string, size_t index) {
  if (string == NULL) {
    exit(1);
  }

  if (index >= string->length) {
    printf("Out of bounds\n");
    exit(1);
  }

  return string->buffer[index];
}
