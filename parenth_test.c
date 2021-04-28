#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 20
char stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
	return (top == -1);
}

int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

void push(char c)
{
	if (is_full())
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = c;
}

char pop()
{
	if (is_empty())
	{
		fprintf(stderr,"���� ���� ����\n");
	}
	else
	{
		return stack[top--];
	}
}

int check_matching(const char* in)
{
	char ch, open_ch;
	int n = strlen(in);

	for (int i = 0; i < n; i++)
	{
		ch = in[i];
		switch (ch) {
		case'(' : case'[' : case'{':
			push(ch);
			break;
		case')' : case']': case'}':
			if (is_empty(stack))
			{
				return 0;
			}
			else
			{
				open_ch = pop(stack);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}'))
				{
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(stack)) // ������ ��� ���� ������ -> ���ÿ� ��ȣ�� ������
	{
		return 0; // ����
	}
	return 1;
}

int main(void)
{
	char* p = "{A[(i+1)]=0;}"; 

	if (check_matching(p) == 1)
	{
		printf("%s ��ȣ �˻� ����\n", p);
	}
	else
	{
		printf("%s ��ȣ �˻� ����\n", p);
	}
	return 0;
}