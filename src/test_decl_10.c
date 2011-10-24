
int a[5] = {1,2,3,4,5};
int c = 6;
int *b[5] = { &c, &c, &c, &c, &c }; /* array mit pointern auf int */
int (*d)[5] = &a; /* pointer auf array mit int */

