#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//lines 7 to 24 taken from word_guess in class with minor adjustments
//such as not printing the word back to the user
bool *validate_word(char *word)
{
    int length = strlen(word);
    char fixed_word[length];
    for (int i = 0; i < length; i++)
    {
        bool low_bad = word[i] < 'A';
        bool mid_bad = (word[i] > 'Z' && word[i] < 'a');
        bool high_bad = word[i] > 'z';
        if (low_bad || mid_bad || high_bad)
        {
            printf("(%c) is an invalid word, please only use letters. \n", word[i]);
            return true;
        }
        fixed_word[i] = word[i];
    }
    return false;
}
//lines 19 and 23, not sure why return true for invalid word and return
//false for correct word works, but it does so I won't question it

//lines 29 to 36 taken from in class example, don't remember when the class was
char get_word(char *secret, int max_len)
{
    printf("Enter the secret word (25 characters or less): \n");
    fgets(secret, max_len, stdin);
    int sec_len = strlen(secret);
    secret[sec_len - 1] = '\0'; //takes off secret character at the end of input and was very difficult to figure out
    return *secret;
}

//this is where the magic happens
int main()
{
    char play = 'y';    //set var play to yes
    while (play == 'y') //run while play is set to yes
    {
        int max_len = 25;          //set max length of secret word
        char secret_word[max_len]; //not sure what this does, Alex helped me with it

        //validate that the word contains letters only
        bool bad_word = true;
        while (bad_word)
        {
            *secret_word = get_word(secret_word, max_len);
            bad_word = validate_word(secret_word);
        }
        // if (strlen(secret_word) < 11)
        // {
        //     secret_word[strlen(secret_word) - 1] = '\0';
        // }
        //I don't remember what this was but it was wrong, looks like
        //a bad attempt at removing the special end of input character

        int guesses = 5; //allowed number of incorrect guesses
        int sec_len = strlen(secret_word);

        char word_guess[strlen(secret_word)];
        for (int i = 0; i < strlen(secret_word); i++)
        {
            word_guess[i] = '_'; // changes secret word to underscores for user who will be guessing it
        }
        // printf("%s", secret_word - 1); //failed attempt of fixing odd error, turns out taking the line out helped
        word_guess[sec_len] = '\0';
        // word_guess(stlen(word_guess) - 3) = '\0'; //succesful attempt at fixing odd error for a specific number of letters for secret word (10 letters)
        int correct = 0;
        char guess = '?';

        while (guesses > 0 && strcmp(secret_word, word_guess) != 0) //run while user still has guesses and has not guessed the word
        {
            correct = 0;

            for (int i = 0; i < strlen(word_guess); i++)
            {
                printf("%c ", word_guess[i]); //print the underscores for each letter of secret word
            }

            printf("\nYou have %d guesses remaining. \nEnter a letter: ", guesses);
            scanf("%c", &guess);
            while (getchar() != '\n') //you showed us this in class, I don't remember what it does but it works. It has to do with the end of line special character
                ;

            for (int i = 0; i < strlen(word_guess); i++)
            {
                //repeat loop till user guesses new word
                if (guess == word_guess[i])
                {
                    printf("You already guessed this letter.\n");
                    correct = 1;
                    break;
                }
                //determine if letter guessed is correct
                if (guess == secret_word[i])
                {
                    word_guess[i] = secret_word[i];
                    correct = 1;
                }
            }
            //inform user of incorrect guess
            if (correct == 0)
            {
                printf("Incorrect guess!\n");
                guesses--;
            }
        }
        //no more guesses = loser
        if (guesses == 0)
        {
            printf("You are out of guesses! The correct word was %s. You guessed %s.", secret_word, word_guess);
        }
        //guessed word = winner
        else
        {
            printf("You win! The correct word was %s You had %d guesses remaining.", secret_word, guesses);
        }

        printf("\nPlay again? (y/n): "); //if user enterers "y", play again, if not then end program
        scanf("%c", &play);
        while (getchar() != '\n') //as previously mentioned, you showed us in class and I do not remember exactly what this does
            ;
    }
}
