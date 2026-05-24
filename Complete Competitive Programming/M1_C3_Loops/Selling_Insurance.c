/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/AGENTCHEF

#include <stdio.h>
#include <math.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int x_insurance_cost;
        scanf("%d", &x_insurance_cost);

        double per_insurance_comission = (x_insurance_cost * 20) / 100.0; // x_insurance_cost/5.0

        double total_insurance_sell = 100 / per_insurance_comission;

        // printf("%d\n", (int)ceil(total_insurance_sell)); // solution - 1
        // printf("%d\n", (int)(total_insurance_sell + 0.9999999)); // solution - 2

        // solution - 3
        double diff = total_insurance_sell - (int)total_insurance_sell;
        if (diff > 0.0)
            printf("%d\n", (int)total_insurance_sell + 1);
        else
            printf("%d\n", (int)total_insurance_sell);
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x;
        scanf("%d", &x);

        int ans = 500 / x; // x * 20% = x/5; 100(target) / (x/5) = 500/x

        if (500 % x != 0) // if there is a remainder after division, we need one more insurance. Or, we can say Ceil value.
        {
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}