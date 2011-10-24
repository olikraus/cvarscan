
/*
  variable length array, Sec. 6.7.5.2 (ISO 9899)
  gcc3 --> warning
  gcc4 --> ok
  [*] is variable length arry and is equivalent to []
  
  
  
*/

void fn(int x, char a[*]);

void fn(int x, char a[x])
{
}
