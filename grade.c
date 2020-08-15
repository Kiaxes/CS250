#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student();
void stripnewline(char str[]);
int cal(int ArrInput,int length);

int main()
{
    student();      // I use function haha xDDD
}

void student()
{
    int student,assignments,i,j; 
    char junk;

    char ArrStu[10][30];
    int ArrAss[10][30];
    int Avg[10];
    printf("How many student? ");
    scanf("%d", &student);
    printf("How many assignments? ");
    scanf("%d", &assignments);
    scanf("%c", &junk);
    for (i=0; i<student;i++)
    {
        printf("Enter student name: ");
        fgets(ArrStu[i],30,stdin);
        stripnewline(ArrStu[i]);
    }
    for (i=0; i< student;i++)
    {
        for (j=0;j<assignments;j++)
        {
        printf("Enter grade for Assignment %d for %s : ", j, ArrStu[i]);
        scanf("%d", &ArrAss[i][j]);
        Avg[i] = Avg[i] + ArrAss[i][j];
        }
        Avg[i] = Avg[i] / assignments;
    }

     for(i=0;i<=assignments;i++){
        printf("%10s", ArrStu[i]);
     }
     printf("\n");

    for(i=0;i< assignments;i++){
        for (j=0;j<student;j++)
        {
        printf("%10d", ArrAss[j][i]);
        
        }printf("\n");
       
    }
    for(i=0;i<=student-1;i++){
        printf("%10c", cal(Avg[i],student));
     }
   
    printf("\n");
    printf("This is the variable of Avg[0] %d\n", Avg[0]);
    printf("This is the variable of Avg[1] %d\n", Avg[1]);

    return ;
    
}
void stripnewline(char str[])
{
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
        }
    }
}

int cal(int ArrInput,int length)
{
    int i;
    char Return;
    for (i=0;i< length;i++)
    {
       
            if (ArrInput>=90)
            {
                Return = 'A';
            }
           
            else if (ArrInput >=80)
            {
                Return = 'B';
            }
            
            else if (ArrInput >=70)
            {
                Return = 'C';
            }
            
            else if (ArrInput>= 60)
            {
                Return = 'D';
            }
            else
            {
                Return = 'F';
            }
            
        }
        return Return;
    }
