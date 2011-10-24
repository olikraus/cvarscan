
struct s { int m; };
void *p;

int main()
{
	return ((struct s *)(int *)p)->m;
}
