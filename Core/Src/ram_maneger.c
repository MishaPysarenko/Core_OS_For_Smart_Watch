#include "ram_maneger.h"

void heapInit(){
	firstBlock = (BlockHeader*)heap; //преобразування вказівника <(на що)із чого>
	firstBlock->size = HEAP_SIZE - sizeof(BlockHeader);
	firstBlock->free = true;
	firstBlock->next = nullptr;
	isHeapInit = true;
}

void* malloc(size_t size){
	if(isHeapInit){
	    BlockHeader* current = firstBlock;
	    while (current) {
	        if (current->free && current->size >= size) {
	            // Якщо блок більший ніж потрібно — ділимо його
	            if (current->size > size + sizeof(BlockHeader)) {
	                BlockHeader* newBlock = (BlockHeader*)((uint_8*)(current + 1) + size);
	                newBlock->size = current->size - size - sizeof(BlockHeader);
	                newBlock->free = true;
	                newBlock->next = current->next;

	                current->size = size;
	                current->next = newBlock;
	            }

	            current->free = false;
	            return (void*)(current + 1);
	        }
	        current = current->next;
	    }
	    return nullptr;
	}
	else{
		ERRORS |= not_memory_init;
	}
	return nullptr;
}

void free(void* ptr){
	if(isHeapInit){
	    if (ptr == nullptr) return;

	    BlockHeader* block = (BlockHeader*)(ptr - 1);
	    block->free = true;

	    // Об'єднання суміжних вільних блоків
	    BlockHeader* current = firstBlock;
	    while (current) {
	        if (current->free && current->next && current->next->free) {
	            current->size += sizeof(BlockHeader) + current->next->size;
	            current->next = current->next->next;
	        } else {
	            current = current->next;
	        }
	    }
	}
	else{
		ERRORS |= not_memory_init;
	}
	return;
}

void* calloc(size_t count, size_t size){
	if(isHeapInit){
	    size_t totalSize = count * size;
	    void* ptr = malloc(totalSize);
	    if (ptr) {
	        // Занулення вручну
	    	uint_8* p = (uint_8*)(ptr);
	        for (size_t i = 0; i < totalSize; i++) {
	            p[i] = 0;
	        }
	    }
	    return ptr;
	}
	else{
		ERRORS |= not_memory_init;
	}
	return nullptr;
}

void* realloc(void* ptr, size_t new_size){
	if(isHeapInit){
	    if (ptr == nullptr) return malloc(new_size);
	    if (new_size == 0) { free(ptr); return nullptr; }

	    BlockHeader* block = (BlockHeader*)(ptr - 1);
	    if (block->size >= new_size) return ptr; // достатньо місця

	    void* newPtr = malloc(new_size);
	    if (newPtr) {
	        // Копіювання вручну
	    	uint_8* src = (uint_8*)(ptr);
	    	uint_8* dst = (uint_8*)(newPtr);
	        for (size_t i = 0; i < block->size; i++) {
	            dst[i] = src[i];
	        }
	        free(ptr);
	    }
	    return newPtr;
	}
	else{
		ERRORS |= not_memory_init;
	}
	return nullptr;
}
