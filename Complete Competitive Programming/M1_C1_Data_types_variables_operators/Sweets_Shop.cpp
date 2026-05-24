/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/SWEETSHOP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ini_money, laddus;
    scanf("%d%d", &ini_money, &laddus);
    int laddu_cost = laddus * 10;
    int rem_money = ini_money - laddu_cost;
    int total_jalebi = rem_money / 20;
    printf("%d\n", total_jalebi);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ini_money, laddus;
    scanf("%d%d", &ini_money, &laddus);
    printf("%d\n", (ini_money - (laddus * 10)) / 20);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    int rem = x - n * 10;
    printf("%d\n", rem / 20);
    return 0;
}