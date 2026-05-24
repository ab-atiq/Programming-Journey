/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc280/tasks/abc280_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // inverse prefix sum
    cout << A[0] << " ";
    for (int i = 1; i < n; i++)
    {
        cout << A[i] - A[i - 1] << " ";
    }
    return 0;
}

// make original array from input array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int S[N], A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    // inverse prefix sum
    A[0] = S[0];
    for (int i = 1; i < N; i++)
    {
        A[i] = S[i] - S[i - 1];
    }

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int s[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }

    int a[n + 1];

    a[1] = s[1];

    for (int i = 2; i <= n; i++)
    {
        a[i] = s[i] - s[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}