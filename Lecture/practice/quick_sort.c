#include <stdio.h>

#define MAX 8

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int list[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void quick_sort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = start;
    int L = start + 1;
    int R = end;

    while (L <= R) {
        while (L <= end && arr[L] <= arr[pivot]) {
            L++;
        }
        while (R > start && arr[R] >= arr[pivot]) {
            R--;
        }
        if (L < R) {
            swap(&arr[L], &arr[R]);
        }
        else swap(&arr[pivot], &arr[R]);
    }
    

    quick_sort(arr, start, R - 1);
    quick_sort(arr, R + 1, end);
}

int main() {
    int arr[MAX] = {5, 6, 3, 1, 8, 7, 9, 0};
    printf("before: ");
    print_arr(arr);
    quick_sort(arr, 0, MAX - 1);
    printf("after: ");
    print_arr(arr);
}
