#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int ID;
    char first[20];
    char last[20];
    int department;
    int salary;
};
typedef struct data data;

void options();

int choice(int input, data list[], int num);

int main(int argc, char *argv[]) {
    int employee, userInput, i;
    data list[100];

    FILE *infile;
    if (argc != 2) {
        printf("Usage: %s inputfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Error opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fscanf(infile, "%d", &employee);

    while (1) {
        for (i = 0; i < employee; i++) {
            fscanf(infile, "%d", &list[i].ID);
            fscanf(infile, "%s", list[i].first);
            fscanf(infile, "%s", list[i].last);
            fscanf(infile, "%d", &list[i].department);
            fscanf(infile, "%d", &list[i].salary);
        }
        options();
        scanf("%d", &userInput);
        choice(userInput, list, employee);
    }
    fclose(infile);
    return 0;
}

void options() {
    printf("Welcome to the Employee Database!\n");
    printf("---------------------------------\n");
    printf("Choose an option: \n");
    printf("1:  Print empid\n");
    printf("2:  Print ALL employees\n");
    printf("3:  show all employees in department\n");
    printf("-1: QUIT\n");
    printf("---------------------------------\n");
}

int choice(int input, data list[], int num) {
    int departNum, empID;
    if (input == 1) {
        printf("Which employee ID to print?");
        scanf("%d", &empID);
        int found = 0;
        for (int i = 0; i < num; i++) {
            if (empID == list[i].ID) {
                printf("ID: %9d\n", list[i].ID);
                printf("First Name: %s\n", list[i].first);
                printf("Last Name: %s\n", list[i].last);
                printf("Department:  %d\n", list[i].department);
                printf("Salary: %d\n\n", list[i].salary);
                found++;
            }
        }
        if (found == 0) {
            printf("Employee %d not found\n", empID);
        }
    } else if (input == 2) {
        for (int i = 0; i < num; i++) {
            printf("ID: %9d\n", list[i].ID);
            printf("First Name: %s\n", list[i].first);
            printf("Last Name: %s\n", list[i].last);
            printf("Department:  %d\n", list[i].department);
            printf("Salary: %d\n\n", list[i].salary);
        }
    } else if (input == 3) {
        printf("Which department number?");
        scanf("%d", &departNum);
        int found = 0;
        for (int i = 0; i < num; i++) {
            if (departNum == list[i].department) {
                printf("ID: %9d\n", list[i].ID);
                printf("First Name: %s\n", list[i].first);
                printf("Last Name: %s\n", list[i].last);
                printf("Department:  %d\n", list[i].department);
                printf("Salary: %d\n\n", list[i].salary);
                found++;
            }
        }
        if (found == 0) {
            printf("department %d not found\n", departNum);
        }
    } else if (input == -1) {
        printf("exit\n");
        exit(EXIT_FAILURE);
    } else { printf("Please Enter something from the options\n"); }
}