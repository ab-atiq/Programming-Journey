/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc311/tasks/abc311_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n_people, d_days;
    cin >> n_people >> d_days;
    string people[n_people];
    for (int i = 0; i < n_people; i++)
    {
        cin >> people[i];
    }

    int max_consecutive_days = 0, cur_con_day = 0;
    for (int i = 0; i < d_days; i++)
    {
        int cnt_day = 0;
        bool is_consecutive = true;
        for (int p = 0; p < n_people; p++)
        {
            if (people[p][i] == 'o')
            {
                cnt_day++;
            }
            else
            {
                is_consecutive = false;
                cur_con_day = 0;
            }
        }
        if (cnt_day == n_people && is_consecutive)
        {
            cur_con_day++;
            max_consecutive_days = max(max_consecutive_days, cur_con_day);
        }
    }
    cout << max_consecutive_days << endl;
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n, d;
    scanf("%d%d", &n, &d);

    char arr[n][d];
    char temp;

    scanf("%c", &temp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        scanf("%c", &temp);
    }

    int free[d];

    for (int j = 0; j < d; j++)
    {
        int got = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == 'x')
            {
                got = 1;
                break;
            }
        }
        if (got == 1)
            free[j] = 0;
        else
            free[j] = 1;
    }

    int ans = 0;

    for (int j = 0; j < d; j++)
    {
        if (free[j] == 1)
        {
            int len = 1;
            for (int j2 = j + 1; j2 < d; j2++)
            {
                if (free[j2] == 1)
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            if (len > ans)
            {
                ans = len;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}