#include <stdio.h>
#include <stdlib.h>


#pragma warning(disable : 4996)
#define SIZE 100

//// Ÿ������ -> int���� element�� ���� ////
//// Ÿ�� ������ �� ���ϰ� �ϱ����� ////
typedef int element;

typedef struct {
    element list[SIZE];            //�迭
    int length;                    //���� �迭�� ����� ������ ����
}ArrayListType;

//// �迭 �ʱ�ȭ
void init(ArrayListType* L)
{
    L->length = 0;
}

////�迭�� ����ִ��� Ȯ��
int is_empty(ArrayListType* L)
{
    return L->length == 0;
}
//����Ʈ�� ���� �������� 1, �׷��� ������ 0 ��ȯ
int is_full(ArrayListType* L)
{
    return L->length == SIZE;
}
//����Ʈ ������ ���
void display(ArrayListType* L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d-> ", L->list[i]);
    printf("\n");
}

// position : �����ϰ��� �ϴ� ��ġ (�ε�����)
// item : �迭�� ������ �����Ͱ�
void AddInArrayList(ArrayListType* L, int position, element item)
{
    //�迭�� ���� ���ִ����� ������ �ε��� �� ��ȿ�� �˻�
    if (!is_full(L) && (position >= 0) && (position <= L->length))
    {
        int i;
        // for������ �����ϰ����ϴ� ��ġ�� �� ���� �׸���� 1ĭ�� �ڷ�(index+1) �̵���Ŵ
        // i = ���� ���� �ִ� �׸��� �ε�����;
        for (i = (L->length - 1); i >= position; i--)
            L->list[i + 1] = L->list[i];

        L->list[position] = item;
        //�߿�! �׸��� 1�� �þ����� length�� 1����
        L->length++;
    }
}

// �������� �߰�
void AddInArrayList_last(ArrayListType* L,  element item)
{
    //�迭�� ���� ���ִ����� ������ �ε��� �� ��ȿ�� �˻�
    if (is_full(L)) {
        printf("����Ʈ �����÷ο�");
    }
    L->list[L->length++] = item;

}

// elementŸ���� ������ ������ ���� ��ȯ��ų �� �̷��� �Լ�Ÿ���� �����Ѵ�.
// position ������ �ϰ��� �ϴ� ��ġ(�ε�����)
element DelArrayList(ArrayListType* L, int position)
{
    int i;
    element item;        //������ ���� ���� ����
    // position ���� �ùٸ���
    if ((position >= 0) && (position <= L->length - 1))
    {
        item = L->list[position];

        // i�� ������ (position <= i <= length - 1)
        // ������ �ε����� �ڿ� �ִ� �׸�� ������ 1ĭ�� �̵�
        for (i = position; i < L->length; i++)
            L->list[i] = L->list[i + 1];

        // ������ �ؼ� �׸��� 1 ���������� length�� 1 ����
        L->length--;
        return item;
    }
}

int main_0() {
    ArrayListType list;

    init(&list);
    AddInArrayList(&list, 0, 10); display(&list);
    AddInArrayList(&list, 0, 20); display(&list);
    AddInArrayList(&list, 0, 30); display(&list);
    AddInArrayList_last(&list, 40); display(&list); //�������� �߰�

    DelArrayList(&list, 0); display(&list); //ù��° �׸� ����
    return 0;


}
