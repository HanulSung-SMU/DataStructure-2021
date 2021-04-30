#include<stdio.h>
typedef struct {								// stack에 대한 자료구조
	char* data;
	int top;
}Stack;

void init_stack(Stack* s, int len) {			// 스택 초기화, 데이터를 스택구조로 저장하기위해 배열형태를 사용 
	s->top = -1;
	s->data = (char*)malloc(sizeof(char) * len);// 데이타 메모리의 크기는 문자열 길이만큼으로 설정
}

int is_empty(Stack* s) {						// 스택이 비었는지 검사
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
	Stack* s = (Stack*)malloc(sizeof(Stack));	// 스택 생성
	int len = strlen(p);
	init_stack(s, len);
	char ch, open_ch;
	for (int i = 0; i < len; i++) {				// 문자열을 하나씩 검사하여 '(','{','['에대한 문자는 스택에 저장하고 후에 ')','}',']'와 짝을 맞춰본다
		ch = p[i];
		switch (ch) {
		case '(': case'[': case'{':				// '(','{','['에대한 문자는 스택에 저장
			push(s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(s)) {					// 닫힘괄호가 나왔는데 스택이 비어있을 경우
				return 0;
			}
			open_ch = pop(s);
			if (open_ch)
				if ((open_ch == '(' && ch != ')') ||	// 스택에서 pop한 문자('(','{','[')가 각각의 쌍(')','}',']')과 맞지 않는 경우 괄호검사 실패
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']')) {
					return 0;
				}
		}
	}
	if (is_empty(s))							//여전히 스택에 괄호가 남아있을 경우 괄호검사 실패
		return 1;
	else
		return 0;
}

int main() {
	char* p = "{{[[()]()]}}";
	if (check_matching(p) == 1)
		printf("%s 괄호검사성공 \n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;
}