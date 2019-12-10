#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fighter.h"

/*dynamic memory allocation for name of Fighter 1 from lines 106 to 123 and line 175, 
I did not do assignment 6 and would like this to account for (some of) the points*/

// #define atk 10   //I originally planned on having two different atk and def or heal values
// #define heal 15  //for each player that would factor into the range for hit and def/heal
// #define atk_2 15 //but I didn't end up going that route :(
// #define heal_2 10

void player_turn(struct fighter *player, struct fighter *enemy)
{
    int move;

    //ask user for move
    printf("\n%s: Hit (1), Big Hit (2), Heal (3): ", player->names);
    scanf("%d", &move);
    while (getchar() != '\n')
        ;
    // printf("%d\n", move); //used to confirm input while making program

    if (move == 1)
    {
        enemy->hp -= rand() % (8 + 1 - 5) + 5; //damage range from 5 to 8
        printf("%s's HP: %d\n", enemy->names, enemy->hp);
    }
    if (move == 2)
    {
        enemy->hp -= rand() % (10 + 1 - 1) + 1; //damage range from 1 to 10
        printf("%s's HP: %d\n", enemy->names, enemy->hp);
    }
    if (move == 3)
    {
        player->hp += rand() % (10 + 1 - 3) + 3; //heal range from 3 to 10
        if (player->hp > 50)
        {
            player->hp = 50; //cannot heal above 50 HP
        }
        printf("%s's HP: %d\n", player->names, player->hp);
    }
    if (move != 1 && move != 2 && move != 3)
    {
        printf("That is an invalid move, you lose your turn.");
    }
}

void winner_1()
{
    FILE *f = fopen("final_test.txt", "r+"); //I know this is bad but I had to meet the File IO requirement, sorry
    char *text = "Fighter 1";                //and I used programiz.com to put this piece together
    fprintf(f, "Previous Winner: %s\n", text);
    fscanf(f, "%s", &text);
    printf("Winner: %s\n", text);
    fclose(f);
}

void winner_2()
{
    FILE *f = fopen("final_test.txt", "r+"); //also very bad
    char *text = "Fighter 2";
    fprintf(f, "Previous Winner: %s\n", text);
    fscanf(f, "%s", &text);
    printf("Winner: %s\n", text);
    fclose(f);
}
int main()
{
    //define variables to be used in print statements
    // char name[20];
    int hp = 50;
    int atk = 10;
    int heal = 10;

    char name_2[20];
    int hp_2 = 50;
    int atk_2 = 10;
    int heal_2 = 10;

    //introduction reading that no one wants
    printf("\nWelcome, fighters! Today could very well be your final one.\n");
    printf("Ideally, you will be fighting an enemy.\n");
    printf("Realistically, you will be in control of both yourself and your foe.\n");
    printf("Either way, I wish you luck.\n");

    printf("\nPress enter to continue. ");
    getchar();

    printf("\nYour HP begins at 50 and the maximum damage that can be dealt in one turn is 10.");
    printf("\nA regular hit will do anywhere from 5 to 8 damage.");
    printf("\nA big hit can do 1 to 10 damage.");
    printf("\nA heal will recover 3 to 10 of your own HP.");

    printf("\n\nIf you enter an invalid move, you will be ridiculed and lose your turn.\n"); //it's not a bug, it's a feature

    printf("\nPress enter to continue.\n");
    getchar();

    //run while play is yes
    char play = 'y';
    while (play == 'y')
    {
        //dynamic memory allocation for Fighter 1 name
        char *name, c = '0';
        int i = 0, j = 1;
        name = (char *)malloc(sizeof(char));
        printf("Fighter 1, enter your name: ", name);
        while (c != '\n')
        {
            c = getc(stdin);
            if (c == '\n')
            {
                break;
            }
            // printf("c: %c(%d)\n", c, c);
            name = (char *)realloc(name, j * sizeof(char));
            name[i] = c;
            i++;
            j++;
        }
        name[i] = '\0';
        // free(name);

        // printf("Fighter 1, enter your name: ", name);
        // scanf("%s", &name);
        // while (getchar() != '\n')
        //     ;

        //non dynamic memory allocation for Fighter 2 name
        printf("\nFighter 2, enter your name: ", name_2);
        scanf("%s", name_2);
        while (getchar() != '\n')
            ;

        //(very short) array of strings
        char *names[2] = {name, name_2};

        //seed for random, taken from google
        srand(time(NULL));

        //define Fighter 1 using .h file and variables
        struct fighter tanner = {*names, hp, atk, heal};
        struct fighter *tanner_ptr = &tanner;

        //define Fighter 2 using .h file and variables
        struct fighter alex = {*(names + 1), hp, atk, heal};
        struct fighter *alex_ptr = &alex;

        /*tell users their stats, was supposed to actually mean something but did not
        go that route as mentioned above*/
        printf("\n%s, your stats are: HP: %d, ATK: %d, Heal: %d\n", tanner.names, tanner.hp, tanner.atk, tanner.heal);
        printf("%s, your stats are: HP: %d, ATK: %d, Heal: %d\n", alex.names, alex.hp, alex.atk, alex.heal);

        //set player 1 and what to do when one HP goes below or equal to 0
        char *player = tanner.names;
        while (play == 'y')
        {
            player_turn(&tanner, &alex);
            if (alex.hp <= 0)
            {
                printf("%s lost!\n", alex.names);
                winner_1();
                break;
            }
            player_turn(&alex, &tanner);
            if (tanner.hp <= 0)
            {
                printf("%s lost!\n", tanner.names);
                winner_2();
                break;
            }
        }
        free(name); //resets name of Fighter 1 if play again
        printf("Would you like to play again? (y/n) ");
        scanf("%c", &play);
        while (getchar() != '\n')
            ;
    }
}

