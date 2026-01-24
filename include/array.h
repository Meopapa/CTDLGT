#ifndef ARRAY_H
#define ARRAY_H

#include "include\data_structure.h"

#define TENSOR_DECLARE_INIT(type, dimension) \
    void TENSOR_Initialize(Tensor_##type##_##dimension *t, int r, int c, int d); \
    void TENSOR_Free(Tensor_##type##_##dimension *t); 
#define TENSOR_DECLARE_LOCATE(type, dimension) \
    void TENSOR_Locate(Tensor_##type##_##dimension *t, int r, int c, int d); \
    void TENSOR_transpose(Tensor_##type##_##dimension *t, int nr, int nc, int nd);
#define TENSOR_DECLARE_TRANSPOSE(type, dimension) \
    void TENSOR_transpose(Tensor_##type##_##dimension *src, Tensor_##type##_##dimension *dst);
#endif