#include <stdio.h>

int main()
{
    int secret_number = 0;
    int min_num = 1;
    int max_num = 100;
    printf("Enter a number between %d and %d: \n", min_num, max_num);
    scanf("%d", &secret_number);

    int guess = 0;
    int tries = 5;
    int attempts = 1;
    char ch;
    do
    {
        while (guess != secret_number)
        {
            printf("Guess the number between %d and %d: \n", min_num, max_num);
            scanf("%d", &guess);
            if (guess > secret_number)
            {
                tries--;
                attempts++;
                printf("%d is too high!\n", guess);
                printf("You have %d tries left\n", tries);
                max_num = guess;
            }
            if (guess < secret_number)
            {
                tries--;
                attempts++;
                printf("%d is too low!\n", guess);
                printf("You have %d tries left\n", tries);
                min_num = guess;
            }
            if (tries == 0)
            {
                printf("You have no more tries :(\n");
            }
        }
        if (guess == secret_number)
        {
            printf("You guessed it, %d!\n", secret_number);
            printf("It took you %d tries\n", attempts);
            printf("Would you like to play again? (y/n) ");
            ch = getchar(); //not entirely sure, taken from stack overflow
            getchar(); //not entirely sure, taken from stack overflow
        }

    } while (ch == 'y'); //supposed to rerun program, did not, not sure why
}
