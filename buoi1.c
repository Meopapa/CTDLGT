#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int ARRAY[MAX], *ARRAY_, *ARRAY_1; 

void ARRAY_Add(int vitri, int m)
{
    if (vitri < 0 || vitri >= MAX) return;
    if(m==1)
    {
    scanf("%d", &ARRAY[vitri]);
    fflush(stdin);
    }
    else if(m==2)
    {
        ARRAY_1 = realloc(ARRAY_, sizeof(int)*MAX+1);
        for(int i = 0; i < vitri; i++)
        {
            ARRAY_1[i] = ARRAY_[i];
        }
        scanf("%d", &ARRAY_1[vitri]);
        for(int i = vitri + 1; i < MAX+1; i++)
        {
            ARRAY_1[i] = ARRAY_[i-1];
        } 
    }
}

void ARRAY_Delete(int vitri, int m)
{
    int x;
    scanf("%d", &x);
    fflush(stdin);
    if (vitri < 0 || vitri >= MAX) return;
    if(m==1){
    for(int i = vitri - 1; i < MAX - 1; i++)
    {
        ARRAY[i] = ARRAY[i + 1];    
    }

    ARRAY[MAX - 1] = 0;
    }
    else if(m==2)
    {
        for(int i = vitri - 1; i < MAX - 1; i++)
    {
        ARRAY_[i] = ARRAY_[i + 1];    
    }

    ARRAY_1 = realloc(ARRAY_ , sizeof(int)*MAX-1);
    }
}

int ARRAY_Find(int vitri, int m)
{
    if (vitri < 0 || vitri >= MAX) return -1;
    if(m==1) return ARRAY[vitri];    
    else if(m==2) return ARRAY_[vitri];
}

int main(int argc, char *argv[])
{
    int n, m, k;
    for(int i = 0; i < MAX; i++)
    {
        ARRAY[i] = 0;
    }

    ARRAY_ = malloc(MAX*sizeof(int));

    while(1)
    {
        printf("1. Mang dong\n");
        printf("2. Mang tinh\n");
        printf("Choose type of array:\n");
        scanf("%d", &m); fflush(stdin);
        switch(m)
        {
            case 1: 
            printf("-------------------------------------------------------\n");
            printf("1. Add\n");
            printf("2. Delete\n");
            printf("3. Find\n");
            printf("4. Exit\n");
            printf("Choose function:\n");
            scanf("%d", &n); fflush(stdin);
            printf("-------------------------------------------------------\n"); 
            switch(n)
        {
        case 1: printf("Nhap vi tri mang: "); scanf("%d", &k); fflush(stdin); ARRAY_Add(k, m); break;
        case 2: printf("Nhap vi tri mang: "); scanf("%d", &k); fflush(stdin); ARRAY_Delete(k, m); break;
        case 3: scanf("%d", &k); fflush(stdin); printf("%d\n", ARRAY_Find(k, m)); break;
        case 4: return 0; break;
        default: break;
        }
            break;
            case 2: 
            printf("-------------------------------------------------------\n");
            printf("1. Add\n");
            printf("2. Delete\n");
            printf("3. Find\n");
            printf("4. Exit\n");
            printf("Choose function:\n");
            scanf("%d", &n); fflush(stdin);
            printf("-------------------------------------------------------\n"); 
            switch(n)
        {
        case 1: printf("Nhap vi tri mang: "); scanf("%d", &k); fflush(stdin); ARRAY_Add(k, m); break;
        case 2: printf("Nhap vi tri mang: "); scanf("%d", &k); fflush(stdin); ARRAY_Delete(k, m); break;
        case 3: scanf("%d", &k); fflush(stdin); printf("%d\n", ARRAY_Find(k, m)); break;
        case 4: return 0; break;
        default: break;
        }
            break;
            default: return 0; break;
        }
    }
    return 0;
}