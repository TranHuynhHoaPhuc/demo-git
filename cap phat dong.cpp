#include <stdio.h>
#include <stdlib.h> 
int main() {
    int *arr;
    int n, i, tong = 0;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    printf("Nhap %d phan tu:\n", n);
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        tong += arr[i];
    }
    printf("Tong cac phan tu la: %d\n", tong);
    free(arr);
    return 0;
}
