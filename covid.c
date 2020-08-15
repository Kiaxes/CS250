//==========================================
// Title:  Number of Covid in Thailand(City)
// Author: Chirawat (Kim) Yooyuenyong
// Date:   30 April 2020
//==========================================

/*
TABLE LAYOUT  &  FILE LAYOUT
||  Cities  ||  Total Positive case ||  Recovered ||  Ever Hospitalized ||  Deaths  ||

open with the file 'cities.txt'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

void sortPositive(data list[], int cityNum);
void print(data list[], int cityNum);
void options();
int choice(int choice, data list[], int cityNum);
int main(int argc, char *argv[])
{
    FILE *input;
    int cityNum, i, junk;
    data list[100];
    int choices;

    if (argc != 2) //make sure user inputfile and also name of the output file
    {
        printf("Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    input = fopen(argv[1], "r"); //ERROR for opening file
    if (input == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        exit(1);
    }
    fscanf(input, "%d ", &cityNum); //number of city

    for (i = 0; i < cityNum; i++)
    {
        fgets(list[i].city, 100, input);
        fscanf(input, "%d ", &list[i].positive);
        fscanf(input, "%d ", &list[i].recover);
        fscanf(input, "%d ", &list[i].hospital);
        fscanf(input, "%d ", &list[i].death);
    }

    while (1)
    {
        options();
        scanf("%d", &choices);
        choice(choices, list, cityNum);
    }
    //print(list, cityNum); //test print all pos. num
    //need options

    //need choice
    //sortPositive(list, cityNum);  //SORT works
    //print(list, cityNum); //test print all pos. num after sort

    fclose(input);
    return 0;
}

void sortPositive(data list[], int cityNum)
{
    int i, j, key;
    data tmp;
    for (i = 0; i < cityNum - 1; i++)
    {
        key = i;
        for (j = i + 1; j < cityNum; j++)
        {
            if (list[j].positive < list[key].positive)
            {
                key = j;
            }
        }
        tmp = list[key];
        list[key] = list[i];
        list[i] = tmp;
    }
}
void print(data list[], int cityNum)
{
    int i;
    for (i = 0; i < cityNum; i++)
    {
        printf("%d ", list[i].positive);
    }
    printf("\n");
    return;
}

void options()
{
    printf("====================\n");
    printf("1) View the list\n");
    printf("2) Sort the positive case base by max->min\n");
    printf("3) Try me :DDD\n");
    printf("-1) Exit\n");
    printf("====================\n");
}

int choice(int choice, data list[], int cityNum)
{
    int i;
    if (choice == 1)
    {
        for (i = 0; i < cityNum; i++)
        {
            printf("\n%s", list[i].city);
            printf("|| %d Total Positive case ", list[i].positive);
            printf("|| %d Recovered ", list[i].recover);
            printf("|| %d Ever Hospitalized ", list[i].hospital);
            printf("|| %d Deaths ||\n", list[i].death);
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i < cityNum; i++)
        {
            sortPositive(list, cityNum);
            printf("\n%s", list[i].city);
            printf("|| %d Total Positive case ", list[i].positive);
            printf("|| %d Recovered ", list[i].recover);
            printf("|| %d Ever Hospitalized ", list[i].hospital);
            printf("|| %d Deaths ||\n", list[i].death);
        }
    }
    else if (choice == 3)
    {
        printf("                                                                +-------------------------------------------------->\n");
        printf("                                                                 |                                                 |\n");
        printf("                                                                 |   +-------------------------------------> +     |\n");
        printf("                                                                 |   |    sudo Give me A++                   |     |\n");
        printf("                                                                 |   |    sudo Teach my next semester class  |     |\n");
        printf("                                    XX XXX                       |   |    sudo Thank you for an awesome class :D|  |\n");
        printf("            XXXXX XX XXXXXXX    XX X                             |   +<------------------------------------+ +     |\n");
        printf("       XXXXX                XXXX                               XX|                                                 |\n");
        printf("    XXXX                       XX                             XX +<-------------------------------------------------+\n");
        printf("    X                           XXX                         XX        XXXX\n");
        printf("  XX                              XXXX                    XXX    XXXXX\n");
        printf(" XX                                  XXXXXXXX             XXXXXXXX\n");
        printf(" X                                           XX XX\n");
        printf("X    X XXXXX   XX            XXXX                 XXX\n");
        printf("X    XXXXXXXX   X            XXXX                   XX\n");
        printf("X     XXXXXXXX  X            XXXX                    X\n");
        printf("XX   XX XXXXXX  X                                     X\n");
        printf(" X   XXXXXXX X  X                                     XXXXXXX\n");
        printf(" X   X XXXXXXX XX                                     X XXXXXXX\n");
        printf("  X   XXXX XXX X           XX                         XX  XXXXXX\n");
        printf("  XX   XXXXX   XXX          X                         XXXX  XXX\n");
        printf("   XXXX      XXX X          XX                       XXXX  XXXXX\n");
        printf("      XXX   XXX  XX           XX                    XXXXXXXXXXXX\n");
        printf("         XXXX     XX           XXXXXXXX          XXXX\n");
        printf("                   XXXXXXXXXXXXX      XXXXXXXXXXXXXX\n");
        printf("                   X           X\n");
        printf("                   X           XX\n");
        printf("                  XX            XX\n");
        printf("                  X              X\n");
        printf("                  X    X         X\n");
        printf("                 XX    X         XXXXXXXXX XXXXXXXX\n");
        printf("               XX      X         X       XXX      XXX\n");
        printf("              XX       X         X         X        XX\n");
        printf("             XX        X         X       XXX      XXXX\n");
        printf("            XX         X         X         X         X\n");
        printf("            X   X  X  XXX        X      XXXXX     XXXX\n");
        printf("            XXXXX  XXXX XXX      X          X        X\n");
        printf("              X  XXX      XXX    X          X        X\n");
        printf("              X             XXXXXX          X        X\n");
        printf("              X                             X        X\n");
        printf("              XXX                           X       XX\n");
        printf("         XXXXXXXXX                         XX       X\n");
        printf("    XXXXXX  XXXXXXX                       XX        X\n");
        printf("  XXXXX     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("      XXXXXXXX\n");
    }
    else if (choice == -1)
    {
        printf("exit\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Please choose something from the options *EXIT*\n");
        exit(EXIT_FAILURE);
    }
}