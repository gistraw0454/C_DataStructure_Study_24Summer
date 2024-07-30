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

int update(int old_data,int new_data){
    NODE* tmp = head;
    while (tmp){
        if (tmp->data == old_data){
            tmp->data = new_data;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

//insert version1
int insert1(int index, int new_data){
    //1. 새노드 삽입
    NODE* new_node = init(new_data);

    //2. [0]에 삽입?
    if (index==0){
        new_node->next = head;
        head = new_node;
        return 1;
    }

    //3. 그렇지 않으면 탐색
    int cnt = 0;
    NODE* tmp = head;
    while(tmp){

        if (cnt +1==index){
            new_node->next = tmp->next;
            tmp->next = new_node;
            return 1;
        }

        ++cnt;
        tmp = tmp->next;
    }
}

int insert2(NODE** p,int new_data,int index){
    int cnt=0;
    while(cnt != index && *p !=NULL){
        p = &(*p)->next;
        cnt++;
    }
    if (cnt ==index){
        NODE* new_node = init(new_data);
        new_node->next = *p;
        *p = new_node;
        return 1;
    }
    return 0;
}

int remove1(NODE** parent, int data){
    //parent : 삭제할 노드의 앞 노드중, next의 주소 or head의 주소
    // 삭제할 노드의 주소가 있었던 곳의 주소

    if (*parent ==NULL){
        return 0;
    }
    if ((*parent)->data==data){
        //삭제
        NODE* target = *parent;
        *parent = target->next;
        free(target);
        return 1;
    }
    remove1(&(*parent)->next,data);  //다음 노드를 대상으로 remove재귀호출
}

int main(){
    add(&head,10);
    add(&head,20);
    add(&head,30);
    add(&head,40);
    add(&head,50);
    // if(update(20,300)){
    //     printf("수정완료\n");
    // }
    // else printf("수정실패\n");

    //insert version1
    // if(insert1(2,100)){   //10 20 100 30 40 50
    //     printf("삽입완료\n");
    // }
    // else printf("삽입실패\n");


    // //insert version2
    // if(insert3(&head,2,100)){   //10 20 100 30 40 50
    //     printf("삽입완료\n");
    // }
    // else printf("삽입실패\n");

    if(remove1(&head,20)){
        printf("삭제완료\n");
    }
    else printf("삭제실패\n");

    peek();
}