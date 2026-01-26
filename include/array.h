#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure.h"

#define TENSOR_DECLARE_INIT(type, dimension) \
    int TENSOR_Initialize_##type(Tensor_##type##_##dimension *t, int r, int c, int d); \
    int TENSOR_Free_##type(Tensor_##type##_##dimension *t); 
#define TENSOR_DECLARE_LOCATE(type, dimension) \
    type* TENSOR_Locate_##type(Tensor_##type##_##dimension *t, int r, int c, int d); \
    int TENSOR_reshape_##type(Tensor_##type##_##dimension *t, int nr, int nc, int nd);
#define TENSOR_DECLARE_TRANSPOSE(type, dimension) \
    int TENSOR_transpose_##type(Tensor_##type##_##dimension *src, Tensor_##type##_##dimension *dst);
#endif