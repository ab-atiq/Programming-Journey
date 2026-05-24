/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc307/tasks/abc307_a

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    // for (int t = 0; t < n; t++)
    while (n--)
    {
        int arr[7];
        for (int i = 0; i < 7; i++)
        {
            scanf("%d", &arr[i]);
        }
        // for (int i = 0; i < 7; i++)
        // {
        //     printf("%d ", arr[i]);
        // }
        int total_step = 0;
        for (int i = 0; i < 7; i++)
        {
            total_step += arr[i];
        }
        printf("%d ", total_step);
    }
    return 0;
}

// cpp solution - optimize
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[7 * N];
    for (int i = 0; i < 7 * N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        int weekly_sum = 0;
        for (int j = 0; j < 7; j++)
        {
            weekly_sum += A[i * 7 + j];
        }
        cout << weekly_sum << " ";
    }
    cout << endl;

    return 0;
}

// another solution
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int sum = 0, x;
        for (int i = 0; i < 7; i++)
        {
            cin >> x;
            sum += x;
        }
        cout << sum << " ";
    }
}