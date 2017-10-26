#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
  return (First(L)==Nil);
};
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
  First(*L) = Nil;
};
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
  address P = (address) malloc(1 * sizeof(ElmtList));

  if (P!=Nil){
    Info(P) = X;
    Next(P) = Nil;
    return P;
  }
  else {
    return P;
  }

};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
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

  if (Info(P)==X){
    return P;
  }
  else{
    P = Next(P);
    while(P!=First(L)){
      if (Info(P)==X){
        return P;
      }
      P = Next(P);
    }
  }

  return Nil;
};

/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
  address P;
  address PIterate;

  P = Alokasi(X);

  if (!IsEmpty(*L)){

    PIterate = First(*L);
    Next(P) = First(*L);

    while(Next(PIterate)!=First(*L)){
      PIterate = Next(PIterate);
    }
    First(*L) = P;
    Next(PIterate) = First(*L);

  }
  else{
    First(*L) = P;
    Next(P) = First(*L);
  }

};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
  address PIterate;
  address PInsert;

  PInsert = Alokasi(X);

  PIterate = First(*L);

  if (PInsert!=Nil){
    if (PIterate!=Nil){
      while (Next(PIterate)!=First(*L)) {
        PIterate = Next(PIterate);
      }
      Next(PInsert) = First(*L);
      Next(PIterate) = PInsert;
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
void DelVFirst (List *L, infotype * X){
  address PIterate;
  address PFirst;

  PFirst = First(*L);
  PIterate = First(*L);

  *X = Info(PFirst);

  if (Next(PIterate)==First(*L)){
    First(*L)=Nil;
  }
  else{
    while (Next(PIterate)!=First(*L)) {
      PIterate = Next(PIterate);
    }

    First(*L) = Next(PFirst);
    Next(PIterate) = First(*L);
  }

  Dealokasi(PFirst);
};
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
  address PIterate;
  address PRec;

  PIterate = First(*L);
  PRec = Nil;

  while(Next(PIterate)!=First(*L)){
    PRec = PIterate;
    PIterate = Next(PIterate);
  }

  *X = Info(PIterate);
  if (PRec == Nil){
    First(*L) = Nil;
  }
  else {
    Next(PRec) = First(*L);
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


  if(IsEmpty(*L)){
    First(*L) = P;
    Next(P) = First(*L);
  }
  else {
    PIterate = First(*L);


    while (Next(PIterate)!=First(*L)) {
      PIterate = Next(PIterate);
    }
    Next(P) = First(*L);
    First(*L) = P;
    Next(PIterate) = P;
  }



};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
  address PIterate;

  if (IsEmpty(*L)) {
    InsertFirst(L,P);
  }
  else{
    PIterate = First(*L);
    while (Next(PIterate)!=First(*L)) {
      PIterate = Next(PIterate);
    }

    Next(PIterate) = P;
    Next(P) = First(*L);
  }

};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
  Next(P) = Next(Prec);
  Next(Prec) = P;
};
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
  address PIterate;
  PIterate = First(*L);
  *P = First(*L);

  if (Next(PIterate) == First(*L)){
    First(*L) = Nil;
  }
  else {

    while (Next(PIterate)!=First(*L)) {
      PIterate = Next(PIterate);
    }


    First(*L) = Next(First(*L));

    Next(PIterate) = First(*L);
  }
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
  address PIterate;
  address PRec;
  PIterate = First(*L);
  PRec = Nil;

  if (Next(PIterate)==First(*L)){
    *P = PIterate;
    PIterate = Nil;
    First(*L) = Nil;
  }
  else{
    while(Next(PIterate)!=First(*L)){
      PRec = PIterate;
      PIterate = Next(PIterate);
    }
    *P = PIterate;
    if (PRec != Nil){
      Next(PRec) = First(*L);
    }
  }

};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
  address PIterate;
  PIterate = First(*L);

  while (PIterate!= Prec) {
    PIterate = Next(PIterate);
  }
  *Pdel = Next(Prec);

  Next(Prec) = Next(Next(Prec));

};
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
  address PIterate;
  address PRec;

  PIterate = First(*L);
  PRec = Nil;

  if (Info(PIterate)==X){
    if (Next(PIterate) == First(*L)){
      First(*L) = Nil;
    }
    else {
      while (Next(PIterate)!=First(*L)) {
        PIterate = Next(PIterate);
      }
      Dealokasi(First(*L));
      First(*L) = Next(First(*L));
      Next(PIterate) = First(*L);
    }
  }
  else{
    PRec = PIterate;
    PIterate = Next(PIterate);

    while ( (PIterate!=First(*L)) && (Info(PIterate)!=X)) {
      PRec = PIterate;
      PIterate = Next(PIterate);
    }

    if (PIterate!=First(*L)){
      Next(PRec) = Next(Next(PRec));
      Dealokasi(PIterate);
    }
  }

};
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
  address PIterate;
  PIterate = First(L);

  printf("[");

    if (!IsEmpty(L)){
      printf("%d",Info(PIterate));
      if (Next(PIterate)!=First(L)){
        printf(",");
      }
      PIterate = Next(PIterate);

      while (PIterate != First(L)) {
        printf("%d",Info(PIterate));
        if (Next(PIterate)!=First(L)){
          printf(",");
        }
        PIterate = Next(PIterate);
      }
    }

  printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
