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

// ==========================================================
// PHAN KHOI TAO, NHAP, XUAT DANH SACH (Mang dong)
// ==========================================================
void khoiTaoDanhSach(DanhSachSinhVien *dsList, int initial_capacity) {
    dsList->data = (SinhVien *)malloc(initial_capacity * sizeof(SinhVien));
    dsList->size = 0;
    dsList->capacity = initial_capacity;
}

void nhapDanhSach(DanhSachSinhVien *dsList) {
    int n;
    printf("\nNhap so luong sinh vien muon them: ");
    scanf("%d", &n);
    xoaBoDem();

    for (int i = 0; i < n; i++) {
        // Tu dong cap phat mo rong mang neu vuot qua suc chua (realloc)
        if (dsList->size >= dsList->capacity) {
            dsList->capacity *= 2;
            dsList->data = (SinhVien *)realloc(dsList->data, dsList->capacity * sizeof(SinhVien));
        }

        SinhVien *sv = &dsList->data[dsList->size];
        printf("\n--- Nhap thong tin sinh vien thu %d ---\n", dsList->size + 1);
        
        printf("Nhap Ma SV: ");
        scanf("%9s", sv->maSV);
        xoaBoDem();

        printf("Nhap Ho va Ten: ");
        fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
        sv->hoTen[strcspn(sv->hoTen, "\n")] = 0; // xoa ky tu xuong dong

        printf("Nhap Diem Giua Ky (diemGK): ");
        scanf("%f", &sv->diemGK);

        printf("Nhap Diem Cuoi Ky (diemCK): ");
        scanf("%f", &sv->diemCK);
        xoaBoDem();

        // Tu dong goi ham tinh toan GPA, xep loai hoc luc va diem chu
        tinhGpaVaXepLoai(sv);

        dsList->size++;
    }
    printf("=>Nhap danh sach sinh vien thanh cong!\n");
}

void xuatDanhSach(const DanhSachSinhVien *dsList) {
    if (dsList->size == 0) {
        printf("\nDanh sach sinh vien hien dang trong!\n");
        return;
    }

    printf("\n================================ DANH SÁCH SINH VIÊN ================================\n");
    printf("%-10s | %-22s | %-8s | %-8s | %-6s | %-12s | %-8s\n", 
           "Ma SV", "Ho va Ten", "Diem GK", "Diem CK", "GPA", "Xep Loai", "Diem Chu");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < dsList->size; i++) {
        SinhVien sv = dsList->data[i];
        printf("%-10s | %-22s | %-8.1f | %-8.1f | %-6.2f | %-12s | %-8s\n", 
               sv.maSV, sv.hoTen, sv.diemGK, sv.diemCK, sv.gpa, sv.xepLoai, sv.diemChu);
    }
    printf("=====================================================================================\n");
}

void giaiPhongDanhSach(DanhSachSinhVien *dsList) {
    if (dsList->data) {
        free(dsList->data);
        dsList->data = NULL;
    }
    dsList->size = 0;
    dsList->capacity = 0;
}
