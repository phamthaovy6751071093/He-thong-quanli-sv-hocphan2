#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
    #define strcasestr strstr
#endif

#define ACCOUNT_FILE "accounts.dat"
#define STUDENT_FILE "students.dat"

// Phân quyền hệ thống
typedef enum { ROLE_ADMIN = 1, ROLE_STUDENT = 2 } Role;

// Cấu trúc Lưu trữ Sinh Viên & Điểm Số
typedef struct SinhVien {
    char maSV[11];
    char hoTen[50];
    float diemGK;
    float diemCK;
    float gpa;
    char diemChu[3];
    char xepLoai[20];
} SinhVien;

// Cấu trúc Danh sách Sinh Viên (Mảng động)
typedef struct DanhSachSinhVien {
    SinhVien *data;
    int capacity;
    int size;
} DanhSachSinhVien;

// Cấu trúc Tài Khoản
typedef struct TaiKhoan {
    char username[30];
    char password[30];
    Role role;
    char maSV[11]; // Liên kết với Ma SV nếu role == ROLE_STUDENT
} TaiKhoan;

// Cấu trúc Danh sách Tài Khoản (Mảng động)
typedef struct DanhSachTaiKhoan {
    TaiKhoan *data;
    int capacity;
    int size;
} DanhSachTaiKhoan;
