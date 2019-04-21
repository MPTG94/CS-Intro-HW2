/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

bool print_dragon(bool dragon_c_cond, bool dragon_b_cond, bool dragon_a_cond);
int print_welcome_message();
int print_dragonX_sent(char c);
int print_no_dragon();

// Constant to check that the input ending char has been provided.
#define INPUT_ENDING_CHAR '!'

/*-------------------------------------------------------------------------
  This program takes the name of an enemy as input and prints the correct
  dragon to send to battle according to the name of the enemy.
  length: 15 lines
 -------------------------------------------------------------------------*/
int main()
{
    int ascii_sum = 0, num_of_letters = 0;
    bool is_rising = true, contains_letter_s  = false;
    char enemy_letter, previous_letter = 'Z';

    print_welcome_message();
    scanf(" %c", &enemy_letter);
    // Looping over input enemy letters until input ending char has been
    // provided.
    while(enemy_letter != INPUT_ENDING_CHAR)
    {
        // Adding the ASCII value of the letter to the sum.
        ascii_sum += enemy_letter;
        // Checking if the input letter is 's'.
        contains_letter_s = (contains_letter_s || enemy_letter == 's');
        // Checking if the new input letter value is larger than the previous
        // and also comparing to the result of previous checks.
        is_rising = (previous_letter < enemy_letter && is_rising);
        // Saving the input letter for comparison.
        previous_letter = enemy_letter;
        // Increasing the total letters counter.
        num_of_letters++;
        // Receiving a new letter as input.
        scanf("%c", &enemy_letter);
    }

    // Checking which dragon conditions were met and sending to print function.
    // Printing the correct dragon.
    print_dragon((!contains_letter_s && num_of_letters < 6), is_rising, (ascii_sum % 5 != 0 && num_of_letters > 4));
    return 0;
}

/*
This function receives the boolean result of every dragon printing
conditions and prints the correct dragon.
If multiple dragons conditions are met, the first dragon in lexical order
will be printed.
*/
bool print_dragon(bool dragon_c_cond, bool dragon_b_cond, bool dragon_a_cond)
{
    return !((dragon_c_cond && print_dragonX_sent('C')) ||
             (dragon_b_cond && print_dragonX_sent('B')) ||
             (dragon_a_cond && print_dragonX_sent('A')) ||
             (print_no_dragon()));
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
