#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hang so
#define NAME_LENGHT 50
#define SV_ID_LENGHT 8
#define SUBJECT_ID_LENGHT 6
#define SUBJECT_NAME_LENGHT 50

//Doi tuong
typedef struct Subject
{
    char id[SUBJECT_ID_LENGHT], name[SUBJECT_NAME_LENGHT];
    int tinchi;
    float diem_qua_trinh, diem_cuoi_ky, trong_so_gk, trong_so_ck, diem_tong;
    Subject *sub_next, *sub_pre;
}Subject;

typedef struct SV
{
    char name[NAME_LENGHT], id[SV_ID_LENGHT];
    Subject* subjects;
    int subject_number;
    float gpa;
    SV *sv_next, *sv_pre;
}SV;

// Bien global
SV *sv_head, *sv_tail, *sv_current;

// Sinh vien
inline void SV_ListInit()
{
    sv_head = sv_tail = sv_current = NULL;
}

void SV_AddToEnd(char *name, char *id)
{
    if(name == NULL || id == NULL) return;

    SV *sv_moi;
    sv_moi = malloc(sizeof(SV));

    if(sv_moi == NULL) return;

    strcpy(sv_moi->name, name);
    strcpy(sv_moi->id, id);
    sv_moi->gpa = 0;
    sv_moi->subject_number = 0;
    sv_moi->subjects = NULL;
    sv_moi->sv_next = NULL;
    sv_moi->sv_pre = sv_tail;
    sv_tail = sv_moi;
}

void SV_Display()
{
    sv_current = sv_head;
    while((sv_current++) != sv_head)
    {
        printf("Thong tin sinh vien:\n");
        printf("1. Ten:%s\n", sv_current->name);
        printf("2. ID:%s\n", sv_current->id);
        printf("3. Number of subject:%d\n", sv_current->subject_number);
        printf("4. GPA:%.2f\n", sv_current->gpa);
    }
}

inline SV* SV_SearchByID(char* id)
{
    if(id == NULL) return;

    while(!strcmp(sv_current->id, id))
        return sv_current;
}

void SV_DeleteByID(char* id)
{
    if(id == NULL) return;

    sv_current = sv_head;
    while((sv_current++) != sv_tail)
    {
        if(strcmp(sv_current->id, id))
        {
            sv_current->sv_pre->sv_next = sv_current->sv_next;
            sv_current->sv_next->sv_pre = sv_current->sv_pre;
            SUB_AllSubFree(sv_current);
            free(sv_current);
        }
    }
}

float SV_GPAUpdate(SV *sv)
{
    if(sv == NULL) return;

    Subject *sub;

    sub = sv->subjects;
    while((sub++) != NULL)
        sv->gpa += sub->tinchi * sub->diem_tong;
    sv->gpa /= sv->subject_number;

    return sv->gpa;
}

// Mon hoc
void SUB_AddToEnd(SV *sv, char *sub_name, char *sub_id, int tinchi, float diemgk, float diemck, float trongsogk, float trongsock)
{
    if((trongsock + trongsogk != 1) || (sv == NULL)) return;

    Subject* sub_new;
    sub_new = malloc(sizeof(Subject));
    
    strcpy(sub_new->name, sub_name);
    strcpy(sub_new->id, sub_id);
    sub_new->tinchi = tinchi;
    sub_new->diem_qua_trinh = diemgk;
    sub_new->diem_cuoi_ky = diemck;
    sub_new->trong_so_gk = trongsogk;
    sub_new->trong_so_ck = trongsock;
    sub_new->diem_tong = trongsock * diemck + trongsogk * diemgk; // Tinh diem tong

    if(sv->subjects == NULL) sv->subjects = sub_new;
    else 
    {
        sv->subjects->sub_next = sub_new;
        sv->subjects = sub_new;
    }

    sv->subject_number += tinchi;
}

Subject* SUB_SearchByID(SV *sv, char *sub_id)
{
    if(sv == NULL || sub_id == NULL) return NULL;

    Subject *sb;

    sb = sv->subjects;
    while((sb++)->sub_pre != NULL)
        if(!strcmp(sb->id, sub_id)) return sb;
}

void SUB_DeleteByID(char *id, SV *sv)
{
    if(id == NULL || sv == NULL) return;

    Subject *sub_search_by_id;

    sub_search_by_id = sv->subjects;
    while(strcmp((sub_search_by_id++)->id, id))
        free(sub_search_by_id);
}

inline void SUB_AllSubFree(SV *sv)
{
    while(sv->subjects != NULL)
        free(sv->subjects);
}

// Ham menu va hien thi
void DISPLAY_SVList()
{
    int choice;
    char *name, *id;

    name = malloc(NAME_LENGHT * sizeof(char));
    id = malloc(SV_ID_LENGHT * sizeof(char));

    for(;;) //Menu chinh
    {
        printf("APP QUAN LY DANH SACH SINH VIEN\n");
        printf("===========================================================");
        printf("Huong dan su dung:\n1. Them sinh vien\n2. Hien thi danh sach\n3. Tim sinh vien theo ma\n4. Xoa sinh vien theo ma\n5. Quan ly mon hoc cua sinh vien( Can nhap ID sinh vien )\n0. Thoat"); 
        printf("===========================================================");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0: return; 
            case 1: 
                fgets(name, NAME_LENGHT, stdin);
                fgets(id, SV_ID_LENGHT, stdin);

                SV_AddToEnd(name, id);
                break;
            case 2: SV_Display(); break;
            case 3: 
                fgets(id, SV_ID_LENGHT, stdin);
                SV_SearchByID(id);
                break;
            case 4: 
                fgets(id, SV_ID_LENGHT, stdin);
                SV_DeleteByID(id);
                break;
            case 5:
                fgets(id, SV_ID_LENGHT, stdin);
                DISPLAY_SubList(id);
                break;
        }
    }
}

void DISPLAY_SubList(char *id)
{
    int choice;
    char *sub_name, *sub_id;
    int tinchi;
    float diemgk, diemck, trongsogk, trongsock, diemtong;
    SV *sivi;

    sivi = SV_SearchByID(id);

    for(;;) 
    {
        printf("APP QUAN LY SINH VIEN\n");
        printf("===========================================================");
        printf("Huong dan su dung:\n1. Them mon hoc\n2. Xoa mon theo ID\n3. Tinh GPA sinh vien\n0. Quay lai\n"); 
        printf("===========================================================");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0: return;
            case 1: 
                fgets(sub_name, SUBJECT_NAME_LENGHT, stdin);
                getchar();
                fgets(sub_id, SUBJECT_ID_LENGHT, stdin);
                getchar();

                scanf("%d", &tinchi);
                scanf("%f", &diemgk);
                scanf("%f", &diemck);
                scanf("%f", &trongsogk);
                scanf("%f", &trongsock);

                SUB_AddToEnd(sivi, sub_name, sub_id, tinchi, diemgk, diemck, trongsogk, trongsock);
                break;
            case 2:
                fgets(sub_id, SUBJECT_ID_LENGHT, stdin);
                SUB_DeleteByID(id, sivi);
                break;
            case 3:
                SV_GPAUpdate(sivi);
                break;
        }
    }
}

// Ham chinh
// int main(int agrc, char* agrv[])
// {}