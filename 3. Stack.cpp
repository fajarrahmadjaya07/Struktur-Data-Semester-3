#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void push(node **top, int value);
void pop(node **top);
void display(node *top);
int isEmpty(node *top);

int main() {
    node *top = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Push data / Tambah Awal\n");
        printf("2. Pop data / Hapus Awal\n");
        printf("3. Tampilkan stack\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1') {
            int value;
            printf("Masukkan data: ");
            scanf("%d", &value);
            push(&top, value);
        } else if (pilih == '2') {
            pop(&top);
        } else if (pilih == '3') {
            display(top);
            getchar();
            getchar();
        }

    } while (pilih != 'q');

    return 0;
}

void push(node **top, int value) {
    node *pNew = (node *)malloc(sizeof(node));
    if (pNew == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    pNew->data = value;
    pNew->next = *top;
    *top = pNew;
}

void pop(node **top) {
    if (isEmpty(*top)) {
        return;
    }
    node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

void display(node *top) {
    if (isEmpty(top)) {
        printf("Stack kosong\n");
        return;
    }
    printf("Isi stack: ");
    node *pWalker = top;
    while (pWalker != NULL) {
        printf("%d ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("\n");
}

int isEmpty(node *top) {
    return top == NULL;
}

