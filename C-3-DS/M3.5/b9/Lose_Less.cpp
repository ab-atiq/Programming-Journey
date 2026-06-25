// problem link: https://www.codechef.com/problems/LOSELESS

#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int match, point;
        cin >> match >> point;

        int minimumLoss;

        if (point <= match)
        {
            minimumLoss = match - point;
        }
        else
        {
            minimumLoss = (point - match) % 2;
        }

        cout << minimumLoss << endl;
    }

    return 0;
}