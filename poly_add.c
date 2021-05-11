#include <stdio.h>

#define MAX_DEGREE 10
#define MAX(a,b)  (((a) > (b)) ? (a) : (b)) // a가 크다면 a 반환. 아니면 b 반환

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; // 변수 초기화 
	int degree_a = A.degree; // A 다항식 차수 멤버 접근 
	int degree_b = B.degree; // B 다항식 차수 멤버 접근 
	C.degree = MAX(A.degree, B.degree); // C 다항식의 차수는 A와 B 다항식 중 더 큰 차수로 정하기 
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