#ifndef BUOI3_1_H
#define BUOI3_1_H

#include<stdio.h>

#define MAX 100

typedef struct
{
    int infor[MAX];
    int size;
}Stack;

void initStack(Stack *s);
void push(Stack *s, int val);
void pop(Stack *s);
void pop_get_value(Stack *s, int *val);
int peek(Stack *s);
void display(Stack *s);

#endif