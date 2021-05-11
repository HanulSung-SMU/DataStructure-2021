#include<stdio.h>
#define MAX_TERMS 101

struct poly
{
	float coef;
	int expon;
};

struct poly terms[MAX_TERMS] = { {8,5},{5,4},{2,3}, {7,1}, {1,0}, {10,3},{3,2},{1,0} };
int avail = 8;

char compare(int a, int b)
{
	if (a > b)
	{
		return '>';
	}
	else if (a < b)
	{
		return '<';
	}
	else
	{
		return '=';
	}
}

void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "항의 개수가 너무 많음\n");
		return;
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;

		case '<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;

		case '=':
			tempcoef = terms[As].coef + terms[Bs].coef;
			attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;
		}
	}
	for (; As <= Ae; As++)
	{
		attach(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++)
	{
		attach(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail-1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
	{
		printf("%3.1f^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f^%d\n", terms[e].coef, terms[e].expon);
}
int main(void)
{
	int As = 0, Ae = 4, Bs = 5, Be = 7, Cs, Ce;

	poly_add(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("=========================================================\n");
	print_poly(Cs, Ce);
	return 0;
}