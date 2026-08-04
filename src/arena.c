#include <stdio.h>
#include <string.h>

#include "arena.h"

void arena_new(struct Arena *arena, size_t size) {
  if (arena == NULL) {
    exit(1);
  }

  arena->size = size;
  arena->offset = 0;
  arena->buffer = (uint8_t *)malloc(sizeof(uint8_t) * size);
  if (arena->buffer == NULL) {
    exit(1);
  }
}

void *arena_allocate(struct Arena *arena, size_t request_size) {
  if (arena == NULL) {
    exit(1);
  }

  if (request_size > (arena->size - arena->offset)) {
    exit(1);
  }

  void *ptr = (void *)(arena->buffer + arena->offset);
  arena->offset += request_size;
  return ptr;
}

void arena_reset(struct Arena *arena) {
  if (arena == NULL) {
    exit(1);
  }

  arena->offset = 0;
}

void arena_free(struct Arena *arena) {
  if (arena == NULL || arena->buffer == NULL) {
    return;
  }
  free(arena->buffer);
}
