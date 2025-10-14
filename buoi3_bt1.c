#include<stdio.h>
#include "buoi3_1.c"

int main()
{
    int value, du;
    Stack s;
    initStack(&s);
    printf("Input your value: ");
    scanf("%d", &value);

    while(value)
    {
        du = value%2;
        value /= 2;
        push(&s, du);
    }

    display(&s);
}