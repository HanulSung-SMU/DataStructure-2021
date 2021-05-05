#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

int error(char* message) // ���� ��� �Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L) // ����Ʈ �ʱ�ȭ �Լ�
{
	L->size = 0; // 0���� �ʱ�ȭ
}

int is_empty(ArrayListType* L) // ����Ʈ ���� ���� �Լ�
{
	return L->size == 0; // ����Ʈ�� ��� ������ 1, �ƴϸ� 0 ��ȯ
}

int is_full(ArrayListType* L) // ����Ʈ ��ȭ ���� �Լ�
{
	return L->size == MAX_LIST_SIZE; // ����Ʈ�� ���� �� ������ 1, �ƴϸ� 0 ��ȯ
}

element get_entry(ArrayListType* L, int pos) // pos ��ġ�� ��� ��ȯ�ϴ� �Լ�
{
	if (pos < 0 || pos >= L->size) error("��ġ ���� ����");
	return L->array[pos];
}

void print_list(ArrayListType* L) // ����Ʈ ��� �Լ�
{
	for (int i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

void insert(ArrayListType* L, int pos, element item) // ����Ʈ�� Ư�� ��ġ�� �׸��� �߰��ϴ� �Լ�
{
	if (is_full(L)) error("��ȭ ���� ����"); // ��ȭ ������ ��� ���� ���
	else {
		if (pos <= L->size && pos >= 0) { // pos ���� 0�� size ������ ���
			for (int i = L->size - 1; i >= pos; i--) { // pos ��ġ�� ���� ���� �� ĭ�� �̵�
				L->array[i + 1] = L->array[i];
			}
			L->array[pos] = item; 
			L->size++; // pos ��ġ�� item ���� �� size + 1
		}
		else error("��ġ ���� ����"); // ��ġ ������ �߸��Ǿ��� ��� ���� ���
	}
}

void insert_last(ArrayListType* L, element item) // ����Ʈ �� ���� �׸��� �߰��ϴ� �Լ�
{
	if (is_full(L)) error("��ȭ ���� ����");
	else {
		L->array[L->size++] = item; // ���� size ��ġ�� item�� �����ϰ� size + 1
	}
}

void insert_first(ArrayListType* L, element item) // ����Ʈ �� ó���� �׸��� �߰��ϴ� �Լ�
{
	if (is_empty(L)) error("���� ���� ����"); // ��ȭ ������ ��� ���� ���
	else {
		for (int i = L->size - 1; i >= 0; i--) { 
			L->array[i + 1] = L->array[i]; // ��� ���� ��ġ�� �� ĭ�� �̵�
		}
		L->array[0] = item;
		L->size++; // �� ó�� ��ġ�� item�� �����ϰ� size + 1
	}
}

element delete(ArrayListType* L, int pos) // ����Ʈ�� �׸��� �����ϴ� �Լ�
{
	element item;
	if (pos < 0 || pos >= L->size) error("��ġ ���� ����"); 
	item = L->array[pos]; // pos ��ġ�� �ִ� ���� item ������ ����
	for (int i = pos; i < (L->size - 1); i++) { 
		L->array[i] = L->array[i + 1];
	}
	L->size--; // ����Ʈ�� ������ �� ĭ�� �ű�� size - 1
	return item; // ������ �׸� ��ȯ
}

int main(void)
{
	// ArrayListType�� �������� �����ϰ� ArrayListType��
	// ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	ArrayListType list;
	init(&list);
	insert(&list, 0, 10); print_list(&list); // 0��° ��ġ�� 10 �߰�
	insert(&list, 0, 20); print_list(&list); // 0��° ��ġ�� 20 �߰�
	insert(&list, 0, 30); print_list(&list); // 0��° ��ġ�� 30 �߰�
	insert_last(&list, 40); print_list(&list); // �� ���� 40 �߰�
	insert_first(&list, 50); print_list(&list); // �� �տ� 50 �߰�
	delete(&list, 0); print_list(&list); // 0��° �׸� ����
	return 0;
}