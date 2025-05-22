#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char maSV[10];
    char hoTen[50];
    float diem;
} SinhVien;
typedef struct Node {
    SinhVien data;
    struct Node *next;
} Node;
Node* taoNode(SinhVien sv) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}
void themCuoi(Node **head, SinhVien sv) {
    Node *newNode = taoNode(sv);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void inDanhSach(Node *head) {
    printf("\nDanh sach sinh vien:\n");
    while (head != NULL) {
        printf("MaSV: %s | Ho ten: %s | Diem: %.2f\n", head->data.maSV, head->data.hoTen, head->data.diem);
        head = head->next;
    }
}
void giaiPhong(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node *danhSach = NULL;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma SV: ");
        scanf("%s", sv.maSV);
        printf("Ho ten: ");
        scanf(" %[^\n]", sv.hoTen);
        printf("Diem: ");
        scanf("%f", &sv.diem);

        themCuoi(&danhSach, sv);
    }
    inDanhSach(danhSach);
    giaiPhong(danhSach);
    return 0;
}
