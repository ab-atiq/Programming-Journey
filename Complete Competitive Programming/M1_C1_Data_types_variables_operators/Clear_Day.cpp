/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/CLEARDAY

#include <stdio.h>
int main()
{
    int rainy, cloudy, clear;
    scanf("%d%d", &rainy, &cloudy);
    clear = 7 - (rainy + cloudy);
    printf("%d\n", clear);
    return 0;
}