#include "include\data_structure\dsa_configs.h"
#include "include\data_structure\data_structure.h"
#include "include\data_structure\array.h"

#define TENSOR_IMPLEMENT_INIT(type, dimension) \
    int TENSOR_Initialize_##type(Tensor_##type##_##dimension *t, int r, int c, int d) \
    { \
        if(t == NULL) return ERROR_NULL_PTR; \
        t->row = r; \
        t->column = (dimension >= 2)? c : 1; \
        t->depth = (dimension >= 3)? d : 1; \
        t->data = (type*)malloc(t->row * t->column * t->depth * sizeof(type)); \
        if(t->data == NULL) return ERROR_MEMORY_ALLOC; \
        return SUCCESS_TRUE; \
    } \
    \
    int TENSOR_Free_##type(Tensor_##type##_##dimension *t) \
    { \
        if(t == NULL) return ERROR_NULL_PTR; \
        if(t->data) free(t->data); \
        t->data = NULL; \
        return SUCCESS_TRUE; \
    }
#define TENSOR_IMPLEMENT_LOCATE(type, dimension) \
    type* TENSOR_Locate_##type(Tensor_##type##_##dimension *t, int r, int c, int d) \
    { \
        if(t == NULL) return NULL; \
        int index = r * (t->column * t->depth) + c * (t->depth) + d; \
        return &(t->data[index]); \
    } \
    int TENSOR_reshape_##type(Tensor_##type##_##dimension *t, int new_r, int new_c, int new_d) \
    { \
        if(t == NULL) return ERROR_NULL_PTR; \
        if ((new_r * new_c * new_d) == (t->row * t->column * t->depth)) \
        { \
        t->row = new_r; \
        t->column = new_c; \
        t->depth = new_d; \
        return SUCCESS_TRUE; \
        } \
        else return ERROR_SIZE; \
    }
#define TENSOR_IMPLEMENT_TRANSPOSE(type, dimension) \
    int TENSOR_transpose_##type(Tensor_##type##_##dimension *src, Tensor_##type##_##dimension *dst) \
    { \
        if(src == NULL || dst == NULL) return ERROR_NULL_PTR; \
        TENSOR_Initialize_##type(dst, src->column, src->row, src->depth); \
        \
        for (int r = 0; r < src->row; r++) \
        { \
            for (int c = 0; c < src->column; c++) \
            { \
                for (int d = 0; d < src->depth; d++) \
                { \
                    type val = *TENSOR_Locate_##type(src, r, c, d); \
                    *TENSOR_Locate_##type(dst, c, r, d) = val; \
                } \
            } \
        } \
        return SUCCESS_TRUE; \
    }
