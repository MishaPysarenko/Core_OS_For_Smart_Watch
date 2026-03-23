#ifndef INC_RAM_MANEGER_H_
#define INC_RAM_MANEGER_H_

typedef unsigned long long size_t;

void* malloc(size_t size);

void free(void* ptr);

void* calloc(size_t count, size_t size);

void* realloc(void* ptr, size_t new_size);

#endif /* INC_RAM_MANEGER_H_ */
