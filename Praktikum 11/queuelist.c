#include "boolean.h"
#include "queuelist.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
  *P = (address) malloc(1 * sizeof(ElmtQueue));

  if (P!=Nil){
    Info(*P) = X;
    Next(*P) = Nil;
  }

};
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
  free(P);
};
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q){
  return (Head(Q)==Nil && Tail(Q)==Nil);
};
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
  address PIterate;
  int sum = 0;
  PIterate = Head(Q);
  while (PIterate!=Nil) {
    sum++;
    PIterate = Next(PIterate);
  }
  return sum;
};
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
};
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X){
  address PInsert;
  address PIterate;

  Alokasi(&PInsert,X);

  PIterate = Tail(*Q);

  if (PInsert!=Nil){
    if (PIterate!=Nil){
      Next(PIterate) = PInsert;
      Tail(*Q) = PInsert;
    }
    else {
      Head(*Q) = PInsert;
      Tail(*Q) = PInsert;
    }
  }
};
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Del(Queue * Q, infotype * X){
  address PIterate;

  PIterate = Head(*Q);

  *X = Info(PIterate);


  Head(*Q) = Next(PIterate);
  if (Next(PIterate)==Nil){
      Tail(*Q) = Nil;
  }
  Dealokasi(PIterate);
};
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
