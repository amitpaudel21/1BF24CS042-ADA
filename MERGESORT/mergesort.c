#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int left, int mid, int mid2, int right)
{
    int i = left;
    int j = mid2;
    int k = 0;
    int temp[60000];

    while(i <= mid && j <= right)
    {
        if(A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while(i <= mid)
        temp[k++] = A[i++];

    while(j <= right)
        temp[k++] = A[j++];

    for(i = left, k = 0; i <= right; i++, k++)
        A[i] = temp[k];
}

void merge_sort(int A[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);

        merge(A, left, mid, mid + 1, right);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    for(n = 10000; n <= 50000; n += 10000)
    {
        int A[n];

        for(i = 0; i < n; i++)
            A[i] = rand() % 10000;

        start = clock();

        merge_sort(A, 0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d \t Time = %.10f seconds\n", n, time_taken);
    }

    return 0;
}
