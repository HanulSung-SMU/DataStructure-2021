#include<stdio.h>
#define MAX_TERMS 13
struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {5,5}, {3,3}, {1,1}, {100,0}, {4,4}, {-3,3} ,{2,2}, {100,0} };
int avail = 8;

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%.2fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%.2fx^%d\n", terms[e].coef, terms[e].expon);
}

void attach(float coef, int expon)
{
	if (avail >= MAX_TERMS) {
		printf("항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float sum;
	*Cs = avail;
	while (As <= Ae && Bs <= Be) {
		if (terms[As].expon > terms[Bs].expon) {
			attach(terms[As].coef, terms[As].expon);
			As++;
		}
		else if (terms[As].expon == terms[Bs].expon) {
			sum = terms[As].coef + terms[Bs].coef;
			if (sum)
				attach(sum, terms[As].expon);
			As++; Bs++;
		}
		else {
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
		}
	}
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

int main(void)
{
	int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}