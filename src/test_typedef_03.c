/*
  nested overwrite of a typedef
  gcc -> ok
  prints values 1 and 4
*/

#include <stdio.h>

typedef char x;

int main(void)
{
  x y1;
  typedef int x;
  x y2;
  printf("%d %d\n", sizeof(y1), sizeof(y2) );
  return 0;
}
