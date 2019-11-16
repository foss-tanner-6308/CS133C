#include <stdio.h>
#include <string.h>

int game(char g_board[][3][3])
{
    //check for tie game
    int tie = 1;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (g_board[row][col][0] != 'X' && g_board[row][col][0] != 'O')
            {
                tie = 0;
            }
        }
    }
    if (tie == 1)
    {
        return 2;
    }

    //check row for win, shown in class
    for (int row = 0; row < 3; row++)
    {
        if (g_board[row][0][0] == g_board[row][1][0] && g_board[row][1][0] == g_board[row][2][0])
        {
            if (g_board[row][0][0] != 'X' && g_board[row][0][0] != 'O')
            {
                continue;
            }
            else
            {
                return 1;
            }
        }
    }

    //check column for win, shown in class
    for (int col = 0; col < 3; col++)
    {
        if (g_board[0][col][0] == g_board[1][col][0] && g_board[1][col][0] == g_board[2][col][0])
        {
            return 1;
        }
    }

    //check diagonal for win, shown in class
    if (g_board[0][0][0] == g_board[1][1][0] && g_board[1][1][0] == g_board[2][2][0])
    {
        return 1;
    }
    //another check for diagonal win
    if (g_board[2][0][0] == g_board[1][1][0] && g_board[1][1][0] == g_board[0][2][0])
    {
        return 1;
    }
}

//used in 1d tic-tac-toe with minor adjustments
void show_board(char g_board[][3][3]) //Alex helped me adjust this from 1d to 2d
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%s", g_board[row][col]);
            if ((col + 1) % 3 != 0)
            {
                printf("|");
            }
        }
        //also used in the 1d tic-tac-toe
        if ((row + 1) % 3 != 0)
        {
            printf("\n--|--|--\n");
        }
    }
}

int main()
{
    char play = 'y';
    while (play == 'y') //run while play = yes
    {
        //Alex helped me set this up
        char b_spots[4][3][3] = {
            {"a0", "a1", "a2"},
            {"b0", "b1", "b2"},
            {"c0", "c1", "c2"},
            {"\0"}};
        char *player = "X ";
        char user_row = 'd';
        int user_col = 4;

        while (play == 'y') //run while play = yes
        {
            show_board(b_spots);
            printf("\nPlayer %s: Where would you like to play: ", player);
            scanf("%c%d", &user_row, &user_col); //checks user move
            user_row = user_row - 'a'; //thanks Alex
            while (getchar() != '\n')  //taken from class
                ;
            strcpy(b_spots[user_row][user_col], player); //thanks again Alex
            
            if (game(b_spots) == 1)                      //when a player wins, run this (used with return functoins at top)
            {
                printf("\n");
                show_board(b_spots);
                printf("\nPlayer %s wins!", player);
                break;
            }
            
            if (game(b_spots) == 2) //when there's a tie, run this (used with return functions at top)
            {
                printf("\n");
                show_board(b_spots);
                printf("\nCat's game! Nobody wins.");
                break;
            }

            printf("\n");
            //swithces turn for players, X goes first
            if (strcmp(player, "X ") == 0)
            {
                player = "O ";
            }
            
            else
            {
                if (strcmp(player, "O ") == 0)
                {
                    player = "X ";
                }
            }
        }

        printf("\nPlay again? (y/n): "); //taken from class, used in assn4
        scanf("%c", &play);              //taken from class, used in assn4
        while (getchar() != '\n')        //taken from class, used in assn4
            ;
    }
}
