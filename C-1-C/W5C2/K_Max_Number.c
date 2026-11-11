// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K



// https://github.com/phitronio/Conceptual-Sessions-Code/blob/main/Batch%209/C/Week_5%20Session_2/K_Max_Number.c
// link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K
#include <stdio.h>
#include <limits.h>

long long int max_v = LLONG_MIN;
void max_find(long long int arr[], int n, int idx)
{
    if (idx == n)
    {
        return;
    }
    max_find(arr, n, idx + 1);
    if (arr[idx] > max_v)
    {
        max_v = arr[idx];
    }
    // // for (int i = 0; i < n; i++)
    // // {
    // if (arr[i] > max_v)
    // {
    //     max_v = arr[i];
    // }
    // // }
}
int main()
{
    int n;
    scanf("%d", &n);

    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    // int max_v = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > max_v)
    //     {
    //         max_v = arr[i];
    //     }
    // }
    // printf("%d\n", max_v);

    // recursion function call
    max_find(arr, n, 0);
    printf("%d\n", max_v);
    return 0;
}

// https://github.com/phitronio/Conceptual-Sessions-Code/blob/main/Batch%209/C/Week_5%20Session_2/K_Max_Number_return_function.c

// link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/K
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
// long long int max_v = LLONG_MIN;
long long int max_find(long long int arr[], int n, int idx)
{
    if (idx == n)
    {
        return LLONG_MIN;
    }
    // if (idx == n - 1)
    // {
    //     return arr[idx];
    // }
    long long int temp_max = max_find(arr, n, idx + 1);
    // if (arr[idx] > temp_max)
    // {
    //     return arr[idx];
    // }
    // else
    // {
    //     return temp_max;
    // }
    // return temp_max;
    return fmax(arr[idx], temp_max);
}
int main()
{
    int n;
    scanf("%d", &n);

    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    // int max_v = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > max_v)
    //     {
    //         max_v = arr[i];
    //     }
    // }
    // printf("%d\n", max_v);

    // recursion function call
    long long int result = max_find(arr, n, 0);
    printf("%lld\n", result);
    return 0;
}

// method 1: solve depend on array index
#include <stdio.h>
#include <limits.h>

int findMax(int a[], int n, int i)
{
    if (i == n - 1) // if index is last item then that is return as max value
    {
        return a[i];
    }

    int max_rest = findMax(a, n, i + 1);
    if (a[i] > max_rest)
    {
        return a[i];
    }
    else
    {
        return max_rest;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max_value = findMax(a, n, 0);
    printf("%d\n", max_value);

    return 0;
}

/*
// method 1.1: solve depend on array index
#include <stdio.h>
#include <limits.h>

int findMax(int a[], int n, int i)
{
    if (i == n)
    {
        return INT_MIN; // Return the smallest possible integer when the array is exhausted/out of index
    }
    int max_rest = findMax(a, n, i + 1);
    return (a[i] > max_rest) ? a[i] : max_rest;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max_value = findMax(a, n, 0);
    printf("%d\n", max_value);

    return 0;
}
 */

/*
// method 2: solve depend on array size
#include <stdio.h>

long long int max(int arr[], int n)
{
    if (n == 1) // If the array has only one element, the maximum value is that element itself.
    {
        return arr[0];
    }

    // Compare the first element of the array with the maximum of the rest of the array (obtained by a recursive call). Return the larger of the two.
    long long int max_of_rest = max(arr + 1, n - 1);
    return (arr[n - 1] > max_of_rest) ? arr[n - 1] : max_of_rest;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long int res = max(arr, n);
    printf("%lld\n", res);
    return 0;
}
 */

/* // method 2.1: if else instead ternary
#include <stdio.h>

int findMax(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int max_rest = findMax(arr + 1, n - 1);
    if (arr[0] > max_rest)
    {
        return arr[0];
    }
    else
    {
        return max_rest;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findMax(arr, n));
    return 0;
} */

