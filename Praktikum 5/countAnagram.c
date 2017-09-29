#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

int countChar( Kata mKata, char cChar){
  int i;
  int count = 0 ;

  for (i = 1; i <= mKata.Length; i++) {
    if (mKata.TabKata[i] == cChar){
      count++;
    }
  }
  return count;
}

boolean isAnagram(Kata kata1, Kata kata2){

  int i=1;
  boolean check = true;

  if (kata1.Length == kata2.Length){
    while (check && i<=kata1.Length) {
      if (countChar(kata1,kata1.TabKata[i]) != countChar(kata2,kata1.TabKata[i]) ){
        check = false;
      }
      else {
        i++;
      }
    }
    return check;
  }
  else {
    return false;
  }
}

void printKata(Kata mKata){
  int i;
  for (i = 1; i <= mKata.Length; i++) {
    printf("%c",mKata.TabKata[i]);
  }
}

void copyKata(Kata mKata, Kata * pasteKata){
  *pasteKata = mKata;
}

int main() {
  int i=1;
  Kata firstKata;
  int count =0;


  STARTKATA();
  if (!EndKata){
    copyKata(CKata,&firstKata);
    printKata(firstKata);
    printf(" - %d\n",firstKata.Length );
    ADVKATA();
    while (!EndKata){
      printKata(CKata);
      if (isAnagram(firstKata,CKata)){
        printf(" - Anagram dari ");printKata(firstKata);
        count++;
      }
      printf("\n");
      ADVKATA();
    }
  }

  printf("%d\n", count);

  return 0;
}
