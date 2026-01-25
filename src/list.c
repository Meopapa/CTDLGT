#include <stdio.h>
#include <stdlib.h>
#include "include\dsa_configs.h"
#include "include\data_structure.h"
#include "include\list.h"

#define LIST_IMPLEMENT_INIT(type1, type2, type3, head) \
    int LIST_Init_##type1##_##type2##_##type3() \
    { \
        head = NULL; \
    } \
    int LIST_Free_##type1##_##type2##_##type3() \
    { \
        List_##type1##_##type2##_##type3 *l; \
        while(head != NULL) \
        { \
            l = head; \
            head = head->next_ptr; \
            head->pre_ptr = NULL; \
            free(l); \
        } \
    } 
#define LIST_IMPLEMENT_INSERT(type1, type2, type3, head) \
    int LIST_InsertFront_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 *l) \
    { \
        if(l == NULL) return ERROR_NULL_PTR; \
        if(head == NULL) head = l; \
        else \
        { \
            head->pre_ptr = l; \
            l->next_ptr = head; \
            head = l; \
        } \
        return SUCCESS_TRUE; \
    } \
    int LIST_InsertBack_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 *l) \
    { \
        if(l == NULL) return ERROR_NULL_PTR; \
        if(head == NULL) return ERROR_EMPTY; \
        List_##type1##_##type2##_##type3 *L; \
        L = head; \
        while(L->next_ptr != NULL) L = L->next_ptr; \
        L->next_ptr = l; \
        l->pre_ptr = L; \
    } \
    int LIST_InsertMiddle_##type1##_##type2##_##type3(type1 *m1, type2 *m2, type3 *m3, List_##type1##_##type2##_##type3 *l_insert);
#define LIST_IMPLEMENT_DELETE(type1, type2, type3, head) \
    int LIST_DeleteFront_##type1##_##type2##_##type3() \
    { \
        List_##type1##_##type2##_##type3 *l; \
        l = head; \
        head = head->next_ptr; \
        free(l); \
        return SUCCESS_TRUE; \
    } \
    int LIST_DeleteBack_##type1##_##type2##_##type3() \
    { \
        List_##type1##_##type2##_##type3 *L; \
        while(L->next_ptr->next_ptr != NULL) L = L->next_ptr; \
        free(L->next_ptr); \
        L->next_ptr = NULL; \
    } \
    int LIST_DeleteMiddle_##type1##_##type2##_##type3(type1 *m1, type2 *m2, type3 *m3);
#define LIST_IMPLEMENT_TRAVERSE() \
    int LIST_Traverse_##type1##_##type2##_##type3(); \