#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h" // Nhung file vao cau truc

#include "header.h"

//xoa bo nho dem tu ban phim
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//chong tran bo nho va kiem tra do dai cua thong tin nhap vao
void inputString(char *buffer, int length) {
    if (fgets(buffer, length, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            clearInputBuffer();
        }
    }
}
//khoi tao mang dong
void initList(DanhSachSinhVien *list, int initialCapacity) {
    list->data = (SinhVien *)malloc(initialCapacity * sizeof(SinhVien));
    if (list->data == NULL) {
        printf("Loi: Khong du bo nho cap phat!\n");
        exit(1);
    }
    list->capacity = initialCapacity;
    list->size = 0;
}

// giai phong bo nho
void freeList(DanhSachSinhVien *list) {
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
    }
    list->capacity = 0;
    list->size = 0;
}

// nhap thong tin sinh vien
SinhVien inputOneStudent(DanhSachSinhVien *list) {
    SinhVien sv;
 
    printf("\n--- NHAP THONG TIN SINH VIEN MONG MUON --- \n");
    printf("Nhap Ma SV: ");
    inputString(sv.maSV, sizeof(sv.maSV));

    printf("Nhap Ho va Ten: ");
    inputString(sv.hoTen, sizeof(sv.hoTen));

    do {
        printf("Nhap Diem Giua Ky (0.0 - 10.0): ");
        if (scanf("%f", &sv.diemGK) != 1 || sv.diemGK < 0 || sv.diemGK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

    do {
        printf("Nhap Diem Cuoi Ky (0.0 - 10.0): ");
        if (scanf("%f", &sv.diemCK) != 1 || sv.diemCK < 0 || sv.diemCK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

   
    return sv;


// ==========================================================
// PHAN CUA LE THI CAM TU: Tinh GPA, Xep loai hoc luc, Phan loai diem chu
// ==========================================================
void tinhGpaVaXepLoai(SinhVien *sv) {
    // Tinh diem GPA he so 10 (Giua ki 40%, Cuoi ky 60%)
    sv->gpa = (sv->diemGK * 0.4f) + (sv->diemCK * 0.6f);

    // Xep loai hoc luc
    if (sv->gpa >= 8.5) {
        strcpy(sv->xepLoai, "Xuat sac");
    } else if (sv->gpa >= 7.0) {
        strcpy(sv->xepLoai, "Gioi");
    } else if (sv->gpa >= 5.5) {
        strcpy(sv->xepLoai, "Kha");
    } else if (sv->gpa >= 4.0) {
        strcpy(sv->xepLoai, "Trung binh");
    } else {
        strcpy(sv->xepLoai, "Yeu");
    }

    // Phan loai diem chu (Chuan he tinh chi)
    if (sv->gpa >= 8.5) {
        strcpy(sv->diemChu, "A");
    } else if (sv->gpa >= 8.0) {
        strcpy(sv->diemChu, "B+");
    } else if (sv->gpa >= 7.0) {
        strcpy(sv->diemChu, "B");
    } else if (sv->gpa >= 6.5) {
        strcpy(sv->diemChu, "C+");
    } else if (sv->gpa >= 5.5) {
        strcpy(sv->diemChu, "C");
    } else if (sv->gpa >= 5.0) {
        strcpy(sv->diemChu, "D+");
    } else if (sv->gpa >= 4.0) {
        strcpy(sv->diemChu, "D");
    } else {
        strcpy(sv->diemChu, "F");
    }
}

