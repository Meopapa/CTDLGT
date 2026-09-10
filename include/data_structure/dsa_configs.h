#ifndef DSA_CONFIGS_H
#define DSA_CONFIGS_H

typedef enum {
    SUCCESS_TRUE = 1,
    FAIL_FALSE = 0,
    ERROR_NULL_PTR = -1,
    ERROR_MEMORY_ALLOC = -2,
    ERROR_EMPTY = -3,
    ERROR_SIZE = -4,
    ERROR_INDEX = -5
} Status;

#endif