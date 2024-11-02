#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahNode(node **head);
void hapusNode(node **head);
void cariData(node *head);
void jumlahData(node *head);
void jumlahkanData(node *head);
void tranverse(node *head);

//========================================================

int main() {
    node *head = NULL;  
    char pilih;

    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. tambah Node\n");
        printf("2. hapus Node\n");
        printf("3. cari data\n");
        printf("4. jumlah data\n");
        printf("5. jumlahkan semua data\n");
        printf("c. cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf(" %c", &pilih);
        if (pilih == '1') {
            tambahNode(&head);
        } else if (pilih == '2') {
            hapusNode(&head);
        } else if (pilih == '3') {
            cariData(head);
        } else if (pilih == '4') {
            jumlahData(head);
        } else if (pilih == '5') {
            jumlahkanData(head);
        } else if (pilih == 'c') {
            tranverse(head);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================
void tambahNode(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = NULL;

    if (*head == NULL) { 
        *head = pNew;
        pNew->next = *head; 
    } else {
        pCur = *head;
        while (pCur->data != pos && pCur->next != *head) {
            pCur = pCur->next;
        }

        if (pCur->data != pos) {
            printf("\nnode tidak ditemukan");
            free(pNew);
            getch();
        } else {
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    }
}

//========================================================

void hapusNode(node **head) {
    int pos;
    node *pPre, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nmasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    if (*head == NULL) {
        printf("Tidak ada list\n");
        getch();
        return;
    }

    pPre = *head;
    pCur = (*head)->next;

    if (pPre->data == pos) {
        if (pCur == *head) { 
            free(*head);
            *head = NULL;
        } else {
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = (*head)->next; 
            free(*head);
            *head = pCur->next; 
        }
        printf("Data dihapus\n");
        getch();
        return;
    }

    while (pCur != *head && pCur->data != pos) {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur == *head) {
        printf("Data tidak ditemukan\n");
    } else {
        pPre->next = pCur->next;
        free(pCur);
        printf("Data dihapus\n");
    }
    getch();
}

//========================================================

void cariData(node *head) {
    int cari;
    node *pCur;
    int found = 0;

    system("cls");
    printf("masukkan data yang dicari: ");
    fflush(stdin);
    scanf("%d", &cari);

    pCur = head;
    if (pCur != NULL) {
        do {
            if (pCur->data == cari) {
                printf("%d Ditemukan\n", cari);
                found = 1;
                break;
            }
            pCur = pCur->next;
        } while (pCur != head);
    }

    if (!found) {
        printf("Data tidak ditemukan\n");
    }
    getch();
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    if (pCur != NULL) {
        do {
            count++;
            pCur = pCur->next;
        } while (pCur != head);
    }

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//========================================================

void jumlahkanData(node *head) {
    int total = 0;
    node *pCur = head;

    if (pCur != NULL) {
        do {
            total += pCur->data;
            pCur = pCur->next;
        } while (pCur != head);
    }

    printf("Penjumlahan semua data: %d\n", total);
    getch();
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    if (pWalker != NULL) {
        do {
            printf("%d\t", pWalker->data);
            pWalker = pWalker->next;
        } while (pWalker != head);
    }
    printf("NULL");
}
