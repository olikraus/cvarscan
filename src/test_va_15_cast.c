
struct s { int m; };
typedef struct s * t;
void *p;

int main()
{
	return ((t)(int *)p)->m;
}
