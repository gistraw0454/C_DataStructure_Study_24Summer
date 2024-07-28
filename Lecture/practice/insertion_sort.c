#include <stdio.h>

#define MAX 8

void print_arr(int list[]){
    for (int i=0; i<MAX;i++){
        printf("%d",list[i]);
    }
    printf("\n");
}

void insertion_sort(int list[]){
    for (int i=1; i<MAX;i++){
        
        int remember = list[i];

        int j=i-1;
        while(list[j] > remember && j >=0){  // j�� 0�̻��̰�, j�� ���Ұ� �ĺ����Һ��� Ŭ���� ��� j+1�� j���� �־���
            list[j+1] = list[j];
            j--;
        }

        //while(--j>=0 && list[j]>remember){
        //  list[j+1]=list[j];
        //}


        //for (j=i-1;j>=0&&list[j]>remember;--j)
        //  list[j+1] = list[j];

        list[j+1] = remember;
    }
}

int main(){
    int arr[8]={5,6,3,1,8,7,9,0};
    printf("before: ");
    print_arr(arr);
    insertion_sort(arr);
    printf("after: ");
    print_arr(arr);
}