#include <stdlib.h>

#include "data_structure/dsa_configs.h"
#include "data_structure/data_structure.h"
#include "data_structure/list.h"

#define LIST_IMPLEMENT(type1, type2, type3) \
    int LIST_Init_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head) \
    { \
        if (head == NULL) return ERROR_NULL_PTR; \
        *head = NULL; \
        return SUCCESS_TRUE; \
    } \
    int LIST_Free_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head) \
    { \
        List_##type1##_##type2##_##type3 *node; \
        if (head == NULL) return ERROR_NULL_PTR; \
        while (*head != NULL) \
        { \
            node = *head; \
            *head = node->next_ptr; \
            free(node); \
        } \
        return SUCCESS_TRUE; \
    } \
    int LIST_InsertFront_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head, List_##type1##_##type2##_##type3 *node) \
    { \
        if (head == NULL || node == NULL) return ERROR_NULL_PTR; \
        node->pre_ptr = NULL; \
        node->next_ptr = *head; \
        if (*head != NULL) (*head)->pre_ptr = node; \
        *head = node; \
        return SUCCESS_TRUE; \
    } \
    int LIST_InsertBack_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head, List_##type1##_##type2##_##type3 *node) \
    { \
        List_##type1##_##type2##_##type3 *tail; \
        if (head == NULL || node == NULL) return ERROR_NULL_PTR; \
        if (*head == NULL) return LIST_InsertFront_##type1##_##type2##_##type3(head, node); \
        tail = *head; \
        while (tail->next_ptr != NULL) tail = tail->next_ptr; \
        node->next_ptr = NULL; \
        node->pre_ptr = tail; \
        tail->next_ptr = node; \
        return SUCCESS_TRUE; \
    } \
    int LIST_DeleteFront_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head) \
    { \
        List_##type1##_##type2##_##type3 *node; \
        if (head == NULL) return ERROR_NULL_PTR; \
        if (*head == NULL) return ERROR_EMPTY; \
        node = *head; \
        *head = node->next_ptr; \
        if (*head != NULL) (*head)->pre_ptr = NULL; \
        free(node); \
        return SUCCESS_TRUE; \
    } \
    int LIST_DeleteBack_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 **head) \
    { \
        List_##type1##_##type2##_##type3 *tail; \
        if (head == NULL) return ERROR_NULL_PTR; \
        if (*head == NULL) return ERROR_EMPTY; \
        tail = *head; \
        while (tail->next_ptr != NULL) tail = tail->next_ptr; \
        if (tail->pre_ptr != NULL) tail->pre_ptr->next_ptr = NULL; \
        else *head = NULL; \
        free(tail); \
        return SUCCESS_TRUE; \
    } \
    int LIST_Size_##type1##_##type2##_##type3(List_##type1##_##type2##_##type3 *head) \
    { \
        int size = 0; \
        while (head != NULL) \
        { \
            size++; \
            head = head->next_ptr; \
        } \
        return size; \
    }

LIST_STRUCT(int, int, int)
LIST_DECLARE(int, int, int)
LIST_IMPLEMENT(int, int, int)
#include <stdio.h>
#include <stdlib.h>
#include "data_structure/dsa_configs.h"
#include "data_structure/data_structure.h"
#include "data_structure/list.h"

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
        while(L->next_ptr != NULL) L = L->next_ptr; \
        L->pre_ptr->next_ptr = NULL; \
        free(L); \
    } \
    int LIST_DeleteMiddle_##type1##_##type2##_##type3(type1 *m1, type2 *m2, type3 *m3);
#define LIST_IMPLEMENT_TRAVERSE(type1, type2, type3) \
    int LIST_Traverse_##type1##_##type2##_##type3();

#define LIST_IMPLEMENTATION_END 1