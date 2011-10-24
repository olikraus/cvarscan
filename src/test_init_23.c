/*  gcc -Wall -c -std=c99 test_mtql_06.c */
/* gcc bringt keine fehlermeldung bei der generierten object initalisierung ... */
typedef struct s { int *i; } **t;
t a[4];

