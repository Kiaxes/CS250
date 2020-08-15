#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);
void stripnewLine(char str[]);

int main()
{
    char input[750];
    
    int userNum = 0;
    int shift = 2;
    while(userNum != 4) {

        userNum = getUserChoice();

        if (userNum == 1)
        {
            shift = getShift();
            printf("Shift : %d\n", shift);
            //printf("change shift\n");
        }
        else if (userNum == 2)
        {
            getString(input);
            decrypt(input,shift);
            //printf("Decrypt\n");
        }
        else if (userNum == 3)
        {
            getString(input);
            encrypt(input,shift);
            //printf("Encrypt\n");
        }
        else if (userNum == 4)
        {
            printf("Quit\n");
            break;
        }
        else
        {
            printf("please enter something in the options\n");
        }
    }
    return 0;
}

int getUserChoice()
{
    int userNum;
    int junk;
    printf("-----------------------------\n");
    printf("| 1: Change Shift            |\n");
    printf("| 2: Decrypt a message       | \n");
    printf("| 3: Encrypt a message       |\n");
    printf("| 4: Quit                    |\n");
    printf("-----------------------------\n");
    printf("What would you like to do?\n");
    scanf("%d", &userNum);
    scanf("%c", &junk);
    return userNum;
}

int getShift()
{
    int shift;
    printf("Enter a new shift value: ");
    scanf("%d", &shift);
    return shift;
}

void getString(char buf[])
{
    fgets(buf, 750, stdin);
    stripnewLine(buf);
}

void stripnewLine(char str[])
{
    int i;
    for (i = 0;i< strlen(str); i++)
    {
        if (str[i] == '\n')
        {
            str[i]='\0';
            return;
        }
    }
}

void encrypt(char buf[], int shift)
{

    int i;
    for (i=0;i<strlen(buf);i++)
    {
        buf[i] = buf[i] + shift;
    }
    printf("%s\n",buf);
}
void decrypt(char buf[], int shift)
{
    int i;
        for (i=0;i<strlen(buf);i++)
        {
            buf[i] = buf[i] - shift;
        }
    printf("%s\n",buf);
}