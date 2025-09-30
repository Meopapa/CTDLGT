#include<stdio.h>
#include "buoi3_1.h"

void initStack(Stack *s)
{
    s->size = 0;
}

void push(Stack *s, int val)
{
    s->infor[s->size++] = val;
}

void pop(Stack *s)
{
    s->size--;
}

void pop_get_value(Stack *s, int *val)
{
    if (s->size > 0) {
        *val = s->infor[s->size - 1];
        s->size--;
    }
}

int peek(Stack *s)
{
    if(!s->size) return 0;
    return s->infor[s->size-1];
}

void display(Stack *s)
{
    for(int i = 0; i <= s->size; i++)
    {
        printf("%d\n", s->infor[i]);
    }
}
