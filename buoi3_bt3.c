#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buoi3_1.c"

#define MAX_CAL 100

int main() {
    char str[MAX_CAL], *charac;
    Stack s;
    float result, a ,b;

    initStack(&s);
    fgets(str, MAX_CAL, stdin);
    result = 0;

    charac = strtok(str, " ");
    while (charac != NULL) {
        if (strcmp(charac, "*") == 0) {
            if (s.size > 0) {a = (float)pop(&s); b = (float)pop(&s); result = b * a; push(&s, result);}
        } else if (strcmp(charac, "/") == 0) {
            if (s.size > 0) {a = (float)pop(&s); b = (float)pop(&s); result = b / a; push(&s, result);}
        } else if (strcmp(charac, "+") == 0) {
            if (s.size > 0) {a = (float)pop(&s); b = (float)pop(&s); result = b + a; push(&s, result);}
        } else if (strcmp(charac, "-") == 0) {
            if (s.size > 0) {a = (float)pop(&s); b = (float)pop(&s); result = b - a; push(&s, result);}
        } else {
            push(&s, atoi(charac));
        }
        charac = strtok(NULL, " ");
    }

    printf("Result: %.2f\n", result);
    return 0;
}