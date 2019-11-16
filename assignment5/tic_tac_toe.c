#include <stdio.h>
#include <string.h>

//lines 5-25 taken from in class, lines 26-37 taken from Alex
int game(char g_board[])
{
    //check for tie game
    int tie = 1;
    for (int i = 0; i < strlen(g_board); i++)
    {
        if (g_board[i] != 'X' && g_board[i] != 'O')
        {
            tie = 0;
        }
    }
    if (tie == 1)
    {
        return 2;
    }
    
    for (int i = 0; i < 3; i++)
    {
        //check for column win
        if (g_board[i] == g_board[i + 3] && g_board[i + 3] == g_board[i + 6])
        {
            return 1;
        }
        //check for row win
        if (g_board[3 * i] == g_board[3 * i + 1] && g_board[3 * i + 1] == g_board[3 * i + 2])
        {
            return 1;
        }
    }

    //check for diagonal win
    if (g_board[0] == g_board[4] && g_board[4] == g_board[8])
    {
        return 1;
    }
    //another check for diagonal win
    if (g_board[2] == g_board[4] && g_board[4] == g_board[6])
    {
        return 1;
    }
}

//prints game board for user(s), also taken from class
int show_board(char g_board[])
{
    for (int i = 0; i < strlen(g_board); i++)
    {
        printf("%c", g_board[i]);
        if ((i + 1) % 3 != 0)
        {
            printf("|");
        }

        if (i == 8)
        {
            break;
        }

        if ((i + 1) % 3 == 0)
        {
            printf("\n-|-|-\n");
        }
    }
}

int main()
{
    char play = 'y';
    while (play == 'y') //loop while play = yes
    {
        char board_spots[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '\0'}; //taken from class
        char player = 'X';                                                          //X goes first
        int play_space = 9;                                                         //ignores the end of line character

        while (strlen(board_spots) == 9) //9 includes end of line character
        {
            show_board(board_spots);
            printf("\n\n%c: Where would you like to play: ", player);
            scanf("%d", &play_space);
            while (getchar() != '\n') //taken from class
                ;
            board_spots[play_space] = player;

            if (game(board_spots) == 1) //when a player wins, run this (used with return functions at top)
            {
                printf("\n");
                show_board(board_spots);
                printf("\nPlayer %c wins!", player);
                break;
            }

            if (game(board_spots) == 2) //when there's a tie, run this (used with return functions at top)
            {
                printf("\n");
                show_board(board_spots);
                printf("\n\nYou know what they say about ties, it's like kissing your sister. Now think about what you've done before playing again.\n");
                break;
            }

            printf("\n");
            //swithces turn for players
            if (player == 'X')
            {
                player = 'O';
            }
            else
            {
                if (player == 'O')
                {
                    player = 'X';
                }
            }
        }

        printf("\nPlay again? (y/n): "); //taken from class, used in assn 4
        scanf("%c", &play);              //taken from class, used in assn 4
        while (getchar() != '\n')        //taken from class, used in assn 4
            ;
    }
}
