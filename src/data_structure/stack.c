#include "data_structure/dsa_configs.h"
#include "data_structure/data_structure.h"
#include "data_structure/stack.h"

#define STACK_IMPLEMENT_INIT(type, number) \
    int STACK_Init_##type(Stack_##type##_##number *s) \
    { \
        if (s == NULL) return ERROR_NULL_PTR; \
        s->top = -1; \
        return SUCCESS_TRUE; \
    }

#define STACK_IMPLEMENT_CHECK(type, number) \
    int STACK_IsFull_##type(Stack_##type##_##number *s) \
    { \
        if (s == NULL) return ERROR_NULL_PTR; \
        return (s->top >= number - 1) ? SUCCESS_TRUE : FAIL_FALSE; \
    } \
    int STACK_IsEmpty_##type(Stack_##type##_##number *s) \
    { \
        if (s == NULL) return ERROR_NULL_PTR; \
        return (s->top < 0) ? SUCCESS_TRUE : FAIL_FALSE; \
    }

#define STACK_IMPLEMENT_ACT(type, number) \
    type STACK_Pop_##type(Stack_##type##_##number *s) \
    { \
        type pop; \
        if (s == NULL) return (type)ERROR_NULL_PTR; \
        if (STACK_IsEmpty_##type(s)) return (type)ERROR_INDEX; \
        pop = s->data[s->top]; \
        s->top--; \
        return pop; \
    } \
    int STACK_Push_##type(Stack_##type##_##number *s, type n) \
    { \
        if (s == NULL) return ERROR_NULL_PTR; \
        if (STACK_IsFull_##type(s)) return ERROR_INDEX; \
        s->data[++s->top] = n; \
        return SUCCESS_TRUE; \
    } \
    type STACK_Top_##type(Stack_##type##_##number *s) \
    { \
        if (s == NULL) return (type)ERROR_NULL_PTR; \
        if (STACK_IsEmpty_##type(s)) return (type)ERROR_INDEX; \
        return s->data[s->top]; \
    }

#define STACK_IMPLEMENTATION_END 1

STACK_STRUCT(int, 8)
STACK_DECLARE_INIT(int, 8)
STACK_DECLARE_CHECK(int, 8)
STACK_DECLARE_ATC(int, 8)
STACK_IMPLEMENT_INIT(int, 8)
STACK_IMPLEMENT_CHECK(int, 8)
STACK_IMPLEMENT_ACT(int, 8)
