#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Helllooo" << endl;
    pair<int, int> p = {1, 2};
    pair<int, int> p2 = make_pair(2, 3);
    auto [id1, mark] = p;
    cout << id1 << mark << endl;

    tuple<string, int, int, string> t = make_tuple("atiq", 1, 12, "bozlu");
    auto [name, id, cls, father] = t;
    cout << name << id << cls << father << endl;
    cout << get<0>(t) << get<1>(t) << get<2>(t) << get<3>(t) << endl;

    pair<string, pair<int, string>> pp = {"abul", {1905004, "CSE"}};

    string name1 = pp.first;
    int id2 = pp.second.first;
    string sub = pp.second.second;
    cout << name1 << id2 << sub << endl;

    deque<int> dq;
    dq.push_back(50);
    dq.push_front(10);
    for (int n : dq)
    {
        cout << n << " ";
    }
    cout << endl;

    vector<vector<int>> vv(5, vector<int>(5, 5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}