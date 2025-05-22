#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char ten[50];
    float diem;
} SinhVien;
int main() {
    FILE *file;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SinhVien *ds = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ten: ");
        scanf(" %[^\n]", ds[i].ten);
        printf("Diem: ");
        scanf("%f", &ds[i].diem);
    }
    file = fopen("sinhvien.txt", "w");
    if (file == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        free(ds);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %.2f\n", ds[i].ten, ds[i].diem);
    }
    fclose(file);
    printf("\nDa ghi du lieu vao file 'sinhvien.txt'.\n");
    file = fopen("sinhvien.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file de doc!\n");
        free(ds);
        return 1;
    }
    printf("\nNoi dung file 'sinhvien.txt':\n");
    char ten[50];
    float diem;
    while (fscanf(file, " %[^\n] %f", ten, &diem) == 2) {
        printf("Ten: %s | Diem: %.2f\n", ten, diem);
    }
    fclose(file);
    free(ds);
    return 0;
}
