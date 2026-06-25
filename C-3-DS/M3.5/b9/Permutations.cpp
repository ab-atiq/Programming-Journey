// problem link: https://cses.fi/problemset/task/1070/

/*
Idea
    For n = 1, answer is 1.
    For n = 2 or n = 3, no beautiful permutation exists.
    For n >= 4, print all even numbers first, then all odd numbers.

Why does it work?
    Adjacent even numbers differ by at least 2.
    Adjacent odd numbers differ by at least 2.
    The boundary between the last even and first odd also never differs by 1 for n >= 4.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        // Print all even numbers first
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";

        // Print all odd numbers next
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
    }

    return 0;
}