#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
  return (First(L) == Nil);
};
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
  First(*L) = Nil;
};
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

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
void Dealokasi (address *P){
  free(*P);
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
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
  address P;

  P = Alokasi(X);

  Next(P) = First(*L);
  First(*L) = P;

};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
  address PInsert;
  address PIterate;

  PInsert = Alokasi(X);

  PIterate = First(*L);

  if (PInsert!=Nil){
    if (PIterate!=Nil){
      while (Next(PIterate)!=Nil) {
        PIterate = Next(PIterate);
      }
      Next(PIterate) = PInsert;
    }
    else {
      InsVFirst(L,X);
    }
  }

}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
  address PIterate;

  PIterate = First(*L);

  *X = Info(PIterate);

  First(*L) = Next(PIterate);

  Dealokasi(&PIterate);


};
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
  address PIterate;
  address PRec;

  PIterate = First(*L);
  PRec = Nil;

  while(Next(PIterate)!=Nil){
    PRec = PIterate;
    PIterate = Next(PIterate);
  }

  *X = Info(PIterate);
  if (PRec == Nil){
    First(*L) = Nil;
  }
  else {
    Next(PRec) = Nil;
  }

  Dealokasi(&PIterate);


};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){

  Next(P) = First(*L);
  First(*L) = P;

};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
  Next(P) = Next(Prec);
  Next(Prec) = P;
};
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
  address PIterate;

  if (IsEmpty(*L)) {
    InsertFirst(L,P);
  }
  else{
    PIterate = First(*L);
    while (Next(PIterate)!=Nil) {
      PIterate = Next(PIterate);
    }

    Next(PIterate) = P;
  }

};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
  *P = First(*L);
  First(*L) = Next(*P);

};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
  address PIterate;
  address PRec;

  PIterate = First(*L);
  PRec = Nil;

  if (Info(PIterate)==X){
    First(*L) = Next(PIterate);
    Dealokasi(&PIterate);
  }
  else{
    while ( (PIterate!=Nil) && (Info(PIterate)!=X)) {
      PRec = PIterate;
      PIterate = Next(PIterate);
    }

    if (PIterate!=Nil){
      Next(PRec) = Next(Next(PRec));
      Dealokasi(&PIterate);
    }
  }

};
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
  address PIterate;
  address PRec;
  PIterate = First(*L);
  PRec = Nil;


  if (Next(PIterate)==Nil){
    *P = PIterate;
    PIterate = Nil;
    First(*L) = Nil;
  }
  else{

    while(Next(PIterate)!=Nil){
      PRec = PIterate;
      PIterate = Next(PIterate);
    }
    *P = PIterate;
    if (PRec != Nil){
      Next(PRec) = Nil;
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

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
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
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
  address PIterate;
  int sum = 0;
  PIterate = First(L);
  while (PIterate!=Nil) {
    sum++;
    PIterate = Next(PIterate);
  }
  return sum;

}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
  infotype currentMax;
  address PIterate;

  PIterate = First(L);
  currentMax = Info(PIterate);
  while (PIterate!=Nil) {
    if (currentMax < Info(PIterate)){
      currentMax = Info(PIterate);
    }
    PIterate = Next(PIterate);
  }

  return currentMax;
};
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
  address PIterate;

  PIterate = First(*L1);
  if (PIterate!=Nil){
    First(*L3) = First(*L1);
    while(Next(PIterate)!= Nil){
      PIterate = Next(PIterate);
    };
    Next(PIterate) = First(*L2);
  }
  else{
    First(*L3) = First(*L2);
  }

  First(*L1)=Nil;
  First(*L2)=Nil;

};
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
