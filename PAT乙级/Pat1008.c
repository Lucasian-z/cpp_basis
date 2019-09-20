#include <stdio.h>
#include <stdlib.h>

void reverse(int *a, int left, int right)
{
    for(int i = left, j = right; i < j; ++i, --j)
    {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    getchar();//接收回车符
    int n, i;
    int *arr = (int *)calloc(N,sizeof(int));
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &n);
        arr[i] = n;
    }
    reverse(arr, 0, N-M-1);
    reverse(arr, N-M, N-1);
    reverse(arr, 0, N-1);
    i = 0;
    for(; i < N-1; ++i)
        printf("%d ", arr[i]);
    printf("%d", arr[i]);
    return 0;
}