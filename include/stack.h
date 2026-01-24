#ifndef STACK_H
#define STACK_H

#include "include\data_structure.h"

#define STACK_DECLARE_INIT(type, number) \
    int STACK_Init(Stack_##type##_##number *s);
#define STACK_DECLARE_CHECK(type, number) \
    int STACK_IsFull(Stack_##type##_##number *s); \
    int STACK_IsEmpty(Stack_##type##_##number *s);
#define STACK_DECLARE_ATC(type, number) \
    type STACK_Pop(Stack_##type##_##number *s); \
    int STACK_Push(Stack_##type##_##number *s, type n); \
    type STACK_Top(Stack_##type##_##number *s);

#endif