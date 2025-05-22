#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char maMon[10];
    char tenMon[50];
    float gia;
} MonAn;
typedef struct Node {
    MonAn data;
    struct Node *next;
} Node;
Node* taoNode(MonAn m) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = m;
    newNode->next = NULL;
    return newNode;
}
void themMonAn(Node **head, MonAn m) {
    Node *newNode = taoNode(m);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void hienThiDanhSach(Node *head) {
    printf("\n--- DANH SÁCH MÓN AN ---\n");
    while (head != NULL) {
        printf("Ma: %s | Ten: %s | Gia: %.2f VND\n",
               head->data.maMon, head->data.tenMon, head->data.gia);
        head = head->next;
    }
}
void timKiem(Node *head, char tenCanTim[]) {
    int found = 0;
    while (head != NULL) {
        if (strstr(head->data.tenMon, tenCanTim) != NULL) {
            printf("Tim thay: %s - %s - %.2f\n",
                   head->data.maMon, head->data.tenMon, head->data.gia);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("Khong tim thay mon an nao!\n");
}
void xoaMonAn(Node **head, char maXoa[]) {
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->data.maMon, maXoa) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay mon an co ma %s\n", maXoa);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Da xoa mon an co ma %s\n", maXoa);
}
void ghiFile(Node *head) {
    FILE *f = fopen("thucdon.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }
    while (head != NULL) {
        fprintf(f, "%s,%s,%.2f\n",
                head->data.maMon, head->data.tenMon, head->data.gia);
        head = head->next;
    }
    fclose(f);
    printf("Da ghi file thanh cong.\n");
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
    int chon;
    do {
        printf("\n===== MENU QUAN LY MON AN =====\n");
        printf("1. Them mon an moi\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Tim mon an theo ten\n");
        printf("4. Xoa mon an theo ma\n");
        printf("5. Ghi danh sach ra file\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar(); // Xóa ký t? '\n'
        if (chon == 1) {
            MonAn m;
            printf("Nhap ma mon: "); fgets(m.maMon, 10, stdin); m.maMon[strcspn(m.maMon, "\n")] = '\0';
            printf("Nhap ten mon: "); fgets(m.tenMon, 50, stdin); m.tenMon[strcspn(m.tenMon, "\n")] = '\0';
            printf("Nhap gia: "); scanf("%f", &m.gia);
            themMonAn(&danhSach, m);
        } else if (chon == 2) {
            hienThiDanhSach(danhSach);
        } else if (chon == 3) {
            char ten[50];
            printf("Nhap ten mon can tim: ");
            fgets(ten, 50, stdin); ten[strcspn(ten, "\n")] = '\0';
            timKiem(danhSach, ten);
        } else if (chon == 4) {
            char ma[10];
            printf("Nhap ma mon can xoa: ");
            fgets(ma, 10, stdin); ma[strcspn(ma, "\n")] = '\0';
            xoaMonAn(&danhSach, ma);
        } else if (chon == 5) {
            ghiFile(danhSach);
        }
    } while (chon != 0);
    giaiPhong(danhSach);
    return 0;
}
