#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

// Linear data structure
#define TENSOR_STRUCT(type, dimension) \
    typedef struct Tensor_##type##_##dimension \
    { \
        type *data; \
        int column, row, depth; \
    }Tensor_##type##_##dimension; \

#define STACK_STRUCT(type, number) \
    typedef struct Stack_##type##_##number \
    { \
        type data[number]; \
        int top; \
    }Stack_##type##_##number;

#define QUEUE_STRUCT(type, number) \
    typedef struct Queue_##type##_##number \
    { \
        type data[number]; \
        int front, rear, count; \
    }Queue_##type##_##number;

#define LIST_STRUCT(type1, type2, type3) \
    typedef struct List_##type1##_##type2##_##type3 \
    { \
        type1 data1; \
        type2 data2; \
        type3 data3; \
        struct List_##type1##_##type2##_##type3 *next_ptr; \
        struct List_##type1##_##type2##_##type3 *pre_ptr; \
    }List_##type1##_##type2##_##type3;

// Non-linear data structure
#define TREE_STRUCT(type) \
    typedef struct TreeNode_##type \
    { \
        type data; \
        struct BinaryTree_##type *left; \
        struct BinaryTree_##type *right; \
    }TreeNode_##type;

#endif