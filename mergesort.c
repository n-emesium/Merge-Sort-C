#include <stdio.h>
#include "mergesort.h"
inline int verify(int *restrict arr, int *restrict arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr2[i]) {
            printf("arr1 element %d != arr2 element %d\n", arr[i], arr2[i]);
            return 0;
        }
    }
    return 1;
}
inline void gprint(int *restrict arr, int n) {
    putchar('\n');
    for (int i = 0; i < n; i++) printf("%d\t", arr[i]);
    putchar('\n');
}
inline int check(int *restrict arr, int n) {
    int x = n - 1;
    for (int i = 0; i < x; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("%d > %d\n", arr[i], arr[i + 1]);
            return 0;
        }
    }
    return 1;
}
void merge(int *restrict arr, int l, int m, int r) {
    int i = 0, j = 0, k = l, lleft = m - l + 1, rright = r - m;
    int larr[lleft], rarr[rright];
    for (int a = 0; a < lleft; a++) larr[a] = arr[l + a];
    for (int a = 0; a < rright; a++) rarr[a] = arr[m + 1 + a];
    while (i < lleft && j < rright) {
        if (larr[i] < rarr[j]) arr[k] = larr[i++];
        else arr[k] = rarr[j++];
        k++;
    }
    while (i < lleft) arr[k++] = larr[i++];
    while (j < rright) arr[k++] = rarr[j++];
}
inline void mergesort(int * restrict arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
inline void sort(int *restrict arr, int n) {mergesort(arr, 0, n - 1);}

void test(int (*random)()) {
    int n = random() % MAX;
    int arr[n];
    int charr[n], charr2[n];
    mset(charr, 0, n); mset(charr2, 0, n);
    for (int i = 0; i < n; i++) {
        int x = random() % n;
        arr[i] = x;
        charr[x]++;
    }
    puts("Before sorting:");
    gprint(arr, n);
    gprint(charr, n);
    puts("After sorting:");
    sort(arr, n);
    gprint(arr, n);
    gprint(charr2, n);
    for (int i = 0; i < n; i++) charr2[arr[i]]++;
    puts((check(arr, n) ? "Sorted" : "Not Sorted"));
    puts((verify(charr, charr2, n) ? "Not corrupted" : "Corrupted"));
}
