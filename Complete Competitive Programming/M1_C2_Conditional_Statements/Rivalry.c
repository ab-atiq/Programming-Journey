/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/CPRIVAL
#include <stdio.h>
int main()
{
    int dominater_r, everule_r, D1, D2;
    scanf("%d %d %d %d", &dominater_r, &everule_r, &D1, &D2);
    int dom_final_rating = dominater_r + D1;
    int eve_final_rating = everule_r + D2;
    if (dom_final_rating > eve_final_rating)
    {
        printf("Dominater");
    }
    else if (eve_final_rating > dom_final_rating)
    {
        printf("Everule");
    }
    return 0;
}

// solution - 2
#include <stdio.h>

int main()
{

    int r1, r2, d1, d2;
    scanf("%d%d", &r1, &r2);
    scanf("%d%d", &d1, &d2);

    if (r1 + d1 > r2 + d2)
    {
        printf("Dominater\n");
    }
    else
    {
        printf("Everule\n");
    }

    return 0;
}