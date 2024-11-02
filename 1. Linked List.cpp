#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

void hapusAwal(node **head);
void tambahAwal(node **head);
void tranverse(node *head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data \n");
     printf("2. hapus data awal \n");
     printf("3. hapus data tengah \n");
     printf("4. hapus data akhir \n");
     printf("c. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == 'c'){
     		tranverse(head);
         getch();
     }
     else if (pilih == '2')
			hapusAwal(&head);
     else if (pilih == '3')
			hapusTengah(&head);
     else if (pilih == '4')
			hapusAkhir(&head);

  } while (pilih != 'q');
  
  return 0;
}

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan kelamin (1 : laki-laki, 2 : perempuan) : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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
  free(pCur);
  printf("Data dihapus\n");
  getch();
}

//========================================================

//========================================================

void hapusTengah(node **head){
  int pos;
  node *pPre, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nmasukkan data yang ingin dihapus: ");
  fflush(stdin);
  scanf("%d", &pos);

  pPre = *head;
  if (pPre == NULL || pPre->next == NULL) {
    printf("Tidak ada list\n");
    getch();
    return;
  }

  while (pPre->next != NULL && pPre->next->data != pos) {
    pPre = pPre->next;
  }

  if (pPre->next == NULL) {
    printf("Data tidak ditemukan\n");
    getch();
  } else {
    pCur = pPre->next;
    pPre->next = pCur->next;
    free(pCur);
    printf("Data dihapus\n");
    getch();
  }
}

//========================================================

void hapusAkhir(node **head){
  node *pPre, *pCur;

  if (*head == NULL) {
    printf("Tidak ada list\n");
    getch();
    return;
  }

  pPre = *head;
  if (pPre->next == NULL) {
    free(pPre);
    *head = NULL;
  } else {
    while (pPre->next->next != NULL) {
      pPre = pPre->next;
    }
    pCur = pPre->next;
    pPre->next = NULL;
    free(pCur);
  }

  printf("Data dihapus\n");
  getch();
}

//========================================================



void tranverse(node *head){
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}

