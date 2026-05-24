/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc328/tasks/abc328_b

/*
Idea:
A month i and a day j form a “repdigit date” iff:
- All digits in i are the same
    - All digits in j are the same
        - And day j exists (j ≤ D[i])

Examples of repdigits: 1, 2, 3, ..., 9, 11, 22, 33, ..., 99
(100 is NOT a repdigit because digits differ.)

Explanation (Short)

allSameDigits(x) → checks if all digits of the number x are identical.

For each month i:
 - Skip it if the month number is not a repdigit.
 - 1For each day j ≤ D[i], count it if the day is a repdigit.
*/

/*
#include <iostream>
using namespace std;

bool allSameDigits(int x, int last)
{
    while (x > 0)
    {
        if (x % 10 != last)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    int D[105];
    for (int i = 1; i <= N; i++)
        cin >> D[i];

    int count = 0;

    // Check each month i
    for (int i = 1; i <= N; i++)
    {
        int last = i % 10;
        if (!allSameDigits(i, last))
            continue; // month must be repdigit

        // Check each day j
        for (int j = 1; j <= D[i]; j++)
        {
            if (allSameDigits(j, last))
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
*/

// same same
#include <iostream>
using namespace std;

bool check_repdigit(int x, int last_dig)
{

    while (x > 0)
    {
        int rem = x % 10;
        if (rem != last_dig)
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    int month;
    cin >> month;
    int arr[month + 1];
    for (int i = 1; i <= month; i++)
    {
        cin >> arr[i];
    }
    // cout << check_repdigit(1) << endl;
    // cout << check_repdigit(9) << endl;
    // cout << check_repdigit(10) << endl;
    // cout << check_repdigit(11) << endl;
    // cout << check_repdigit(12) << endl;
    // cout << check_repdigit(19) << endl;
    // cout << check_repdigit(22) << endl;
    int cnt_rep_dig = 0;
    for (int i = 1; i <= month; i++)
    {
        int last_dig = i % 10;
        bool chk1 = check_repdigit(i, last_dig);
        // cout<<chk1<<endl;
        if (chk1)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                // cout << j << " ";
                if (check_repdigit(j, last_dig))
                {
                    // cout << i << " " << j << endl;
                    // if (i == j)
                    cnt_rep_dig++;
                }
            }
            // cout << endl;
        }
    }
    cout << cnt_rep_dig << endl;

    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            int flag = 1;
            int lastdigit = i % 10;
            int i2 = i;
            while (i2 != 0)
            {
                int lastnow = i2 % 10;
                if (lastnow != lastdigit)
                {
                    flag = 0;
                    break;
                }
                i2 /= 10;
            }

            int j2 = j;
            while (j2 != 0)
            {
                int lastnow = j2 % 10;
                if (lastnow != lastdigit)
                {
                    flag = 0;
                    break;
                }
                j2 /= 10;
            }
            if (flag == 1)
            {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}