#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure\data_structure.h"
#include "include\data_structure\dsa_configs.h"

#define HEAP_DECLARE_INIT(type) \
    int HEAP_init_##type(); \
    int HEAP_free_##type(); 
#define HEAP_DECLARE_CORE(type) \
    int HEAP_ShiftUp_##type(); \
    int HEAP_ShiftDown_##type();
#define HEAP_DECLARE_ACT() \
    int HEAP_Push_##type(); \
    type HEAP_Pop_##type(); \
    int HEAP_IsEmpty_##type(); \
    int HEAP_Size_##type(); 

#endif