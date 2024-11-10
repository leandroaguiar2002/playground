#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Vector{
 void* data;
 size_t capacity;
 size_t length;
 size_t elem_size; 
} vector_t;







#endif