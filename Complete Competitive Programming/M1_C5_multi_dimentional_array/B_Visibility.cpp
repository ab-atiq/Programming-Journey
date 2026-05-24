/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc197/tasks/abc197_b

// 0 index based solution
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    char arr[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];
        }
        cin.ignore(); // To ignore the newline character after each row input
    }
    // print the array
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
    int count = 0;
    // initial position count 1 if not obstacle
    if (arr[x - 1][y - 1] == '.')
    {
        count = 1;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
    // up direction count
    for (int i = x - 2; i >= 0; i--) // x-2 means one step up from current position
    {
        if (arr[i][y - 1] == '#')
        {
            break;
        }
        count++;
    }
    // down direction count
    for (int i = x; i < h; i++) // x means one step down from current position
    {
        if (arr[i][y - 1] == '#')
        {
            break;
        }
        count++;
    }
    // left direction count
    for (int j = y - 2; j >= 0; j--) // y-2 means one step left from current position
    {
        if (arr[x - 1][j] == '#')
        {
            break;
        }
        count++;
    }
    // right direction count
    for (int j = y; j < w; j++) // y means one step right from current position
    {
        if (arr[x - 1][j] == '#')
        {
            break;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}

// 1 index based solution
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    char arr[h + 1][w + 1];
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> arr[i][j];
        }
        cin.ignore(); // To ignore the newline character after each row input
    }
    int count = 0;
    // initial position count 1 if not obstacle
    if (arr[x][y] == '.')
    {
        count = 1;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
    // up direction count
    for (int i = x - 1; i >= 1; i--)
    {
        if (arr[i][y] == '#')
        {
            break;
        }
        count++;
    }
    // down direction count
    for (int i = x + 1; i <= h; i++)
    {
        if (arr[i][y] == '#')
        {
            break;
        }
        count++;
    }
    // left direction count
    for (int j = y - 1; j >= 1; j--)
    {
        if (arr[x][j] == '#')
        {
            break;
        }
        count++;
    }
    // right direction count
    for (int j = y + 1; j <= w; j++)
    {
        if (arr[x][j] == '#')
        {
            break;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int h, w, x, y;
    scanf("%d%d%d%d", &h, &w, &x, &y);
    x--, y--; // converting to 0 index based

    char arr[h][w];
    char temp;

    scanf("%c", &temp);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        scanf("%c", &temp);
    }

    int ans = 1;

    for (int j = y + 1; j < w; j++)
    {
        if (arr[x][j] == '.')
            ans++;
        else
        {
            break;
        }
    }

    for (int j = y - 1; j >= 0; j--)
    {
        if (arr[x][j] == '.')
            ans++;
        else
        {
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (arr[i][y] == '.')
            ans++;
        else
        {
            break;
        }
    }

    for (int i = x + 1; i < h; i++)
    {
        if (arr[i][y] == '.')
            ans++;
        else
        {
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}