#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* head = NULL;


// 노드 생성 함수 : init()
NODE * init(int data){
    NODE* n = (NODE*)malloc(sizeof(NODE));  //malloc 자체의 리턴 자료형이 void* 로 지도 잘모른다는것으로. NODE*로 형변환
    n->data = data;
    n->next = NULL;
    return n;
}

//노드 생성 + 연결함수 : add()
void add(NODE** head_ptr, int data){
    // 1. head 자체가 NULL? (최초의 노드 생성)
    if (*head_ptr == NULL){
        *head_ptr = init(data);
        return;
    }
    add(&(*head_ptr)->next,data);
}

//데이터 조회 함수
void peek(){
    NODE* tmp = head;
    while (tmp){
        printf("%d \n",tmp->data);
        tmp = tmp->next;
    }
}

int main(){
    add(&head,10);
    add(&head,20);
    add(&head,30);
    peek();
}