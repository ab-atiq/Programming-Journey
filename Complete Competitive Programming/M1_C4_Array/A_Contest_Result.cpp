/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc290/tasks/abc290_a

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int total_points = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        total_points += a[x];
    }
    cout << total_points << endl;
    return 0;
}

// cps - array A, and B with 0 indexed solution
#include <stdio.h>

int main()
{

    int n, m;
    scanf("%d%d", &n, &m);

    int A[n], B[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        int ind = B[i] - 1;
        sum += A[ind];
    }

    printf("%d\n", sum);
    return 0;
}