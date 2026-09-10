#ifndef HEAP_H
#define HEAP_H

#include "data_structure/data_structure.h"
#include "data_structure/dsa_configs.h"

#define HEAP_DECLARE(type, number) \
    int HEAP_Init_##type(Heap_##type##_##number *heap); \
    int HEAP_Push_##type(Heap_##type##_##number *heap, type value); \
    int HEAP_Pop_##type(Heap_##type##_##number *heap, type *value); \
    int HEAP_Peek_##type(const Heap_##type##_##number *heap, type *value); \
    int HEAP_IsEmpty_##type(const Heap_##type##_##number *heap); \
    int HEAP_Size_##type(const Heap_##type##_##number *heap);

#endif
#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "data_structure/data_structure.h"
#include "data_structure/dsa_configs.h"

#define HEAP_DECLARE_INIT(type) \
    int HEAP_init_##type(); \
    int HEAP_free_##type(); 
#define HEAP_DECLARE_CORE(type) \
    int HEAP_ShiftUp_##type(); \
    int HEAP_ShiftDown_##type();
#define HEAP_DECLARE_ACT(type) \
    int HEAP_Push_##type(); \
    type HEAP_Pop_##type(); \
    int HEAP_IsEmpty_##type(); \
    int HEAP_Size_##type(); 

#endif