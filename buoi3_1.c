#include<stdio.h>
#include "buoi3_1.h"

void initStack(Stack *s)
{
    s->size = 0;
}

void push(Stack *s, int val)
{
    if(s->size == 100) return;
    s->infor[s->size++] = val;
}

int pop(Stack *s)
{
    int val;
    if(!s->size) return 0;
    val = s->infor[s->size];
    s->size--;
    return val;
}

int peek(Stack *s)
{
    if(!s->size) return 0;
    return s->infor[s->size];
}

void display(Stack *s)
{
    for(int i = 0; i <= s->size; i++)
    {
        printf("%d\n", s->infor[i]);
    }
}
