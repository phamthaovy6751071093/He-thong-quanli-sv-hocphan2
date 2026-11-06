#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>
#if defined(_WIN32) || defined(_WIN64)
    #define strcasestr strstr
#endif

typedef struct SinhVien {
    char maSV[11];       
    char hoTen[50];      
    float diemGK;      
    float diemCK;        
    float gpa;           
    char diemChu[3];     
    char xepLoai[20];    
} SinhVien;

typedef struct DanhSachSinhVien {
    SinhVien *data;     
    int capacity;       
    int size;           
} DanhSachSinhVien;

void clearInputBuffer();
void inputString(char *buffer, int length);
void initList(DanhSachSinhVien *list, int initialCapacity);
void freeList(DanhSachSinhVien *list);
void tinhGpaVaXepLoai(SinhVien *sv);
SinhVien inputOneStudent(DanhSachSinhVien *list);
void addStudent(DanhSachSinhVien *list, SinhVien sv);
void printStudentList(DanhSachSinhVien list);
void find_student_by_name(DanhSachSinhVien list, char tuKhoa[]);
void suaThongTinSinhVien(DanhSachSinhVien *list);
void xoaSinhVien(DanhSachSinhVien *list);
void sapXepGPAGiamDan(DanhSachSinhVien *list);
void displayMenu();

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

void initList(DanhSachSinhVien *list, int initialCapacity) {
    list->data = (SinhVien *)malloc(initialCapacity * sizeof(SinhVien));
    if (list->data == NULL) {
        printf("Loi: Khong du bo nho cap phat!\n");
        exit(1);
    }
    list->capacity = initialCapacity;
    list->size = 0;
}

void freeList(DanhSachSinhVien *list) {
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
    }
    list->capacity = 0;
    list->size = 0;
}

void tinhGpaVaXepLoai(SinhVien *sv) {
    sv->gpa = (sv->diemGK * 0.4f) + (sv->diemCK * 0.6f);

    if (sv->gpa >= 8.5) strcpy(sv->xepLoai, "Xuat sac");
    else if (sv->gpa >= 7.0) strcpy(sv->xepLoai, "Gioi");
    else if (sv->gpa >= 5.5) strcpy(sv->xepLoai, "Kha");
    else if (sv->gpa >= 4.0) strcpy(sv->xepLoai, "Trung binh");
    else strcpy(sv->xepLoai, "Yeu");

    if (sv->gpa >= 8.5) strcpy(sv->diemChu, "A");
    else if (sv->gpa >= 8.0) strcpy(sv->diemChu, "B+");
    else if (sv->gpa >= 7.0) strcpy(sv->diemChu, "B");
    else if (sv->gpa >= 6.5) strcpy(sv->diemChu, "C+");
    else if (sv->gpa >= 5.5) strcpy(sv->diemChu, "C");
    else if (sv->gpa >= 5.0) strcpy(sv->diemChu, "D+");
    else if (sv->gpa >= 4.0) strcpy(sv->diemChu, "D");
    else strcpy(sv->diemChu, "F");
}

