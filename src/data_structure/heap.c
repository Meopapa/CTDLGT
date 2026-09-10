#include "include\data_structure\heap.h"

#define HEAP_IMPLEMENT_INIT(type) \
    int HEAP_init_##type() \
    { \
         \
    } \
    int HEAP_free_##type(); 
#define HEAP_IMPLEMENT_CORE(type) \
    int HEAP_ShiftUp_##type(); \
    int HEAP_ShiftDown_##type();
#define HEAP_IMPLEMENT_ACT() \
    int HEAP_Push_##type(); \
    type HEAP_Pop_##type(); \
    int HEAP_IsEmpty_##type(); \
    int HEAP_Size_##type(); 