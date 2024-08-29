
#include <stdio.h>

const int ARR_LEN = 10;

void swap(int a, int b, char* arr) {
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
}

void bubsort(char* n, int ln) {
    for (int j = 1; j<ln; j++) {
        for (int i = 0; i<ln-j; i++) {
            if (n[i] > n[i+1]) {
                swap(i, i+1, n);
            }
        }
    }
    return;
}

void mprint(char* n, int len) {
    for (int i = 0; i<len; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
    return;
}

int main() {
    printf("input array of %d numbers\n", ARR_LEN);
    char arr[ARR_LEN];
    for (int i = 0; i<ARR_LEN; i++) {
        printf("input %d-th number: ", i);
        scanf("%d", &arr[i]);
    }
    mprint(arr, ARR_LEN);
    bubsort(arr, ARR_LEN);
    mprint(arr, ARR_LEN);
    return 0;
}

