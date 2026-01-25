#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "include\data_structure.h"

#define LIST_DECLARE_INIT(type1, type2, type3, head) \
    int LIST_Init_##type1##_##type2##_##type3(); \
    int LIST_Free_##type1##_##type2##_##type3(); 
#define LIST_DECLARE_INSERT(type1, type2, type3, head) \
    int LIST_InsertFront_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 *l); \
    int LIST_InsertBack_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 *l); \
    int LIST_InsertMiddle_##type1##_##type2##_##type3(type1 *m1, type2 *m2, type3 *m3, List_##type1##_##type2##_##type3 *l_insert);
#define LIST_DECLARE_DELETE(type1, type2, type3, head) \
    int LIST_DeleteFront_##type1##_##type2##_##type3(); \
    int LIST_DeleteBack_##type1##_##type2##_##type3(); \
    int LIST_DeleteMiddle_##type1##_##type2##_##type3(type1 *m1, type2 *m2, type3 *m3);
#define LIST_DECLARE_TRAVERSE() \
    int LIST_Traverse_##type1##_##type2##_##type3();

#endif 