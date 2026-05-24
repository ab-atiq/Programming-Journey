/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc280/tasks/abc280_a

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

// solution 2 - using string
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    // string input and check directly
    // int cnt = 0;
    // for (int i = 0; i < h; i++)
    // {
    //     string s;
    //     cin >> s;
    //     for (int j = 0; j < w; j++)
    //     {
    //         if (s[j] == '#')
    //         {
    //             cnt++;
    //         }
    //     }
    // }

    // string store all rows then check
    string arr[h];
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int h, w;
    scanf("%d%d", &h, &w);

    char arr[h][w];

    char temp;
    scanf("%c", &temp); // to consume the newline character after reading integers

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        scanf("%c", &temp); // to consume the newline character after each row input
    }

    // print input array
    /*for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    */

    int ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == '#')
            {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}