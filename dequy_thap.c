#include <stdio.h>
#include "buoi3_1.h"
#include <string.h>

void HNTower(char A, char B, char C, int n)
{
    if(n==1)
    {
        printf("%c --> %c\n", A, B);
    }
    else
    {
        HNTower(A, C, B, n-1); // bài toán 3 vòng
        HNTower(A, B, C, 1); // chuyển đĩa nhỏ thứ 2 từ A sang B
        HNTower(C, B, A, n-1);
    }
}

int Tong(int n, int sum)
{
    sum += n;
    if(!n)
    {
        return sum;
    }
    else
    {
        Tong(n-1, sum);
    }
}

int GTNN_Chuan(int a[], int f, int l)
{
    if(f == l) return a[f];
    else
    {
        int mid = (f+1)/2;
        int min_1 = GTNN_Chuan(a,  f, mid);
        int min_2 = GTNN_Chuan(a, mid + 1, l);
        return (min_1 < min_2) ? min_1 : min_2;
    }
}

int UCLN(int a, int b)
{
    int ucln;
    ucln = (a>b) ? (a-b) : (b-a);
    if(b == ucln && b != 0) return ucln;
    if(b > ucln) UCLN(b, ucln);
    else UCLN(ucln, b);
}

int TongSo(int n, int sum)
{
    if(n <= 0) return 0;
    sum += n%10;
    if(n < 10) return sum;
    else TongSo(n/10, sum);
}

void daoNguocChuoi(char* str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    daoNguocChuoi(str, start + 1, end - 1);
}

int ToHop(int n, int k)
{
    if (k == 0 || k == n) return 1;
    return ToHop(n - 1, k - 1) + ToHop(n - 1, k);
}

// ==========================================================================================//
int Tong(int n, int sum) 
{
    while (n > 0) 
    {
        sum += n;
        n--;
    }
    return sum;
}

int GTNN_Chuan(int a[], int f, int l) 
{
    int min = a[f];
    for (int i = f + 1; i <= l; i++) 
    {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int UCLN(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int TongSo(int n, int sum) 
{
    while (n > 0) 
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void daoNguocChuoi(char* str, int start, int end) 
{
    while (start < end) 
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int ToHop(int n, int k) 
{
    if (k > n - k) k = n - k; 
    int res = 1;
    for (int i = 1; i <= k; i++) 
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
// ========================================================================================//

int main()
{
    // int sum = 0;
    // int arr[5] = {3,5,7,1,9};
    // char s[] = "Hello World";
    // HNTower('A', 'B', 'C', 4); //Can 2^n - 1
    // Tong(4, sum);
    // Giatrinhonhat(arr, 5, 0, arr[0]);
    // printf("%d", UCLN(12, 16));
    // printf("%d", TongSo(200, 0));
    // daoNguocChuoi(s, 0, strlen(s) - 1); printf("%s", s);
    // printf("%d", ToHop(3,2));
}