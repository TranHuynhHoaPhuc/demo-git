#include <stdio.h>
int main() {
    const char *danhSachSinhVien[] = {
        "Nguyen Van A",
        "Tran Thi B",
        "Le Van C",
        "Pham Thi D",
        "Hoang Van E"
    };
    int soLuong = sizeof(danhSachSinhVien) / sizeof(danhSachSinhVien[0]);
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("%d. %s\n", i + 1, danhSachSinhVien[i]);
    }

    return 0;
}
