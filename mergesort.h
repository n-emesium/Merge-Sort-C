#ifndef __MERGESORT__
#define __MERGESORT__
#define MAX 100
#define mset(p, v, n) \
    for (int AAAAA = 0; AAAAA < n; AAAAA++) p[AAAAA] = v;
int verify (int *restrict arr, int *restrict arr2, int);
void gprint(int *restrict arr, int);
int check(int *restrict arr, int);
void merge(int *restrict arr, int, int, int);
void mergesort(int *restrict arr, int, int);
void sort(int *restrict arr, int);
void test(int (*p)());
#endif
