#include<stdio.h>

typedef struct
{
    unsigned int mssv;
    float dienTB;
    char hoTen[80];
}Sinhvien;


void INPUT_TenSV(char *ten);
void SCORE_Average(float diem);
void SCORE_Update(float *diemTB);
void CHECK_Pass(float diem);

int main(int argc, char* argv[])
{
    Sinhvien sv;
    printf("Nhap ten sinh vien: ");
    INPUT_TenSV(&sv.hoTen);
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &sv.mssv);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv.dienTB);
    fflush(stdin);

    SCORE_Average(sv.dienTB);
    SCORE_Update(&sv.dienTB);
    CHECK_Pass(sv.dienTB);
}

void INPUT_TenSV(char *ten)
{
    fgets(ten, 80, stdin);
}

void SCORE_Average(float diem)
{
    printf("%f", diem);
}

void SCORE_Update(float *diemTB)
{
    scanf("%f", &diemTB);
    fflush(stdin);
}

void CHECK_Pass(float diem)
{
    (diem >= 4)? printf("Pass!") : printf("Not pass!");
}