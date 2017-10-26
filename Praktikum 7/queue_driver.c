#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"




int main(int argc, char const *argv[]) {
  Queue q;
  int input;
  int numberOfQueue;
  int top;
  int i;
  int max = 1;
  scanf("%d",&numberOfQueue );

  CreateEmpty(&q,numberOfQueue);

  for ( i = 0; i < numberOfQueue; i++) {
    scanf("%d",&input );
    Add(&q,input);
  }

  for ( i = 0; i < numberOfQueue; i++) {
    Del(&q,&top);

    printf("%d\n",top);
  }



  return 0;
}
