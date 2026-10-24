#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h" // Nhung file vao cau truc

#include "header.h"
include <stdio.h>
#include <string.h>
// ==========================================================
// PHAN CUA NGUYEN NGOC THUY: Ham xoa va ham sap xep
// ==========================================================
struct SinhVien { char maSV[20]; char hoTen[50]; float gpa; };

// Ham xoa
void xoaSinhVien(struct SinhVien danhSach[], int *n) {
    char maXoa[20]; int vt = -1;
    printf("Nhap ma can xoa: "); scanf("%s", maXoa);
    for (int i = 0; i < *n; i++) {
        if (strcmp(danhSach[i].maSV, maXoa) == 0) { vt = i; break; }
    }
    if (vt == -1) printf("Khong tim thay!\n");
    else {
        for (int i = vt; i < *n - 1; i++) danhSach[i] = danhSach[i + 1];
        (*n)--; printf("Xoa thanh cong!\n");
    }
}

// Ham sap xep
void sapXepGPAGiamDan(struct SinhVien danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i].gpa < danhSach[j].gpa) {
                struct SinhVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Sap xep xong!\n");
}

int main() {
    struct SinhVien ds[3] = {{"SV01","An",2.5}, {"SV02","Binh",3.9}, {"SV03","Cuong",3.2}};
    int n = 3;
    
    sapXepGPAGiamDan(ds, n); // Chạy thử xếp điểm
    xoaSinhVien(ds, &n);      // Chạy thử xóa
    return 0;
}
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

