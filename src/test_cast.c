
void *ptr;

typedef int a[10];
typedef a *b;

int main()
{
 return (*(int (*)[5][3])ptr)[9][2];
}


