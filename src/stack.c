#include "include\data_structure.h"
#include "include\dsa_configs.h"
#include "include\stack.h"

#define STACK_DECLARE_INIT(type, number) \
    int STACK_Init(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        s->top = 0; \
    }
#define STACK_DECLARE_CHECK(type, number) \
    int STACK_IsFull(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        return (s->top >= number - 1)? SUCCESS_TRUE : FAIL_FALSE; \
    } \
    int STACK_IsEmpty(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        return (!(s->top))? SUCCESS_TRUE : FAIL_FALSE; \
    }
#define STACK_DECLARE_ATC(type, number) \
    type STACK_Pop(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return (type)ERROR_NULL_PTR; \
        if(STACK_IsEmpty(s)) return (type)ERROR_INDEX; \
        type pop = s->data[top]; \
        top = top - 1; \
        return pop; \
    } \
    int STACK_Push(Stack_##type##_##number *s, type n) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        if(STACK_IsFull(s)) return (type)ERROR_INDEX; \
        s->top =+ 1; \
        s->data[top] = n; \
        return SUCCESS_TRUE; \
    } \
    type STACK_Top(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return (type)ERROR_NULL_PTR; \
        return s->data[top]; \
    }