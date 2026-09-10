#include <stddef.h>

#include "data_structure/heap.h"

#define HEAP_IMPLEMENT(type, number) \
    int HEAP_Init_##type(Heap_##type##_##number *heap) \
    { \
        if (heap == NULL) return ERROR_NULL_PTR; \
        heap->size = 0; \
        return SUCCESS_TRUE; \
    } \
    int HEAP_Push_##type(Heap_##type##_##number *heap, type value) \
    { \
        int index; \
        type temporary; \
        if (heap == NULL) return ERROR_NULL_PTR; \
        if (heap->size >= number) return ERROR_SIZE; \
        index = heap->size++; \
        heap->data[index] = value; \
        while (index > 0 && heap->data[(index - 1) / 2] > heap->data[index]) \
        { \
            temporary = heap->data[index]; \
            heap->data[index] = heap->data[(index - 1) / 2]; \
            heap->data[(index - 1) / 2] = temporary; \
            index = (index - 1) / 2; \
        } \
        return SUCCESS_TRUE; \
    } \
    int HEAP_Peek_##type(const Heap_##type##_##number *heap, type *value) \
    { \
        if (heap == NULL || value == NULL) return ERROR_NULL_PTR; \
        if (heap->size == 0) return ERROR_EMPTY; \
        *value = heap->data[0]; \
        return SUCCESS_TRUE; \
    } \
    int HEAP_Pop_##type(Heap_##type##_##number *heap, type *value) \
    { \
        int index; \
        int child; \
        type temporary; \
        if (heap == NULL || value == NULL) return ERROR_NULL_PTR; \
        if (heap->size == 0) return ERROR_EMPTY; \
        *value = heap->data[0]; \
        heap->size--; \
        if (heap->size == 0) return SUCCESS_TRUE; \
        heap->data[0] = heap->data[heap->size]; \
        index = 0; \
        while (index * 2 + 1 < heap->size) \
        { \
            child = index * 2 + 1; \
            if (child + 1 < heap->size && heap->data[child + 1] < heap->data[child]) child++; \
            if (heap->data[index] <= heap->data[child]) break; \
            temporary = heap->data[index]; \
            heap->data[index] = heap->data[child]; \
            heap->data[child] = temporary; \
            index = child; \
        } \
        return SUCCESS_TRUE; \
    } \
    int HEAP_IsEmpty_##type(const Heap_##type##_##number *heap) \
    { \
        if (heap == NULL) return ERROR_NULL_PTR; \
        return heap->size == 0 ? SUCCESS_TRUE : FAIL_FALSE; \
    } \
    int HEAP_Size_##type(const Heap_##type##_##number *heap) \
    { \
        if (heap == NULL) return ERROR_NULL_PTR; \
        return heap->size; \
    }

HEAP_STRUCT(int, 16)
HEAP_DECLARE(int, 16)
HEAP_IMPLEMENT(int, 16)
#include "data_structure/heap.h"

#define HEAP_IMPLEMENT_INIT(type) \
    int HEAP_init_##type() \
    { \
         \
    } \
    int HEAP_free_##type(); 
#define HEAP_IMPLEMENT_CORE(type) \
    int HEAP_ShiftUp_##type(); \
    int HEAP_ShiftDown_##type();
#define HEAP_IMPLEMENT_ACT(type) \
    int HEAP_Push_##type(); \
    type HEAP_Pop_##type(); \
    int HEAP_IsEmpty_##type(); \
    int HEAP_Size_##type();

#define HEAP_IMPLEMENTATION_END 1