/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc298/tasks/abc298_b

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int A[n + 1][n + 1], B[n + 1][n + 1], temp[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    int flag = 0;

    for (int k = 0; k < 4; k++)
    {
        int flag2 = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i][j] == 1 && B[i][j] == 0)
                {
                    flag2 = 0;
                }
            }
        }
        if (flag2 == 1)
        {
            flag = 1;
            break;
        }
        // rotate A
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                temp[i][j] = A[n + 1 - j][i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                A[i][j] = temp[i][j];
            }
        }
    }

    if (flag == 1)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

// chatgpt
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    bool possible = false;

    vector<vector<int>> rotated = A;

    for (int rotation = 0; rotation < 4; rotation++)
    {
        bool valid = true;
        for (int i = 0; i < N && valid; i++)
        {
            for (int j = 0; j < N && valid; j++)
            {
                if (rotated[i][j] == 1 && B[i][j] != 1)
                {
                    valid = false;
                }
            }
        }
        if (valid)
        {
            possible = true;
            break;
        }

        vector<vector<int>> next(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                next[j][N - 1 - i] = rotated[i][j];
            }
        }
        rotated = next;
    }

    cout << (possible ? "Yes\n" : "No\n");

    return 0;
}
