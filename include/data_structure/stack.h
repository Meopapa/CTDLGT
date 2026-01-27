#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure\data_structure.h"

#define STACK_DECLARE_INIT(type, number) \
    int STACK_Init_##type(Stack_##type##_##number *s);
#define STACK_DECLARE_CHECK(type, number) \
    int STACK_IsFull_##type(Stack_##type##_##number *s); \
    int STACK_IsEmpty_##type(Stack_##type##_##number *s);
#define STACK_DECLARE_ATC(type, number) \
    type STACK_Pop_##type(Stack_##type##_##number *s); \
    int STACK_Push_##type(Stack_##type##_##number *s, type n); \
    type STACK_Top_##type(Stack_##type##_##number *s);

#endif