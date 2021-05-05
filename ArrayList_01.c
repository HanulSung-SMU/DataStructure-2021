#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

int error(char* message) // 오류 출력 함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) // 리스트 초기화 함수
{
	L->size = 0; // 0으로 초기화
}

int is_empty(ArrayListType* L) // 리스트 공백 검출 함수
{
	return L->size == 0; // 리스트가 비어 있으면 1, 아니면 0 반환
}

int is_full(ArrayListType* L) // 리스트 포화 검출 함수
{
	return L->size == MAX_LIST_SIZE; // 리스트가 가득 차 있으면 1, 아니면 0 반환
}

element get_entry(ArrayListType* L, int pos) // pos 위치의 요소 반환하는 함수
{
	if (pos < 0 || pos >= L->size) error("위치 설정 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L) // 리스트 출력 함수
{
	for (int i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

void insert(ArrayListType* L, int pos, element item) // 리스트의 특정 위치에 항목을 추가하는 함수
{
	if (is_full(L)) error("포화 상태 오류"); // 포화 상태일 경우 오류 출력
	else {
		if (pos <= L->size && pos >= 0) { // pos 값이 0과 size 사이일 경우
			for (int i = L->size - 1; i >= pos; i--) { // pos 위치를 비우기 위해 한 칸씩 이동
				L->array[i + 1] = L->array[i];
			}
			L->array[pos] = item; 
			L->size++; // pos 위치에 item 삽입 후 size + 1
		}
		else error("위치 설정 오류"); // 위치 설정이 잘못되었을 경우 오류 출력
	}
}

void insert_last(ArrayListType* L, element item) // 리스트 맨 끝에 항목을 추가하는 함수
{
	if (is_full(L)) error("포화 상태 오류");
	else {
		L->array[L->size++] = item; // 현재 size 위치에 item을 삽입하고 size + 1
	}
}

void insert_first(ArrayListType* L, element item) // 리스트 맨 처음에 항목을 추가하는 함수
{
	if (is_empty(L)) error("공백 상태 오류"); // 포화 상태일 경우 오류 출력
	else {
		for (int i = L->size - 1; i >= 0; i--) { 
			L->array[i + 1] = L->array[i]; // 모든 값의 위치를 한 칸씩 이동
		}
		L->array[0] = item;
		L->size++; // 맨 처음 위치에 item을 삽입하고 size + 1
	}
}

element delete(ArrayListType* L, int pos) // 리스트의 항목을 삭제하는 함수
{
	element item;
	if (pos < 0 || pos >= L->size) error("위치 설정 오류"); 
	item = L->array[pos]; // pos 위치에 있는 값을 item 변수에 저장
	for (int i = pos; i < (L->size - 1); i++) { 
		L->array[i] = L->array[i + 1];
	}
	L->size--; // 리스트의 값들을 한 칸씩 옮기고 size - 1
	return item; // 삭제한 항목 반환
}

int main(void)
{
	// ArrayListType를 정적으로 생성하고 ArrayListType를
	// 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;
	init(&list);
	insert(&list, 0, 10); print_list(&list); // 0번째 위치에 10 추가
	insert(&list, 0, 20); print_list(&list); // 0번째 위치에 20 추가
	insert(&list, 0, 30); print_list(&list); // 0번째 위치에 30 추가
	insert_last(&list, 40); print_list(&list); // 맨 끝에 40 추가
	insert_first(&list, 50); print_list(&list); // 맨 앞에 50 추가
	delete(&list, 0); print_list(&list); // 0번째 항목 삭제
	return 0;
}