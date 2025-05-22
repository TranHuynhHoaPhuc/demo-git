#include <stdio.h>

int main() {
//vd 1
    int a = 10;
    int *p = &a;
    printf("Gia tri cua a: %d, qua con tro: %d\n", a, *p);
//vd 2
    *p = 20;
    printf("Gia tri moi cua a sau khi thay doi qua con tro: %d\n", a);
//vd 3
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; 
    printf("Duyet mang qua con tro: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
