/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc330/tasks/abc330_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    long long int L, R;
    cin >> N >> L >> R;

    long long int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        long long int x = A[i]; // Initialize x with A[i] when l<=A[i]<=r
        if (x < L)              // If A[i] is less than L, set x to L
        {
            x = L;
        }
        else if (x > R) // If A[i] is greater than R, set x to R
        {
            x = R;
        }
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < l)
        {
            printf("%d ", l);
        }
        else if (l <= arr[i] && arr[i] <= r)
        {
            printf("%d ", arr[i]);
        }
        else
        {
            printf("%d ", r);
        }
    }
    printf("\n");

    return 0;
}