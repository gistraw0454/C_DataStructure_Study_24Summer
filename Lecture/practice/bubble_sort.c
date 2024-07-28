#include <stdio.h>

#define MAX 8

void print_arr(int list[]){
    for (int i=0; i<MAX;i++){
        printf("%d",list[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[]){
    for (int i = MAX-1; i>0; i--){
        for(int j=0;j<i;j++){
            int tmp=0;
            if (arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}


int main(){
    int arr[8]={5,6,3,1,8,7,9,0};
    printf("before: ");
    print_arr(arr);
    bubble_sort(arr);
    printf("after: ");
    print_arr(arr);
}

