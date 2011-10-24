
typedef struct s1 *t1;
typedef struct s2 *t2;

struct s1 { t2 m2; };
struct s2 { t1 m1; };

t1 o;

