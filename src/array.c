#include "include\dsa_configs.h"
#include "include\data_structure.h"
#include "include\array.h"

#define TENSOR_IMPLEMENT_INIT(type, dimension) \
    int TENSOR_Initialize(Tensor_##type##_##dimension *t, int r, int c, int d) \
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
    int TENSOR_Free(Tensor_##type##_##dimension *t) \
    { \
        if(t == NULL) return ERROR_NULL_PTR; \
        if(t->data) free(t->data); \
        t->data = NULL; \
        return SUCCESS_TRUE; \
    }
#define TENSOR_IMPLEMENT_LOCATE(type, dimension) \
    type* TENSOR_Locate(Tensor_##type##_##dimension *t, int r, int c, int d) \
    { \
        if(t == NULL) return NULL; \
        int index = r * (t->cols * t->depth) + c * (t->depth) + d; \
        return &(t->data[index]); \
    } \
    int TENSOR_transpose(Tensor_##type##_##dimension *t, int nr, int nc, int nd) \
    { \
        if(t == NULL) return ERROR_NULL_PTR; \
        if ((new_r * new_c * new_d) == (t->rows * t->cols * t->depth)) \
        { \
        t->rows = new_r; \
        t->cols = new_c; \
        t->depth = new_d; \
        return SUCCESS_TRUE; \
        } \
        else return ERROR_SIZE; \
    }
#define TENSOR_IMPLEMENT_TRANSPOSE(type, dimension) \
    int TENSOR_transpose(Tensor_##type##_##dimension *src, Tensor_##type##_##dimension *dst) \
    { \
        if(src == NULL || dst == NULL) return ERROR_NULL_PTR; \
        TENSOR_Initialize(dst, src->cols, src->rows, src->depth); \
        \
        for (int r = 0; r < src->rows; r++) \
        { \
            for (int c = 0; c < src->cols; c++) \
            { \
                for (int d = 0; d < src->depth; d++) \
                { \
                    type val = *TENSOR_Locate(src, r, c, d); \
                    *TENSOR_Locate(dst, c, r, d) = val; \
                } \
            } \
        } \
        return SUCCESS_TRUE; \
    }
