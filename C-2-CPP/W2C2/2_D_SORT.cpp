/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.spoj.com/problems/SORT2D/en/

// custom comparator function for sorting the vector of pairs
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    // though sort function sorts in ascending order by default, if a is greater than b, then a should come after b in ascending order, so we return false to not swap or sort in ascending order
    if (a.first > b.first) // a.first is greater than b.first, then a should come after b in ascending order
    {
        return false; // false means do not swap or sort in ascending order
    }
    else if (a.first == b.first)
    {
        // if a.first and b.first are equal, then sort by second in descending order
        if (a.second < b.second) // a.second is smaller than b.second, then a should come after b in descending order
        {
            return false;
        }
    }
    return true; // true means swap or sort in ascending order for a.first and descending order for a.second
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n_pair;
        cin >> n_pair;
        vector<pair<int, int>> v(n_pair);
        for (int i = 0; i < n_pair; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), cmp);
        for (auto p : v)
        {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}

// solution using struct and custom comparator function
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y;
};

bool cmp(const Point &a, const Point &b)
{
    if (a.x != b.x)
        return a.x < b.x; // smaller x comes first
    return a.y > b.y;     // if same x, larger y comes first
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; i++)
        {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end(), cmp);

        for (auto &p : points)
        {
            cout << p.x << " " << p.y << "\n";
        }
    }
    return 0;
}
