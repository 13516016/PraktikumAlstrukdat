#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdp.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
  return (First(L) == Nil) && (Last(L)==Nil);
};
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
  First(*L) = Nil;
  Last(*L) = Nil;
};
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
  address P = (address) malloc(1 * sizeof(ElmtList));

  if (P!=Nil){
    Info(P) = X;
    Next(P) = Nil;
    Prev(P) = Nil;
    return P;
  }
  else {
    return Nil;
  }
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
  free(P);
};
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
  address P;
  P = First(L);

  while(P!=Nil){
    if (Info(P)==X){
      return P;
    }
    P = Next(P);
  }

  return Nil;
};
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
  address P;
  address PIterate;

  P = Alokasi(X);

  if (!IsEmpty(*L)){
    Prev(First(*L)) = P;
    Next(P) = First(*L);
  }
  First(*L) = P;

  PIterate = First(*L);
  while (Next(PIterate)!=Nil) {
    PIterate = Next(PIterate);
  }
  Last(*L) = PIterate;
};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
  address PInsert;
  address PIterate;

  PInsert = Alokasi(X);

  PIterate = Last(*L);

  if (PInsert!=Nil){
    if (PIterate!=Nil){
      Next(PIterate) = PInsert;
      Prev(PInsert) = PIterate;
      Last(*L) = PInsert;
    }
    else {
      InsVFirst(L,X);
    }
  }

};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
  address PIterate;

  PIterate = First(*L);
  *X = Info(PIterate);

  if (First(*L)==Last(*L)){
    First(*L) = Nil;
    Last(*L) = Nil;
  }
  else {
    Prev(Next(PIterate)) = Nil;
    First(*L) = Next(PIterate);
  }

  Dealokasi(PIterate);
};
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
  address PIterate;

  PIterate = Last(*L);

  *X = Info(PIterate);

  if (First(*L)==Last(*L)){
    First(*L) = Nil;
    Last(*L) = Nil;
  }
  else {
    Next(Prev(PIterate)) = Nil;
    Last(*L) = Prev(PIterate);
  }

  Dealokasi(PIterate);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
  address PIterate;

  if (!IsEmpty(*L)){
    Next(P) = First(*L);
    Prev(First(*L)) = P;
  }
  First(*L) = P;

  while (Next(PIterate)!=Nil) {
    PIterate = Next(PIterate);
  }
  Last(*L) = PIterate;
};

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
  address PIterate;

  if (!IsEmpty(*L)) {
    PIterate = Last(*L);
    Next(PIterate) = P;
    Prev(P) = PIterate;
    Last(*L) = P;

  }
  else{
    First(*L) = P;
    Last(*L)=P;
  }

};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
  if (Prec == Last(*L)){
    Last(*L) = P;
  }
  else {
    Prev(Next(Prec)) = P;
  }

  Next(P) = Next(Prec);
  Next(Prec) = P;
  Prev(P) = Prec;


};
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
  if (Succ == First(*L)){
    First(*L) = P;
  }
  else{
    Next(Prev(Succ)) = P;
  }
  Next(P) = Succ;
  Prev(P) = Prev(Succ);
  Prev(Succ) = P;



};
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
  *P = First(*L);

  if (First(*L)==Last(*L)){
    First(*L) = Nil;
    Last(*L) = Nil;
  }
  else {
    Prev(Next(*P)) = Nil;
    First(*L) = Next(*P);
  }

};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
  *P = Last(*L);

  if (First(*L)==Last(*L)){
    First(*L) = Nil;
    Last(*L) = Nil;
  }
  else {
    Next(Prev(*P)) = Nil;
    Last(*L) = Prev(*P);
  }
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
  address PIterate;
  address PRec;

  PIterate = First(*L);
  PRec = Nil;

  if (Info(PIterate)==X){

    if (First(*L) == Last(*L)){
      First(*L) = Nil;
      Last(*L) = Nil;
    }

    else {
      First(*L) = Next(PIterate);
      Prev(Next(PIterate))=Nil;
    }

  }
  else{
    while ( (PIterate!=Nil) && (Info(PIterate)!=X)) {
      PRec = PIterate;
      PIterate = Next(PIterate);
    }

    if (PIterate!=Nil){

      if (PIterate == Last(*L)){
        Last(*L) = PRec;
        Next(PRec) = Nil;
      }

      else {
        Prev(Next(PIterate)) = PRec;
        Next(PRec) = Next(PIterate);
      }

    }
  }
  Dealokasi(PIterate);
};
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
  *Pdel = Next(Prec);

    if (*Pdel == Last(*L)){
      Last(*L) = Prec;
    }
    else {
      Prev(Next(*Pdel)) = Prec;
    }

  Next(Prec) = Next(*Pdel);
};
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
  *Pdel = Prev(Succ);

  if (*Pdel == First(*L)){
    First(*L) = Succ;
  }
  else {
    Next(Prev(*Pdel)) = Succ;
  }

  Prev(Succ) = Prev(*Pdel);
};
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
  address PIterate;
  PIterate = First(L);
  printf("[");
  while (PIterate!=Nil) {
    printf("%d",Info(PIterate));
    if (Next(PIterate)!=Nil){
      printf(",");
    }
    PIterate = Next(PIterate);
  }
  printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
  address PIterate;
  PIterate = Last(L);

  printf("[");
  while (PIterate!=Nil) {
    printf("%d",Info(PIterate));
    if (Prev(PIterate)!=Nil){
      printf(",");
    }
    PIterate = Prev(PIterate);
  }
  printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
