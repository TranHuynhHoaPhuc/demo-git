#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char maSV[10];
    char hoTen[50];
    float diem;
} SinhVien;
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SinhVien *ds = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma SV: ");
        scanf("%s", ds[i].maSV);
        printf("Ho ten: ");
        scanf(" %[^\n]", ds[i].hoTen);
        printf("Diem: ");
        scanf("%f", &ds[i].diem);
    }
    printf("\nDanh sach sinh vien vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("MaSV: %s | Ho ten: %s | Diem: %.2f\n", ds[i].maSV, ds[i].hoTen, ds[i].diem);
    }
    printf("\nDanh sach sinh vien dau (diem >= 5):\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 5.0) {
            printf("MaSV: %s | Ho ten: %s | Diem: %.2f\n", ds[i].maSV, ds[i].hoTen, ds[i].diem);
        }
    }
    free(ds);
    return 0;
}
