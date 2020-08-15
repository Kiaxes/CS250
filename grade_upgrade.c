#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student(int argc, char *argv[]);
void stripnewline(char str[]);
int cal(int ArrInput,int length);

int main(int argc, char *argv[])
{
    student(argc,argv);      // I use function haha xDDD
    return 0;
}
void student(int argc, char *argv[])
{
    FILE* infile;
    if(argc != 2)
    {
        printf("Usage: %s inputfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    infile = fopen(argv[1], "r");
    if(infile == NULL)
    {
        printf("Error opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }


    int student,assignments,i,j; 
    char junk;

    char ArrStu[500][2000];
    int ArrAss[500][2000];
    int Avg[500];
    //printf("How many student? ");
    fscanf(infile,"%d",&student);
    //printf("How many assignments? ");
    fscanf(infile,"%d",&assignments);
    for (i=0; i<student;i++)
    {
        //printf("Enter student name: ");
        fscanf(infile, "%s",ArrStu[i]);
        //fgets(ArrStu[i],30,stdin);
        stripnewline(ArrStu[i]);
    }
    for (i=0; i< student;i++)
    {
        for (j=0;j<assignments;j++)
        {
        //printf("Enter grade for Assignment %d for %s : ", j, ArrStu[i]);
        fscanf(infile,"%d",&ArrAss[i][j]);
        //scanf("%d", &ArrAss[i][j]);
        Avg[i] = Avg[i] + ArrAss[i][j];
        }
        Avg[i] = Avg[i] / assignments;
    }

     for(i=0;i<student;i++){              
        printf("%12s", ArrStu[i]);                  // %12s so i user_name have between 8-11 it will still work fine
     }
     printf("\n");

    for(i=0;i< assignments;i++){
        for (j=0;j<student;j++)
        {
        printf("%12d", ArrAss[j][i]);
        
        }printf("\n");
       
    }
    for(i=0;i<=student-1;i++){
        printf("%12c", cal(Avg[i],student));
     }
   
    printf("\n");
    //printf("This is the variable of Avg[0] %d\n", Avg[0]);
    //printf("This is the variable of Avg[1] %d\n", Avg[1]);

    fclose(infile);
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
