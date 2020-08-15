#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int findMin(int *array, int size);
int findMax(int *array, int size);
int sum(int *array, int size);
int avg(int *array, int size);
int fee(int *array, int size);

int main()
{
    srand(time(NULL));
    int input = 0;
    printf("How many transactions would you want me to generate? ");
    scanf("%d", &input);
    
    int test[100];
    for (int i=0;i<input;i++)
    {
        test[i] = rand() % 201 - 100;
    }
    printf("---Summary--\n");
    printf("Account Balance: $%d\n", ((sum(test,input))+(fee(test,input))));
    printf("Total Fees: $%d\n", fee(test,input));
    
    findMin(test,input);
    findMax(test,input);
    printf("Sum : %3d\n", sum(test,input));
    printf("Avg : %3d\n",  (sum(test, input))/input);
   // printf("%d\nSum : %d\nAvg : %d\n", findMin(test,input), findMax(test, input),sum(test,input), (sum(test, input))/input);
    //printf("The min is %d\n", min(test[i]));`
    //printf("The max is %d\n", max(test[i]));
    printf("\nPos | Val \n==========\n");
    for (int i=0;i<input;i++)
    {
      printf("%2d  |%4d\n", i ,test[i]);   
    }
}

int findMin(int *array, int size)
{
    int min=array[0];
    int loc=0;
    
    for(int i=1;i<size;i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            loc = i;
        }
    }
    printf("Min : %3d    LOC: %4d\n", min, loc);
}

int findMax(int *array, int size)
{
    int max=array[0];
    int loc=0;
    for(int i=0;i<size;i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            loc = i;
        }
    }

    printf("Max : %3d    LOC: %4d\n", max, loc);
}

int sum(int *array, int size)
{
    int sum=0;

    for(int i=0;i<size;i++)
    {
        sum = array[i] + sum;
    }
    return sum;
}

int fee(int *array, int size)
{
    int fee=0;
    for (int i = 0; i <= size; i++)
    {
        if (array[i] < -1)
        {
            fee = fee - 10;
        }
    } return fee;
}