/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc327/tasks/abc327_c

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

    int arr[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int flag = 1;

    for (int i = 0; i < 9; i++)
    {
        int freq[10];
        for (int j = 0; j < 10; j++)
        {
            freq[j] = 0;
        }
        for (int j = 0; j < 9; j++)
        {
            freq[arr[i][j]]++;
        }
        for (int j = 1; j <= 9; j++)
        {
            if (freq[j] != 1)
            {
                flag = 0;
                break;
            }
        }
    }

    for (int j = 0; j < 9; j++)
    {
        int freq[10];
        for (int i = 0; i < 10; i++)
        {
            freq[i] = 0;
        }
        for (int i = 0; i < 9; i++)
        {
            freq[arr[i][j]]++;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (freq[i] != 1)
            {
                flag = 0;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i % 3 == 0 && j % 3 == 0)
            {
                int freq[10];
                for (int k = 0; k < 10; k++)
                {
                    freq[k] = 0;
                }
                for (int i2 = i; i2 < i + 3; i2++)
                {
                    for (int j2 = j; j2 < j + 3; j2++)
                    {
                        freq[arr[i2][j2]]++;
                    }
                }
                for (int k = 1; k <= 9; k++)
                {
                    if (freq[k] != 1)
                    {
                        flag = 0;
                        break;
                    }
                }
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

bool checkNine(int counts[])
{
    for (int i = 1; i <= 9; i++)
    {
        if (counts[i] != 1)
            return false;
    }
    return true;
}

int main()
{
    int A[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> A[i][j];

    for (int i = 0; i < 9; i++)
    {
        int counts[10] = {0};
        for (int j = 0; j < 9; j++)
        {
            counts[A[i][j]]++;
        }
        if (!checkNine(counts))
        {
            cout << "No\n";
            return 0;
        }
    }

    for (int j = 0; j < 9; j++)
    {
        int counts[10] = {0};
        for (int i = 0; i < 9; i++)
        {
            counts[A[i][j]]++;
        }
        if (!checkNine(counts))
        {
            cout << "No\n";
            return 0;
        }
    }

    for (int block_i = 0; block_i < 3; block_i++)
    {
        for (int block_j = 0; block_j < 3; block_j++)
        {
            int counts[10] = {0};
            for (int i = block_i * 3; i < block_i * 3 + 3; i++)
            {
                for (int j = block_j * 3; j < block_j * 3 + 3; j++)
                {
                    counts[A[i][j]]++;
                }
            }
            if (!checkNine(counts))
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
