/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc328/tasks/abc328_a

#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tem;
        scanf("%d", &tem);
        // sum of x or less value
        if (tem <= x) // if (tem >= 100 && tem <= x)
        {
            sum += tem;
        }
    }
    printf("%d\n", sum);
    return 0;
}

// using array
#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // sum of x or less value
        if (arr[i] <= x)
        {
            sum += arr[i];
        }
    }
    printf("%d\n", sum);
    return 0;
}

// cps
#include <stdio.h>

int main(){
    int n, x;
    scanf("%d %d", &n, &x);

    int sum = 0;

    for(int i = 1; i <= n; i++){
        int s;
        scanf("%d", &s);

        if(s <= x){
            sum += s;
        }
    }

    printf("%d\n", sum);

    return 0;
}