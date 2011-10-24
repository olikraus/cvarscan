/*  gcc -Wall -c -std=c99 test_mtql_06.c */

typedef int * const * restrict t;
volatile t * const * volatile * restrict a;

/*
int * const * restrict volatile * const * volatile * restrict b;

int main(void)
{
	b = a;
}
*/