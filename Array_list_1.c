#include <stdio.h>
#include <stdlib.h>


#pragma warning(disable : 4996)
#define SIZE 100

//// 타입정의 -> int형을 element로 정의 ////
//// 타입 변경할 때 편하게 하기위해 ////
typedef int element;

typedef struct {
    element list[SIZE];            //배열
    int length;                    //현재 배열에 저장된 데이터 개수
}ArrayListType;

//// 배열 초기화
void init(ArrayListType* L)
{
    L->length = 0;
}

////배열이 비어있는지 확인
int is_empty(ArrayListType* L)
{
    return L->length == 0;
}
//리스트가 가득 차있으면 1, 그렇지 않으면 0 반환
int is_full(ArrayListType* L)
{
    return L->length == SIZE;
}
//리스트 데이터 출력
void display(ArrayListType* L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d-> ", L->list[i]);
    printf("\n");
}

// position : 삽입하고자 하는 위치 (인덱스값)
// item : 배열에 삽입할 데이터값
void AddInArrayList(ArrayListType* L, int position, element item)
{
    //배열이 가득 차있는지와 삽입할 인덱스 값 유효성 검사
    if (!is_full(L) && (position >= 0) && (position <= L->length))
    {
        int i;
        // for문으로 삽입하고자하는 위치와 그 뒤의 항목들을 1칸씩 뒤로(index+1) 이동시킴
        // i = 제일 끝에 있는 항목의 인덱스값;
        for (i = (L->length - 1); i >= position; i--)
            L->list[i + 1] = L->list[i];

        L->list[position] = item;
        //중요! 항목이 1개 늘었으니 length값 1증가
        L->length++;
    }
}

// 마지막에 추가
void AddInArrayList_last(ArrayListType* L,  element item)
{
    //배열이 가득 차있는지와 삽입할 인덱스 값 유효성 검사
    if (is_full(L)) {
        printf("리스트 오버플로우");
    }
    L->list[L->length++] = item;

}

// element타입인 이유는 삭제한 값을 반환시킬 때 이렇게 함수타입을 설정한다.
// position 삭제를 하고자 하는 위치(인덱스값)
element DelArrayList(ArrayListType* L, int position)
{
    int i;
    element item;        //삭제한 값을 담을 변수
    // position 값이 올바르면
    if ((position >= 0) && (position <= L->length - 1))
    {
        item = L->list[position];

        // i의 범위는 (position <= i <= length - 1)
        // 삭제한 인덱스의 뒤에 있던 항목들 앞으로 1칸씩 이동
        for (i = position; i < L->length; i++)
            L->list[i] = L->list[i + 1];

        // 삭제를 해서 항목이 1 감소했으니 length값 1 감소
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
    AddInArrayList_last(&list, 40); display(&list); //마지막에 추가

    DelArrayList(&list, 0); display(&list); //첫번째 항목 삭제
    return 0;


}
