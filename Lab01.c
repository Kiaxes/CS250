#include <stdio.h>

int main()
{
int i;
printf("Enter Number 1-5 ");
scanf("%d" , &i);

switch(i)
{
    case 1:
            printf("one\n");
            break;
    case 2:
            printf("two\n");
            break;
    case 3:
            printf("three\n");
            break;
    case 4:
            printf("four\n");
            break;
    case 5:
            printf("five\n");
            break;
    default :
            printf("non\n");
}

}