SinhVien inputOneStudent(DanhSachSinhVien *list) {
    SinhVien sv;
    printf("\n--- NHAP THONG TIN SINH VIEN MOI --- \n");
    printf("Nhap Ma SV: ");
    inputString(sv.maSV, sizeof(sv.maSV));

    printf("Nhap Ho va Ten: ");
    inputString(sv.hoTen, sizeof(sv.hoTen));

    do {
        printf("Nhap Diem Giua Ky (0 - 10): ");
        if (scanf("%f", &sv.diemGK) != 1 || sv.diemGK < 0 || sv.diemGK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

    do {
        printf("Nhap Diem Cuoi Ky (0 - 10): ");
        if (scanf("%f", &sv.diemCK) != 1 || sv.diemCK < 0 || sv.diemCK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

    tinhGpaVaXepLoai(&sv);
    return sv;
}

void addStudent(DanhSachSinhVien *list, SinhVien sv) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (SinhVien *)realloc(list->data, list->capacity * sizeof(SinhVien));
        if (list->data == NULL) {
            printf("Loi: Khong the mo rong bo nho!\n");
            exit(1);
        }
    }
    list->data[list->size] = sv;
    list->size++;
    printf("=> Them sinh vien thanh cong!\n");
}

void printStudentList(DanhSachSinhVien list) {
    if (list.size == 0) {
        printf("\nDanh sach sinh vien hien dang rong!\n");
        return;
    }
    printf("\n=========================================================================================================\n");
    printf("%-5s | %-12s | %-25s | %-8s | %-8s | %-6s | %-8s | %-12s\n", 
           "STT", "Ma SV", "Ho va Ten", "Diem GK", "Diem CK", "GPA", "Diem Chu", "Xep Loai");
    printf("=========================================================================================================\n");
    for (int i = 0; i < list.size; i++) {
        printf("%-5d | %-12s | %-25s | %-8.2f | %-8.2f | %-6.2f | %-8s | %-12s\n",
               i + 1, list.data[i].maSV, list.data[i].hoTen, list.data[i].diemGK,
               list.data[i].diemCK, list.data[i].gpa, list.data[i].diemChu, list.data[i].xepLoai);
    }
    printf("=========================================================================================================\n");
}

void find_student_by_name(DanhSachSinhVien list, char tuKhoa[]) {
    int dem = 0;
    printf("\n--- KET QUA TIM KIEM THEO TEN (%s) ---\n", tuKhoa);
    for (int i = 0; i < list.size; i++) {
        if (strcasestr(list.data[i].hoTen, tuKhoa) != NULL) {
            printf("Ma SV: %-10s | Ho ten: %-25s | Diem GK: %5.2f | Diem CK: %5.2f | GPA: %5.2f | Xep loai: %s\n",
                   list.data[i].maSV, list.data[i].hoTen, list.data[i].diemGK, list.data[i].diemCK, list.data[i].gpa, list.data[i].xepLoai);
            dem++;
        }
    }
    if (dem == 0) printf("Khong tim thay sinh vien nao phu hop!\n");
}

void suaThongTinSinhVien(DanhSachSinhVien *list) {
    char maTimKiem[11];
    int timThay = -1;
    printf("\n--- SUA THONG TIN SINH VIEN ---\n");
    printf("Nhap Ma SV cua sinh vien can sua: ");
    inputString(maTimKiem, sizeof(maTimKiem));

    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->data[i].maSV, maTimKiem) == 0) {
            timThay = i;
            break;
        }
    }

    if (timThay == -1) {
        printf("Khong tim thay sinh vien co Ma SV la: %s\n", maTimKiem);
        return;
    }

    printf("Nhap Ho va Ten moi: ");
    inputString(list->data[timThay].hoTen, sizeof(list->data[timThay].hoTen));

    do {
        printf("Nhap Diem Giua Ky moi (0 - 10): ");
        if (scanf("%f", &list->data[timThay].diemGK) != 1 || list->data[timThay].diemGK < 0 || list->data[timThay].diemGK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

    do {
        printf("Nhap Diem Cuoi Ky moi (0 - 10): ");
        if (scanf("%f", &list->data[timThay].diemCK) != 1 || list->data[timThay].diemCK < 0 || list->data[timThay].diemCK > 10) {
            printf("Diem khong hop le! Vui long nhap lai.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    } while (1);

    tinhGpaVaXepLoai(&list->data[timThay]);
    printf("Sua thong tin sinh vien thanh cong!\n");
}

void xoaSinhVien(DanhSachSinhVien *list) {
    char maXoa[11]; 
    int vt = -1;
    printf("\n--- XOA SINH VIEN ---\n");
    printf("Nhap ma SV can xoa: "); 
    inputString(maXoa, sizeof(maXoa));
    
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->data[i].maSV, maXoa) == 0) { 
            vt = i; 
            break; 
        }
    }
    
    if (vt == -1) {
        printf("Khong tim thay sinh vien co ma: %s\n", maXoa);
    } else {
        for (int i = vt; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        list->size--; 
        printf("Xoa sinh vien thanh cong!\n");
    }
}

void sapXepGPAGiamDan(DanhSachSinhVien *list) {
    if (list->size < 2) {
        printf("Danh sach qua it sinh vien de sap xep!\n");
        return;
    }
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = i + 1; j < list->size; j++) {
            if (list->data[i].gpa < list->data[j].gpa) {
               SinhVien temp = list->data[i];
               list->data[i] = list->data[j];
               list->data[j] = temp;
            }
        }
    }
    printf("=> Sap xep danh sach theo GPA giam dan thanh cong!\n");
}

void displayMenu() {
    printf("\n========================================================\n");
    printf("    HE THONG QUAN LY SINH VIEN & DIEM HOC PHAN    \n");
    printf("========================================================\n");
    printf("1. Nhap / Them sinh vien moi\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Sap xep danh sach theo GPA giam dan\n");
    printf("4. Tim kiem sinh vien theo ten\n");
    printf("5. Sua thong tin sinh vien theo Ma SV\n");
    printf("6. Xoa sinh vien theo Ma SV\n");
    printf("0. Thoat va Giai phong bo nho\n");
    printf("========================================================\n");
    printf("Vui long chon chuc nang (0-6): ");
}

int main() {
    DanhSachSinhVien list;
    initList(&list, 10); 
    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Loi: Vui long nhap so nguyen hop le!\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                SinhVien sv = inputOneStudent(&list);
                addStudent(&list, sv);
                break;
            }
            case 2:
                printStudentList(list);
                break;
            case 3:
                sapXepGPAGiamDan(&list);
                printStudentList(list);
                break;
            case 4: {
                if (list.size == 0) {
                    printf("\nDanh sach rong, khong the tim kiem!\n");
                    break;
                }
                char tuKhoa[50];
                printf("Nhap ten hoac tu khoa ten can tim: ");
                inputString(tuKhoa, sizeof(tuKhoa));
                find_student_by_name(list, tuKhoa);
                break;
            }
            case 5:
                suaThongTinSinhVien(&list);
                break;
            case 6:
                xoaSinhVien(&list);
                break;
            case 0:
                printf("\n=> Dang thoat chuong trinh va giai phong bo nho...\n");
                freeList(&list);
                printf("=> Da thoat an toan!\n");
                break;
            default:
                printf("\nLoi: Lua chon khong hop le! Vui long chon tu 0 den 6.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
