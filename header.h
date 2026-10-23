#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct luu tru sinh vien
typedef struct SinhVien {
    char maSV[10];       
    char hoTen[50];     
    float diemGK;      
    float diemCK;       
    float gpa;          
    char diemChu[3];     
    char xepLoai[20];   
} sv;

// quan li nhan vien
typedef struct DanhSachSinhVien {
    SinhVien *data;      
    int capacity;        
    int size;          
} ds;
// Khai báo nguyên mẫu các hàm
void khoiTaoDanhSach(DanhSachSinhVien *dsList, int initial_capacity); // Pham Thao Vy phu trach
void nhapDanhSach(DanhSachSinhVien *dsList);// Nguyen Chi Bao phu trach
void xuatDanhSach(const DanhSachSinhVien *dsList); // Nguyen Ngoc Thuy phu trach
void tinhGpaVaXepLoai(SinhVien *sv); // Le Thi Cam Tu phu trach
void giaiPhongDanhSach(DanhSachSinhVien *dsList);

#endif
