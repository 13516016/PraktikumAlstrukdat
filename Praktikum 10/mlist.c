#include "listdp.h"
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
  P = Alokasi(9);
  // InsertAfter(&l1,P,First(l1));
  x=3;
  // InsertAfter(&l1,P,Next(First(l1)));
  // PrintInfo(l3);
  // DelLast(&l1,&P);
  // DelFirst(&l1,&P);
  // InsertLast(&l1,P);

  // DelVLast(&l1,&x);
  // InsVLast(&l1,2);
  // InsVFirst(&l1,2);
  DelBefore(&l1,&P,Last(l1));
  // InsertAfter(&l1,P,Prev(Last(l1)));
  // DelP(&l1,2);
  printf("%d\n",Info(P));
  // printf("%x\n",Search(l1,x));
  // printf("%x\n",x);
  // PrintBackward(l1);
  PrintForward(l1);
  PrintBackward(l1);
  // PrintInfo(l2);
  // PrintInfo(l3);

  return 0;
}
