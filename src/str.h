#ifndef STR_H
#define STR_H

#include <stddef.h>

#include "arena.h"

struct String {
  size_t length;
  char *buffer;
};

struct String *string_new(struct Arena *arena, const char *raw_string);
char string_at(struct String *string, size_t index);
#endif
