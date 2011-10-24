/*  gcc -Wall -c -std=c99 test_mtql_09.c */

typedef int const * volatile * restrict t[3];
t a[4];

int const * volatile * restrict b[4][3];

/*
int main(void)
{
	if ( &b == &a )
          return 0;
        return 1;
}
*/
