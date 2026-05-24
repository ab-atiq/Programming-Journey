/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Hello world");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
