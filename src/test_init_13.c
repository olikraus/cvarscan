/*  gcc -Wall -c -std=c99 test_mtql_06.c */
/* gcc bringt keine fehlermeldung bei der generierten object initalisierung ... */
typedef int * const * t[3];
volatile t * const * volatile * a[4];

