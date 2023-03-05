#include <cstddef>
#include <cstring>

// 定义内存块的头部结构体
struct block_header {
    size_t size;  // 内存块大小
    bool free;    // 是否空闲
};

// 定义内存对齐的大小
const size_t ALIGNMENT = 8;

// 辅助函数，对齐指定的地址
static inline size_t align(size_t size) {
    return (size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
}

// 内存块大小的最小值
const size_t MIN_BLOCK_SIZE = align(sizeof(block_header));

// 定义内存池的大小
const size_t POOL_SIZE = 1024 * 1024;  // 1MB

// 内存池起始地址
static char pool[POOL_SIZE];

// 内存池的末尾地址
static char* pool_end = pool + POOL_SIZE;

// 当前空闲内存块链表的头节点指针
static block_header* free_list = nullptr;

// 初始化空闲内存块链表
void init_free_list() {
    free_list = reinterpret_cast<block_header*>(pool);
    free_list->size = POOL_SIZE - MIN_BLOCK_SIZE;
    free_list->free = true;
    free_list->next = nullptr;
}

// 划分内存块
void split_block(block_header* block, size_t size) {
    size_t new_size = block->size - size - MIN_BLOCK_SIZE;
    block_header* new_block = reinterpret_cast<block_header*>(reinterpret_cast<char*>(block) + size + MIN_BLOCK_SIZE);
    new_block->size = new_size;
    new_block->free = true;
    new_block->next = block->next;
    block->size = size;
    block->free = false;
    block->next = new_block;
}

// 合并空闲内存块
void merge_blocks(block_header* prev, block_header* curr) {
    prev->size += curr->size + MIN_BLOCK_SIZE;
    prev->next = curr->next;
}

// 分配内存
void* my_malloc(size_t size) {
    // 将申请的内存大小加上头部结构体大小并对齐
    size = align(size + sizeof(block_header));

    block_header* prev = nullptr;
    block_header* curr = free_list;

    while (curr != nullptr) {
        if (curr->size >= size) {
            if (curr->size >= size + MIN_BLOCK_SIZE) {
                split_block(curr, size);
            }
            if (prev != nullptr) {
                prev->next = curr->next;
            } else {
                free_list = curr->next;
            }
            curr->free = false;
            return reinterpret_cast<void*>(curr + 1);
        }
        prev = curr;
        curr = curr->next;
    }

    // 没有合适的空闲内存块，返回空指针
    return nullptr;
}

// 释放内存
void my_free(void* ptr) {
    if (ptr
