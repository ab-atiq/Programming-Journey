/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc301/tasks/abc301_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int flag = 0;
    for (int i = 0; i < n - 1; i++) // before last element
    {
        int gap = arr[i + 1] - arr[i];
        if (gap < 0)
        {
            gap = gap * -1;
        }
        cout << arr[i] << " "; // all pair first element print
        // if (flag == 1)         // remaining elements just print - (my thinking wrong, because only next procedure skip not full loop)
        // {
        //     continue;
        // }
        // else if (gap == 1)
        if (gap == 1)
        {
            // flag = 1; // set flag
            continue;
        }
        else
        {
            int A = arr[i], B = arr[i + 1];

            if (A > B)
            {
                for (int j = A - 1; j > B; j--)
                {
                    cout << j << " ";
                }
            }
            else if (A < B)
            {
                for (int j = A + 1; j < B; j++)
                {
                    cout << j << " ";
                }
            }
        }
    }
    cout << arr[n - 1] << "\n"; // print last element

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            printf("%d ", arr[i]);
            for (int j = arr[i] + 1; j <= arr[i + 1] - 1; j++)
            {
                printf("%d ", j);
            }
        }
        else
        {
            printf("%d ", arr[i]);
            for (int j = arr[i] - 1; j >= arr[i + 1] + 1; j--)
            {
                printf("%d ", j);
            }
        }
    }
    printf("%d\n", arr[n - 1]);

    return 0;
}