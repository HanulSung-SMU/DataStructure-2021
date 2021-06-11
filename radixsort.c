#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define swap(a, b) {int temp; temp = a; a = b; b = temp;}

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *Link;
}ListNode;

ListNode *insert_last(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value; //동적 할당해준 p에 데이터에 입력받은 value 값을 넣어준다 
	if(head == NULL){ //헤드가 NULL이라면 
		head = p; //헤드는 p가 되고
		p->link = head; //링크는 헤드를 가리키게 된다
	}
	else{ //헤드가 NULL이 아니라면
		p->link = head->link; // 헤드의 링크가 가리키던 것을 p의 링크가 가리키게 하고 
		head->link = p; //헤드의 링크는 p를 가리키게 한다
		head = p; //그리고나서 헤드는 p가 된다
	}
    
    return head;
}


void radix_sort(int list[], int n){
	val = ?
	num_bucket = val % 10;
	switch(num_bucket)
	{
		case 0:
			head0 = insert_last(head0, val);
		case 1:
			head1 = insert_last(head1, val);
		case 2:
			head2 = insert_last(head2, val);
		case 3:
			head3 = insert_last(head3, val);
		case 4:
			head4 = insert_last(head4, val);
		case 5:
			head5 = insert_last(head5, val);
		case 6:
			head6 = insert_last(head6, val);
		case 7:
			head7 = insert_last(head7, val);
		case 8:
			head8 = insert_last(head8, val);
		case 9:
			head9 = insert_last(head9, val);
	}
	return;
}

void random_array(int list[])
{
	int i, ii;
	for(i = 0; i<SIZE; i++){
		list[i] = rand() % 10;
		for(ii = 0; ii < i; ii++){
			if(list[i] == list[ii]){
				i--;
				break;
			}
		}
	}
}

void arrayprint(int list[], int n){
	for(int i = 0; i < n; i++){
		printf("%d->",list[i]);
	}
	printf("\n");
}

int main(void){

	ListNode *head0 = NULL;
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	ListNode *head3 = NULL;
	ListNode *head4 = NULL;
	ListNode *head5 = NULL;
	ListNode *head6 = NULL;
	ListNode *head7 = NULL;
	ListNode *head8 = NULL;
	ListNode *head9 = NULL;
	
	int list[SIZE];
	srand(time(NULL));
	
	random_array(list);
	arrayprint(list, SIZE);
	printf("정렬 전\n");
	radix_sort(list, SIZE);
	printf("정렬 후\n");
	arrayprint(list, SIZE);
	
	return 0;
}
	
