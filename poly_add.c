#include <stdio.h>

#define MAX_DEGREE 10
#define MAX(a,b)  (((a) > (b)) ? (a) : (b)) // a�� ũ�ٸ� a ��ȯ. �ƴϸ� b ��ȯ

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; // ���� �ʱ�ȭ 
	int degree_a = A.degree; // A ���׽� ���� ��� ���� 
	int degree_b = B.degree; // B ���׽� ���� ��� ���� 
	C.degree = MAX(A.degree, B.degree); // C ���׽��� ������ A�� B ���׽� �� �� ū ������ ���ϱ� 
	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
	{
		printf("%3.1f^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}
int main(void)
{
	polynomial a = { 5,{3, 6, 0, 0, 0, 10} };
	polynomial b = { 4,{7, 0, 5, 0, 1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("===========================================\n");
	print_poly(c);

	return 0;
}