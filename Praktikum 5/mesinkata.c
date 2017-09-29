#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){

  while ((CC==BLANK) && (CC!=MARK)){
    ADV();
  }
};
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){
  START();
  IgnoreBlank();
  if (CC == MARK) {
    EndKata = true;
  } else /* CC != MARK */ {
    EndKata = false;
    SalinKata();
  }
};
/* I.S. : CC sembarang
atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
   F.S. : EndKata = true, dan CC = MARK;
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
  IgnoreBlank();
  if (CC == MARK) {
    EndKata = true;
  } else /* CC != MARK */ {
    SalinKata();
  }
};
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
  int i = 1; /* inisialisasi */
/* Algoritma*/
  for (;;) {
    CKata.TabKata[i] = CC;
    ADV();
    if ((CC == MARK) || (CC == BLANK) || (i>=NMax)) {
      break;
      if (i>NMax){
        i--;
      }

    } else {
      i++;
    }
  } /* CC = MARK or CC = BLANK */
  CKata.Length = i;
  IgnoreBlank();
};
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
