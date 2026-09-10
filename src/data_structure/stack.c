#include "include\data_structure\data_structure.h"
#include "include\data_structure\dsa_configs.h"
#include "include\data_structure\stack.h"

#define STACK_IMPLEMENT_INIT(type, number) \
    int STACK_Init_##type(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        s->top = -1; \
    }
#define STACK_IMPLEMENT_CHECK(type, number) \
    int STACK_IsFull_##type(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        return (s->top >= number - 1)? SUCCESS_TRUE : FAIL_FALSE; \
    } \
    int STACK_IsEmpty_##type(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        return (!(s->top))? SUCCESS_TRUE : FAIL_FALSE; \
    }
#define STACK_IMPLEMENT_ATC(type, number) \
    type STACK_Pop_##type(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return (type)ERROR_NULL_PTR; \
        if(STACK_IsEmpty_##type(s)) return (type)ERROR_INDEX; \
        type pop = s->data[s->top]; \
        s->top = s->top - 1; \
        return pop; \
    } \
    int STACK_Push_##type(Stack_##type##_##number *s, type n) \
    { \
        if(s == NULL) return ERROR_NULL_PTR; \
        if(STACK_IsFull_##type(s)) return (type)ERROR_INDEX; \
        s->top += 1; \
        s->data[s->top] = n; \
        return SUCCESS_TRUE; \
    } \
    type STACK_Top_##type(Stack_##type##_##number *s) \
    { \
        if(s == NULL) return (type)ERROR_NULL_PTR; \
        return s->data[s->top]; \
    }