#ifndef ARENA_H
#define ARENA_H

#include <stdint.h>
#include <stdlib.h>

struct Arena {
  size_t size;
  size_t offset;
  uint8_t* buffer;
};

void arena_new(struct Arena *arena, size_t size);
void *arena_allocate(struct Arena *arena, size_t request_size);

void arena_reset(struct Arena *arena);
#endif
