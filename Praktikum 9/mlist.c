#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  infotype x=0;
  address P;
  List l1;
  List l2;
  List l3;


  CreateEmpty(&l1);
  CreateEmpty(&l2);
  CreateEmpty(&l3);

  printf("list1\n" );
  scanf("%d",&x );
  while (x!=0) {
    InsVLast(&l1,x);
    scanf("%d",&x );
  }
  //
  // scanf("%d",&x );
  // printf("list2\n" );
  // while (x!=0) {
  //   InsVLast(&l2,x);
  //   scanf("%d",&x );
  // }

  // Konkat1(&l1,&l2,&l3);
  P = Alokasi(3);
  x=3;
  // PrintInfo(l3);
  DelLast(&l1,&P);
  printf("%d\n",Info(P) );
  // DelAfter(&l,&P,First(l));
  PrintInfo(l1);
  // PrintInfo(l2);
  // PrintInfo(l3);

  return 0;
}
