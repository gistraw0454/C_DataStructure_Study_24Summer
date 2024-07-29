#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define MAX 8
#define TRUE 1
#define FALSE 0
void stack_test01();
void stack_test02();

int push(int data);
int pop();

int arr[MAX] = { 0, }; // 원소들을 저장할 배열
int top = -1; // 가장 마지막 원소의 인덱스 (초기값 -1)

void main() {
	stack_test02(); 
}

int push(int data) {  
	if (top == MAX-1) { // top == 7
		printf("더이상 저장할 공간 없음!\n");
		return FALSE;
	}
	arr[++top] = data; 
	// ++top;
	// arr[top] = data;

	return TRUE;	//True False 가 큰 의미가 없긴함
}
int pop() {
	if (top < 0) {
		printf("꺼낼 데이터 없음!\n");
		return FALSE;
	}
	arr[top--] = 0;
	// arr[top] = 0
	// top--;
	return TRUE;
}
void print() {
	int i;
	for (i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void stack_test01() {
	push(4); 
	push(5); 
	push(1); 
	push(2);
	print(); // 4 5 1 2 0 0 0 0
	pop();   
	print(); // 4 5 1 0 0 0 0 0
	pop();
	print(); // 4 5 0 0 0 0 0 0
	pop();
	print(); // 4 0 0 0 0 0 0 0
	pop();
	print(); // 0 0 0 0 0 0 0 0
	pop();
	print();
}

void stack_test02() {
	int select = 0;
	int data;
	while (1) {
		printf("배열 : ");
		print();
		
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. exit \n입력 : ");
		scanf_s("%d", &select);
		switch (select) {
		case 1:
			printf("추가할 원소 : ");
			scanf_s("%d", &data);
			if(push(data))
				printf("추가 완료!\n");
			break;
		case 2:
			if (pop(data))
				printf("삭제 완료!\n");
			break;
		case 3:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		}
		getch();
		system("cls");
	}
}
