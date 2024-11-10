#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "./vector.h"

vector_t* vector_init(size_t elem_size, size_t capacity){
  assert(elem_size > 0);
  vector_t* vec = (vector_t*) malloc(sizeof(vector_t));
  
  if(vec == NULL)
    return NULL;

  if(capacity == 0)
    capacity = 8;
  
  vec->data = malloc(elem_size * capacity);

  if(!vec->data){
    free(vec);
    return NULL;
  }

  vec->length = 0;
  vec->elem_size = elem_size;
  vec->capacity = capacity;

  return vec;
}

void vector_free(vector_t* vec){
  assert(vec);
  free(vec->data);
  free(vec);
}

void push(vector_t* vec, void* elem){
  if(vec->length == vec->capacity){
    size_t temp = vec->capacity * 2;
    vec->data = realloc(vec->data, vec->elem_size * temp);
    if(!vec->data)
      return;
    vec->capacity *= 2;
  }
  memcpy(&vec->data[vec->length * vec->elem_size], elem, vec->elem_size);
  vec->length++;
}

void* pop(vector_t* vec){
  assert(vec);
  assert(vec->length > 0);
  vec->length--;
  return &vec->data[vec->length * vec->elem_size];
}

void clear(vector_t* vec){
  assert(vec);
  vec->length = 0;
}

void* get_element(vector_t* vec, size_t index){
  assert(vec);
  assert(index < vec->length);
  return &vec->data[index * vec->elem_size];
}

void set_element(vector_t* vec, size_t index, void* elem){
  assert(vec);
  assert(index < vec->length);
  
}
