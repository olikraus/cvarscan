/*
  typedef of variable size arrays
  gcc3 -> ok, but wrong results
  gcc4 -> ok
  prints values 1 and 4
*/

#include <stdio.h>

void copyt(int n)
{
  int i;
  typedef int B[n]; // B is n ints, n evaluated now
  n += 4;
  B a; // ais n ints, n without += 1
  int b[n]; // a and b are different sizes
  for (i = 1; i < n; i++)
    a[i-1] = b[i];
  printf("%d\n", sizeof(a));
  printf("%d\n", sizeof(b));
}

int main(void)
{
    copyt(2);
    copyt(7);
    return 0;
}