// failed attempts and older versions/first drafts

// printf("\nFighter 2: Attack (1), Defend (2), Heal (3): ");
// scanf("%d", &move_2);
//
// if (move == 1)
// {
//     hp -= rand() % (10 + 1 - 1) + 1;
//     printf("%d\n", hp);
//     return hp;
// }
//
// if (player == 'fighter')
// {
//     player = 'fighter_2';
// }
// else
// {
//     if (player == 'fighter_2')
//     {
//         player = 'fighter';
//     }
// }
//
// if (player == tanner.name)
//         {
//             printf("\n%s: Hit (1), Big Hit (2), Heal (3): ", player);
//             scanf("%d", &move);
//             printf("%d\n", move);
//             if (move == 1)
//             {
//                 hp_2 -= rand() % (8 + 1 - 5) + 5;
//                 printf("HP 2: %d\n", hp_2);
//             }
//             if (move == 2)
//             {
//                 hp_2 -= rand() % (10 + 1 - 1) + 1;
//                 printf("HP 2: %d\n", hp_2);
//             }
//             if (move == 3)
//             {
//                 hp += rand() % (10 + 1 - 1) + 1;
//                 printf("%d\n", hp);
//             }
//             if (hp_2 < 0)
//             {
//                 printf("%s loser\n", alex.name_2);
//                 break;
//             }
//             player = alex.name_2;
//         }
//         else
//         {
//             {
//                 if (player == alex.name_2)
//                 {
//                     printf("\n%s: Hit (1), Big Hit (2), Heal (3): ", player);
//                     scanf("%d", &move);
//                     printf("%d\n", move);
//                     if (move == 1)
//                     {
//                         hp -= rand() % (8 + 1 - 5) + 5;
//                         printf("HP 1: %d\n", hp);
//                         // return hp_2;
//                     }
//                     if (move == 2)
//                     {
//                         hp -= rand() % (10 + 1 - 1) + 1;
//                         printf("HP 1: %d\n", hp);
//                     }
//                     if (move == 3)
//                     {
//                         hp_2 += rand() % (10 + 1 - 1) + 1;
//                         printf("%d\n", hp_2);
//                     }
//                     if (hp < 0)
//                     {
//                         printf("%s loser\n", tanner.name);
//                         break;
//                     }
//                     player = tanner.name;
//                 }
//             }
//
// if (alex.hp <= 0)
// {
//     printf("%s loser\n", alex.names);
//     FILE *f = fopen("final_test.txt", "r+"); //I know this is bad but I had to meet the File IO requirement, sorry
//     char *text = "Fighter 1";                //and I used programiz.com to put this piece together
//     fprintf(f, "Previous Winner: %s\n", text);
//     fscanf(f, "%s", &text);
//     printf("Winner: %s\n", text);
//     fclose(f);
//     printf("Play again? ");
//     scanf("%c", &play);
//     while (getchar() != '\n')
//         ;
// }
// player_turn(&alex, &tanner);
// if (tanner.hp <= 0)
// {
//     printf("%s loser\n", tanner.names);
//     FILE *f = fopen("final_test.txt", "w"); //also very bad
//     char *text = "Fighter 2";
//     fprintf(f, "Prevoius Winner: %s\n", text);
//     fscanf(f, "%s", &text);
//     printf("Winner: %s\n", text);
//     fclose(f);
//     printf("Play again? ");
//     scanf("%c", &play);
//     while (getchar() != '\n')
//         ;
// }
