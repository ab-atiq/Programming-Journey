/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/BRUNCH

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int x_total_plates, y_per_person_plate;
        scanf("%d %d", &x_total_plates, &y_per_person_plate);
        int max_people = x_total_plates / y_per_person_plate;

        // maximum people 20
        // if (max_people > 20)
        //     max_people = 20;
        // printf("%d\n", max_people); // Output the maximum number of people who can be served

        if (max_people > 20)
        {
            printf("20\n");
        }
        else
        {
            printf("%d\n", max_people);
        }
    }
    return 0;
}