#include <stdio.h>

int main()
{
    short stack = 30540;
    int eger = 9;
    long john = 9999;
    char acter = 't';
    float away = 3.14;
    double down = .1424529515;

    printf("short: %hu\n", stack);   //not entirely sure what 'short' does
    printf("integer: %d\n", eger);   //%d used from class 10/4
    printf("long var: %ld\n", john); //%ld used from class 10/4
    printf("letter: %c\n", acter);   //%c used from class 10/4
    printf("a float: %.2f\n", away); //%f used from class 10/4
    printf("decimal: %lf\n", down);  //rounds to 6th decimal place
}