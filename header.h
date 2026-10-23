#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct luu tru sinh vien
typedef struct SinhVien {
    char maSV[11];       
    char hoTen[50];     
    float diemGK;      
    float diemCK;       
    float gpa;          
    char diemChu[3];     
    char xepLoai[20];   
} SinhVien;

// quan li nhan vien
typedef struct DanhSachSinhVien {
    SinhVien *data;      
    int capacity;        
    int size;          
} DanhSachSinhVien;
// Khai khai bao ham nhap, xuat va bo nho
void initlist(DanhSachSinhVien *dsList, int initial_capacity); 
void freelist(DanhSachSinhVien *dsList);
void clearInputBuffer();
void inputString(char *buffer, int length);
SinhVien inputOneStudent(DanhSachSinhVien *list);
void addStudent(DanhSachSinhVien *list, SinhVien sv);
void printStudentList(DanhSachSinhVien list);

#endif
