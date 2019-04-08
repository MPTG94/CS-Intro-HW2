/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

void print_welcome_message();
void print_welcome_message2();
void print_word_check();
void print_success();
void print_fail();

// Constant to check that the input ending char has been provided.
#define INPUT_ENDING_CHAR '$'
// Length of the counter array.
#define LETTER_COUNTER_ARR_LENGTH 26
// Distance between ASCII uppercase and lowercase letters.
#define ASCII_LETTER_DISTANCE ('a'-'A')
// The ASCII value of the char 'A'.
#define CHAR_A_VALUE 'A'

/*-------------------------------------------------------------------------
  This program takes an expression to loop on, the number of times it can
  be looped, and an expression to see if it fits inside the expression to
  loop on.
  The program will print whether the looping is legal or not.
 -------------------------------------------------------------------------*/
int main()
{
    int num_loops = 0;
    // Creating counter array for the different letters of the ABC, regardless
    // of uppercase or lowercase letter.
    int letter_arr[LETTER_COUNTER_ARR_LENGTH] = {0};
    char input_letter;
    bool can_repeat = true;

    print_welcome_message();
    scanf(" %c", &input_letter);

    while(input_letter != INPUT_ENDING_CHAR)
    {
        // Counting the number of times every letter appeared in the expression
        // in either uppercase or lowercase version.
        if (input_letter > 90)
        {
            letter_arr[input_letter-ASCII_LETTER_DISTANCE-CHAR_A_VALUE]++;
        }
        else
        {
            letter_arr[input_letter-CHAR_A_VALUE]++;
        }
        // Receiving a new letter as input.
        scanf(" %c", &input_letter);
    }

    print_welcome_message2();
    // Checking that the input for number of loops is legal.
    if (scanf("%d", &num_loops) != 1 || num_loops < 0)
    {
        return 0;
    }

    // Calculating the number of times each letter can appear according to
    // number of loops.
    for (int i =0; i< LETTER_COUNTER_ARR_LENGTH; i++)
    {
        letter_arr[i] *= letter_arr[i] * num_loops;
    }

    print_word_check();
    scanf(" %c", &input_letter);
    while(input_letter != INPUT_ENDING_CHAR)
    {
        // Decreasing the number of times every letter can be used, as they
        // are used by the user.
        // If one of the letters was used more than is allowed, the final print
        // will be of a failure.
        if (input_letter > 90)
        {
            letter_arr[input_letter-ASCII_LETTER_DISTANCE-CHAR_A_VALUE]--;
            if (letter_arr[input_letter-ASCII_LETTER_DISTANCE-CHAR_A_VALUE] < 0)
            {
                can_repeat = false;
            }
        }
        else
        {
            letter_arr[input_letter-CHAR_A_VALUE]--;
            if (letter_arr[input_letter-CHAR_A_VALUE] < 0)
            {
                can_repeat = false;;
            }
        }
        // Receiving a new letter as input.
        scanf(" %c", &input_letter);
    }

    // Checking if the loop is legal and printing the correct message.
    if (can_repeat)
    {
        print_success();
    }
    else
    {
        print_fail();
    }

    return 0;
}

void print_welcome_message()
{
    printf("Hello Netta, enter the letters you would like us to repeat ending with $:\n");
}

void print_welcome_message2()
{
    printf("How many times would you like to loop?\n");
}

void print_word_check()
{
    printf("Enter the string you would like to be checked ending with $:\n");
}

void print_success()
{
    printf("Congratulations! you have enough letters to create your song and win the Eurovision!\n");
}

void print_fail()
{
    printf("Not enough letters\n");
}
