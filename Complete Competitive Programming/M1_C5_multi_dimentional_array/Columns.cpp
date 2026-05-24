/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://eolymp.com/en/problems/2322

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int target, n;
    cin >> target >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int j = 0; j < n; j++) // column
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == target)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int x, n;
    scanf("%d%d", &x, &n);

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == x)
            {
                flag = 1;
            }
        }
        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}