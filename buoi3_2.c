#include<stdio.h>
#include "buoi3_1.h"

int main()
{
    int value, du;
    Stack* s;
    printf("Input your value: ");
    scanf("%d", &value);
    fflush(stdin);

    do
    {
        du = value%2;
        value /= 2;
        push(s, du);
    }while(!value);

    display(s);
}