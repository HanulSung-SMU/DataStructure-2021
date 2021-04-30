#include <stdio.h>
#define MAX(x,y) x>y?x:y
#define MAX_DEGREE 101 

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial add(polynomial a, polynomial b) {
	polynomial c;
	int apos = 0, bpos = 0, cpos = 0;
	int a_degree = a.degree;
	int b_degree = b.degree;
	c.degree = MAX(a_degree, b_degree);

	while (a_degree >= 0 && b_degree >= 0) {
		if (a_degree > b_degree) {
			c.coef[cpos] = a.coef[apos];
			apos++, cpos++;
			a_degree--;
		}
		else if (a_degree == b_degree) {
			c.coef[cpos] = a.coef[apos] + b.coef[bpos];
			apos++, bpos++, cpos++;
			a_degree--, b_degree--;
		}
		else {
			c.coef[cpos] = b.coef[bpos];
			bpos++, cpos++;
			b_degree--;
		}
	}
	return c;
}
void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}
int main(void)
{
	polynomial a = { 6,{ 1, 2, 3, 4, 0, 0, 100} };
	polynomial b = { 5,{ 1, 2, 3, 4 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = add(a, b);
	printf("--------------------------------------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}