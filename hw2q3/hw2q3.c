/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*=========================================================================
  Constants and definitions:
==========================================================================*/

#define N 1000

void print_welcome_message();
void print_welcome_message2();
void print_not_enough();
void print_too_many();
void print_field(char field[N][N], int len, int wid);


/*-------------------------------------------------------------------------
  This program takes as input the length and width of a battlefield, and
  also the size of the army to be placed on the battlefield.
  The program will check if the army is large enough and if so will
  deploy it to the field according to the rule set.
 -------------------------------------------------------------------------*/
int main()
{
    int length = 0;
    int width = 0;
    int num_of_soldiers = 0;

    print_welcome_message();
    scanf("%d%d", &length, &width);

    char field[N][N];

    // Initializing array with all underscores.
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            field[i][j] = '_';
        }
    }

    print_welcome_message2();
    scanf("%d", &num_of_soldiers);

    if (length * width < num_of_soldiers)
    {
        print_too_many();
    }
    else
    {
        // Checking if the minimum number of soldiers needed for the field
        // is provided.
        int num_needed_per_row = (((width - 1) / 5 ) + 1);
        if (num_needed_per_row * length > num_of_soldiers)
        {
            print_not_enough();
                return 0;
        }

        /*if (width / 5 == 0 || width / 5 == 1)
        {
            if (1 * length > num_of_soldiers)
            {
                print_not_enough();
                return 0;
            }
        }
        else if (((width/5)+1)*length > num_of_soldiers)
        {
            print_not_enough();
            return 0;
        }*/

        for(int i = 0; i < length; i++)
        {
            for(int j=0; j< width; j+=5)
            {
                // Placing a soldier on the field, and lowering the total
                // number of soldiers left to deploy.
                field[i][j] = 'x';
                num_of_soldiers--;
            }
        }

        if (num_of_soldiers > 0)
        {
            // There soldiers left to deploy, placing them in all available spots until they run out.
            for(int i = 0; i < length; i++)
            {
                int j = 0;
                while (j < width && num_of_soldiers > 0)
                {
                    if (field[i][j] == '_')
                    {
                        // Placing a soldier on the field, and lowering the total
                        // number of soldiers left to deploy.
                        field[i][j] = 'x';
                        num_of_soldiers--;
                    }
                    j++;
                }
            }
        }
        print_field(field, length, width);
    }

    return 0;
}

void print_welcome_message()
{
    printf("Enter length and width of the battlefield:\n");
}

void print_welcome_message2()
{
    printf("How many soldiers do you have?\n");
}

void print_not_enough()
{
    printf("You don't have enough soldiers.\n");
}

void print_too_many()
{
    printf("You have too many soldiers.\n");
}

void print_field(char field[N][N], int len, int wid)
{
    printf("Your army's lineup:\n");
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<wid; j++)
            printf("%c ",field[i][j]);
        printf("\n");
    }
}
