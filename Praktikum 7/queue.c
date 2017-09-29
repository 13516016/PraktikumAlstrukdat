#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

boolean IsEmpty (Queue Q){
  return ((Head(Q)==Nil) && (Tail(Q)==Nil));
};
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
  return (NBElmt(Q)==MaxEl(Q));
};
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q){

  if (IsEmpty(Q)) {

    return 0;
  } else {
    if (Tail(Q)>Head(Q)){
      return (Tail(Q)-Head(Q)+1);
    } else {
      return (MaxEl(Q)-Head(Q)+Tail(Q)+1);
    }
  }

};
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){

  (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  } else /* alokasi gagal */ {
    MaxEl(*Q) = 0;
  }

};
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
  MaxEl(*Q) = 0;
  free((*Q).T);
};
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
  if (IsEmpty(*Q)) {
  Head(*Q)=1;
  } else /* Q tidak kosong */ {
      if (Tail(*Q)==MaxEl(*Q)) { /* Geser elemen smp Head(Q)=1 */
        if (!IsFull(*Q)){
          Tail(*Q)=0;
        }
      }
  }
  Tail(*Q)++;
  InfoTail(*Q)=X;

};
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
  *X = InfoHead(*Q);
  if (Head(*Q)==Tail(*Q)) { /* Set mjd queue kosong */
    Head(*Q)=Nil; Tail(*Q)=Nil;
  }
  else {
    if (Head(*Q)==MaxEl(*Q)){
      if (!IsFull(*Q)) {
        Head(*Q)=Nil;
      }
    }
    Head(*Q)++;
}
};
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
