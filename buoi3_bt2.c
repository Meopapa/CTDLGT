#include <stdio.h>
#include <string.h>
#include "buoi3_1.c"

#define MAX 100

int main() {
    Stack s;
    char str[MAX];
    initStack(&s);

    fgets(str, MAX, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&s, 1);
        } else if (str[i] == ')') {
            if (s.size > 0 && s.infor[s.size - 1] == 1) {
                pop(&s); 
            } else {
                push(&s, 2); 
            }
        }
    }

    for (int i = 0; i < s.size; i++) {
        if (s.infor[i] == 1) printf("(");
        else if (s.infor[i] == 2) printf(")");
    }

    return 0;
}