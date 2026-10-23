#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h" // Nhung file vao cau truc

#include "header.h"

// Hàm hỗ trợ xóa bộ đệm bàn phím (chống trôi lệnh)
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

