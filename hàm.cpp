#include <stdio.h>
int tong(int a, int b) {
    return a + b;
}
int giaithua(int n) {
    if (n == 0) return 1;
    return n * giaithua(n - 1);
}
int laNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0) return 0;
    return 1;
}
int main() {
    printf("Tong: %d\n", tong(8, 9));
    int n;
    printf("Nhap so nguyen n de tinh giai thua: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Khong tinh duoc giai thua so am!\n");
    else
        printf("Giai thua cua %d la: %d\n", n, giaithua(n));
    printf("Nhap so nguyen n de kiem tra so nguyen to: ");
    scanf("%d", &n);
    if (laNguyenTo(n))
        printf("%d la so nguyen to.\n", n);
    else
        printf("%d khong phai so nguyen to.\n", n);
    return 0;
}

