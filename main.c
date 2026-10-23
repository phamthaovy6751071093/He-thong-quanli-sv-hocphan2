#include "header.h"

int main() {
    DanhSachSinhVien dsList;
    khoiTaoDanhSach(&dsList, 10); // Khởi tạo ban đầu chứa 10 sinh viên

    int choice;
    do {
        printf("\n========== HỆ THỐNG QUẢN LÝ SINH VIÊN (ĐT01) ==========\n");
        printf("1. Xem danh sách sinh viên\n");
        printf("2. Nhập/Thêm danh sách sinh viên mới\n");
        printf("0. Thoát chương trình\n");
        printf("=======================================================\n");
        printf("Mời bạn chọn chức năng (0-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                xuatDanhSach(& dsList);
                break;
            case 2:
                nhapDanhSach(& dsList);
                break;
            case 0:
                giaiPhongDanhSach(& dsList);
                printf("Đã giải phóng bộ nhớ. Tạm biệt!\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n");
        }
    } while (choice != 0);

    return 0;
}
