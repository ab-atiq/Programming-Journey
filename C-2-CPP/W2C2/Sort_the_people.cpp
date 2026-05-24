/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://eolymp.com/en/problems/10263

#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<string> &a, const vector<string> &b)
{
    // surname sort lexicographically in ascending order. here, a[1] and b[1] are the surname of person a and person b respectively
    if (a[1] > b[1])
    {
        return false; // false means do not swap or sort in ascending order
    }
    else if (a[1] == b[1])
    {
        // name sort lexicographically in ascending order. here, a[0] and b[0] are the name of person a and person b respectively
        if (a[0] > b[0])
        {
            return false; // false means do not swap or sort in ascending order
        }
        else if (a[0] == b[0])
        {
            // age sort in descending order. here, a[2] and b[2] are the age of person a and person b respectively
            // since a[2] and b[2] are string, we need to convert them to integer before comparing
            int age_a = stoi(a[2]);
            int age_b = stoi(b[2]);
            if (age_a < age_b)
            {
                return false; // false means do not swap or sort in ascending order
            }
        }
    }
    return true; // true means swap or sort in ascending order
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<string>> people(n, vector<string>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> people[i][0] >> people[i][1] >> people[i][2];
    }

    sort(people.begin(), people.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << people[i][0] << " " << people[i][1] << " " << people[i][2] << "\n";
    }
    return 0;
}