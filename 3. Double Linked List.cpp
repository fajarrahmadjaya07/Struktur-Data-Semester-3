#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void jumlahkanData(node *head);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do {
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("4. hapus data di awal\n");
     printf("5. hapus data di tengah\n");
     printf("6. hapus data di akhir\n");
     printf("7. cari data\n");
     printf("8. jumlah data\n");
     printf("9. jumlahkan semua data\n");
     printf("c. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
			tambahAkhir(&head);
     else if (pilih == 'c') {
     		tranverse(head);
         getch();
     }
     else if (pilih == '4')
			hapusAwal(&head);
     else if (pilih == '5')
			hapusTengah(&head);
     else if (pilih == '6')
			hapusAkhir(&head);
     else if (pilih == '7')
			cariData(head);
     else if (pilih == '8')
			jumlahData(head);
     else if (pilih == '9')
			jumlahkanData(head);
  } while (pilih != 'q');
  
  return 0;
}

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL) {
  	  pNew->data = bil;
      pNew->next = *head;
      pNew->prev = NULL;

      if (*head != NULL)
          (*head)->prev = pNew;
      
      *head = pNew;
  } else {
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
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

  pCur = *head;
  while (pCur != NULL && pCur->data != pos) {
    pCur = pCur->next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL) {
     printf("\nnode tidak ditemukan");
     getch();
  } else if (pNew == NULL) {
     printf("\nalokasi memori gagal");
     getch();
  } else {
     pNew->data = bil;
     pNew->next = pCur->next;
     pNew->prev = pCur;
     
     if (pCur->next != NULL) {
         pCur->next->prev = pNew;
     }
     
     pCur->next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head){
  int bil;
  node *pNew, *pCur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  
  pNew = (node *)malloc(sizeof(node));
  
  if (pNew != NULL) {
      pNew->data = bil;
      pNew->next = NULL;
      
      if (*head == NULL) {
          pNew->prev = NULL;
          *head = pNew; 
      } else {
          pCur = *head;
          while (pCur->next != NULL) {
              pCur = pCur->next;
          }
          pCur->next = pNew;
          pNew->prev = pCur;
      }
  } else {
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void hapusAwal(node **head){
  node *pCur;

  if (*head == NULL) {
    printf("Tidak ada list\n");
    getch();
    return;
  }

  pCur = *head;
  *head = (*head)->next;
  
  if (*head != NULL) {
      (*head)->prev = NULL;
  }

  free(pCur);
  printf("Data dihapus\n");
  getch();
}

//========================================================

void hapusTengah(node **head){
  int pos;
  node *pCur;

  system("cls");
  tranverse(*head);
  printf("\nmasukkan data yang ingin dihapus: ");
  fflush(stdin);
  scanf("%d", &pos);

  pCur = *head;
  while (pCur != NULL && pCur->data != pos) {
    pCur = pCur->next;
  }

  if (pCur == NULL) {
    printf("Data tidak ditemukan\n");
    getch();
  } else {
    if (pCur->prev != NULL) {
      pCur->prev->next = pCur->next;
    } else {
      *head = pCur->next;
    }

    if (pCur->next != NULL) {
      pCur->next->prev = pCur->prev;
    }

    free(pCur);
    printf("Data dihapus\n");
    getch();
  }
}

//========================================================

void hapusAkhir(node **head){
  node *pCur;

  if (*head == NULL) {
    printf("Tidak ada list\n");
    getch();
    return;
  }

  pCur = *head;
  
  if (pCur->next == NULL) {
    free(pCur);
    *head = NULL;
  } else {
    while (pCur->next != NULL) {
      pCur = pCur->next;
    }
    pCur->prev->next = NULL;
    free(pCur);
  }

  printf("Data dihapus\n");
  getch();
}

//========================================================

void cariData(node *head){
  int cari;
  node *pCur;
  int found = 0;

  system("cls");
  printf("masukkan data yang dicari: ");
  fflush(stdin);
  scanf("%d", &cari);

  pCur = head;
  while (pCur != NULL) {
    if (pCur->data == cari) {
      printf("%d Ditemukan\n", cari);
      found = 1;
      break;
    }
    pCur = pCur->next;
  }

  if (!found) {
    printf("Data tidak ditemukan\n");
  }
  getch();
}

//========================================================

void jumlahData(node *head){
  int count = 0;
  node *pCur = head;

  while (pCur != NULL) {
    count++;
    pCur = pCur->next;
  }

  printf("Jumlah data dalam list: %d\n", count);
  getch();
}

//========================================================

void jumlahkanData(node *head){
  int total = 0;
  node *pCur = head;

  while (pCur != NULL) {
    total += pCur->data;
    pCur = pCur->next;
  }

  printf("Penjumlahan semua data: %d\n", total);
  getch();
}

//========================================================

void tranverse(node *head){
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL) {
   		printf("%d\t", pWalker->data);
   		pWalker = pWalker->next;
        printf(" -> ");
	}
   printf("NULL\n");
}

