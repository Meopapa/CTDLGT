#include <stdio.h>
#include <string.h>
#include <ctype.h>      
#include "buoi3_1.c"    

#define MAX_STR 100

int main() {
    char str[MAX_STR];
    Stack s;
    initStack(&s);

    printf("Nhap chuoi can kiem tra: ");
    fgets(str, MAX_STR, stdin);

    str[strcspn(str, "\n")] = '\0';

    // Đưa các ký tự hợp lệ vào stack
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c != ' ') {                 
            push(&s, tolower(c));       
        }
    }

    int is_palindrome = 1;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == ' ') continue;         
        if (tolower(c) != pop(&s)) {    
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
        printf("Chuoi doi xung.\n");
    else
        printf("Chuoi KHONG doi xung.\n");

    return 0;
}
