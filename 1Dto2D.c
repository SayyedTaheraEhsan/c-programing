#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter the number of rows: ");
    int i; 
    scanf("%d", &i);

    printf("Enter the number of columns: ");
    int y; 
    scanf("%d", &y);

    int array[i][y];
    int rows, columns;
    int random;

    srand((unsigned)time(NULL));

    for(rows=0;rows<i;rows++)
        {
            for(columns=0;columns<y;columns++)
                {
                    random=rand()%100+1;

                    array[rows][columns] = random;
                    printf("%i\t",array[rows][columns]);
                }

            printf("\n");
        }

return 0;
}