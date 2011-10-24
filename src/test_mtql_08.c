/*  gcc -Wall -c -std=c99 test_mtql_08.c */

typedef int const * volatile * restrict t[3];
t * const * restrict * restrict a;

int const * volatile * restrict ( * const * restrict * restrict b)[3];

/*
int main(void)
{
	b = a;
}
*/