/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
bool print_correct_dragon(bool dragon_c_conditions, bool dragon_b_conditions, bool dragon_a_conditions);
int print_welcome_message();
int print_dragonX_sent(char c);
int print_no_dragon();

#define INPUT_ENDING_CHAR '!'

/*-------------------------------------------------------------------------
  This program takes the name of an enemy as input and prints the correct
  dragon to send to battle according to the name of the enemy.
 -------------------------------------------------------------------------*/
int main()
{
    int ascii_sum = 0, num_of_letters = 0;
    bool is_rising_series = true, contains_letter_s  = false, dragon_a_conditions = false, dragon_b_conditions = false, dragon_c_conditions = false;
    char enemy_letter, previous_letter = 'Z';

    print_welcome_message();
    scanf("%c", &enemy_letter);
    while(enemy_letter != INPUT_ENDING_CHAR)
    {
        ascii_sum += enemy_letter;
        contains_letter_s = (contains_letter_s || enemy_letter == 's');
        is_rising_series = (previous_letter < enemy_letter && is_rising_series);
        previous_letter = enemy_letter;
        num_of_letters++;
        scanf("%c", &enemy_letter);
    }

    dragon_c_conditions = (!contains_letter_s && num_of_letters < 6);
    dragon_b_conditions = is_rising_series;
    dragon_a_conditions = (ascii_sum % 5 != 0 && num_of_letters > 4);

    print_correct_dragon(dragon_c_conditions, dragon_b_conditions, dragon_a_conditions);
    return 0;
}

bool print_correct_dragon(bool dragon_c_conditions, bool dragon_b_conditions, bool dragon_a_conditions)
{
    return (dragon_c_conditions && print_dragonX_sent('C')) ||
    (dragon_b_conditions && print_dragonX_sent('B')) ||
    (dragon_a_conditions && print_dragonX_sent('A')) ||
    (print_no_dragon());
}

int print_welcome_message()
{
    return printf("Please enter enemy name:\n");
}

int print_dragonX_sent(char c)
{
    return printf("\nKhaleesi sent dragon%c into the battle!!!\n", c);
}

int print_no_dragon()
{
    return printf("\nNO Dragon has been sent into the battle!!!\n");
}
