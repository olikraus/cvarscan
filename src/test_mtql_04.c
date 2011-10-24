const int aa[3];
const int bb = 3;

/* pointer auf array mit int */
const int (* const a)[3] = &aa;
/* array mit pointer auf int */
const int *  const b[3] = { &bb, &bb, &bb };

