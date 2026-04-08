#ifndef INC_RAM_MANEGER_H_
#define INC_RAM_MANEGER_H_
#include "error.h"

#define nullptr ((void*)0)

typedef unsigned long long size_t;
typedef unsigned char uint_8;
typedef unsigned char bool;
#define true 1
#define false 0

//1 KB = 1024 Byte
#define HEAP_SIZE 1024 * 8 //налаштувати від обраного мікроконтролеру
static uint_8 heap[HEAP_SIZE];

struct BlockHeader;
typedef struct BlockHeader BlockHeader;

struct BlockHeader{ //структура блоку пам'яті
	size_t size;
	bool free;
	BlockHeader* next;
};

static BlockHeader* firstBlock = nullptr;

static bool isHeapInit = false;

void heapInit();

void* malloc(size_t size);

void free(void* ptr);

void* calloc(size_t count, size_t size);

void* realloc(void* ptr, size_t new_size);

#endif /* INC_RAM_MANEGER_H_ */
