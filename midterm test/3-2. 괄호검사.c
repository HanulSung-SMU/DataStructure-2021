#include<stdio.h>
typedef struct {								// stack�� ���� �ڷᱸ��
	char* data;
	int top;
}Stack;

void init_stack(Stack* s, int len) {			// ���� �ʱ�ȭ, �����͸� ���ñ����� �����ϱ����� �迭���¸� ��� 
	s->top = -1;
	s->data = (char*)malloc(sizeof(char) * len);// ����Ÿ �޸��� ũ��� ���ڿ� ���̸�ŭ���� ����
}

int is_empty(Stack* s) {						// ������ ������� �˻�
	return s->top == -1;
}

void push(Stack* s, char c) {
	s->data[++(s->top)] = c;
}

int pop(Stack* s) {
	if (is_empty(s))
		printf("no data\n");
	else
		return s->data[(s->top)--];
}

int check_matching(char* p) {
	Stack* s = (Stack*)malloc(sizeof(Stack));	// ���� ����
	int len = strlen(p);
	init_stack(s, len);
	char ch, open_ch;
	for (int i = 0; i < len; i++) {				// ���ڿ��� �ϳ��� �˻��Ͽ� '(','{','['������ ���ڴ� ���ÿ� �����ϰ� �Ŀ� ')','}',']'�� ¦�� ���纻��
		ch = p[i];
		switch (ch) {
		case '(': case'[': case'{':				// '(','{','['������ ���ڴ� ���ÿ� ����
			push(s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(s)) {					// ������ȣ�� ���Դµ� ������ ������� ���
				return 0;
			}
			open_ch = pop(s);
			if (open_ch)
				if ((open_ch == '(' && ch != ')') ||	// ���ÿ��� pop�� ����('(','{','[')�� ������ ��(')','}',']')�� ���� �ʴ� ��� ��ȣ�˻� ����
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']')) {
					return 0;
				}
		}
	}
	if (is_empty(s))							//������ ���ÿ� ��ȣ�� �������� ��� ��ȣ�˻� ����
		return 1;
	else
		return 0;
}

int main() {
	char* p = "{{[[()]()]}}";
	if (check_matching(p) == 1)
		printf("%s ��ȣ�˻缺�� \n", p);
	else
		printf("%s ��ȣ�˻����\n", p);
	return 0;
}