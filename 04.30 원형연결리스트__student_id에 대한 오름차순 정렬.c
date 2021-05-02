#include<stdio.h>
typedef struct ListNode {
	int student_id;
	int money;
	struct ListNode* link;
}ListNode;
ListNode* insert_last(ListNode* head, int id, int _money) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		printf("error");
		exit(1);
	}
	node->student_id = id;
	node->money = _money;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* insert_first(ListNode* head, int id, int _money) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		printf("error");
		exit(1);
	}
	node->student_id = id;
	node->money = _money;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
ListNode* search(ListNode* head, int id) {
	if (head == NULL) {
		printf("memory is empty\n");
		exit(1);
	}
	else {
		ListNode* tmp = head;
		for (ListNode* i = head->link; ;) {			// ���ڷ� �Ѿ�� id���� ū student_id�� ���� ��带 Ž���ϰ�
			if (i->student_id >= id)				// �߽߰� �ش� ��带 ����Ű�� ���� ��带 ��ȯ�Ѵ�.
				return tmp;							// ���� ���ڷ� �Ѿ�� id�� ���� ũ�ٸ� NULL��ȯ
			tmp = i;  i = i->link;
			if (i == head->link)
				break;
		}
		return NULL;
	}
}
ListNode* insert(ListNode* head, int id, int _money) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		printf("error");
		exit(1);
	}
	node->student_id = id; node->money = _money;
	if (head == NULL) {
		printf("�ƹ��͵� ������\n");
		insert_last(head, id, _money);
	}
	else {
		ListNode* tmp = search(head, id);
		if (tmp == NULL)
			insert_last(head, id, _money);			// id�� ���� Ŭ��
		else {
			if (tmp == head)
				insert_first(head, id, _money);		// id�� ���� ������
			else {
				node->link = tmp->link;				// id�� ���� ������ ũ���� ������
				tmp->link = node;
				return head;
			}
		}
	}
}
void print_list(ListNode* head) {
	if (head == NULL)
		printf("memory is empty\n");
	else {
		for (ListNode* i = head->link; 1;) {
			printf("%d : %d \n", i->student_id, i->money);
			i = i->link;
			if (i == head->link)
				break;
		}
	}
}
int main(void)
{
	ListNode* head = NULL;
	head = insert(head, 5, 5);
	head = insert(head, 3, 3);
	head = insert(head, 1, 1);
	head = insert(head, 4, 4);
	head = insert(head, 9, 9);
	head = insert(head, 8, 8);

	print_list(head);
	return 0;
}