#include <stdio.h>
#define MAX 100
void inMang(int arr[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void tinhTong(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++)
        tong += arr[i];
    printf("Tong cac phan tu: %d\n", tong);
}
void timMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    printf("Gia tri lon nhat: %d\n", max);
}
void demChan(int arr[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            dem++;
    printf("So luong phan tu chan: %d\n", dem);
}
typedef void (*HamXuLy)(int[], int);

int main() {
    int n, arr[MAX];
    printf("Nhap so luong phan tu (toi da 100): ");
    scanf("%d", &n);
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    HamXuLy dsHam[] = {inMang, tinhTong, timMax, demChan};
    const char *menu[] = {
        "In mang",
        "Tinh tong",
        "Tim gia tri lon nhat",
        "Dem so chan"
    };
    int chon;
    do {
        printf("\n----- MENU -----\n");
        for (int i = 0; i < 4; i++)
            printf("%d. %s\n", i + 1, menu[i]);
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &chon);

        if (chon >= 1 && chon <= 4) {
            dsHam[chon - 1](arr, n); 
        } else if (chon != 0) {
            printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);
    return 0;
}
