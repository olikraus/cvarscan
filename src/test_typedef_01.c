/*
  does an typedef on a previous identifier;
  gcc --> syntax error
  'x' redeclared as different kind of symbol
*/

int x;
typedef char x;
x y;
