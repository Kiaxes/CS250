#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    char name[100];
    int quantity;
    float msrp;
    float sale;
    //TODO: Fill in the members of the structure
};
typedef struct product product;

void readProdFile(FILE* prodFile, product inventory[], int numProd);
void readSalesFile(FILE* salesFile, int sales[][100], int numProd, int numSales);
void calcRemainingInventory(product inventory[], int sales[][100], int numProd, int numSales);
void printReport(product inventory[], int numProd);
void outputToFile(product inventory[], int numProd);

int main(int argc, char *argv[])
{
    
    product inventory[100]; //Max of 100 items
    int sales[100][100]; //Max of 100 items, 100 sales
    int numProd, numSales;
    char choice;
    FILE *prodFile;
    FILE *salesFile;

     if(argc != 3)
    {
        printf("Usage: %s productfile salesfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //Open input file       DONE
     prodFile = fopen(argv[1], "r");
    if(prodFile == NULL)
    {
        printf("Error opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //Open output file     DONE 
    salesFile = fopen(argv[2], "r");
    if(salesFile == NULL)
    {
        printf("Error opening %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }


    //Read in file names from the command line
    // ./a.out productfile salesfile
    
    //TODO: Open files using command line args. Ensure proper error handling.


    //How many products in product file?
    fscanf(prodFile, "%d ", &numProd);

    //How many sales in sales file?
    fscanf(salesFile, "%d ", &numSales);

    readProdFile(prodFile, inventory, numProd);
    readSalesFile(salesFile, sales, numProd, numSales);

    calcRemainingInventory(inventory, sales, numProd, numSales);

    printReport(inventory, numProd);

    printf("Would you like to output to a new file? (y/n): ");
    scanf("%c", &choice);
    if(choice == 'y')
    {
        outputToFile(inventory, numProd);
    }


    return 0;
}



void readProdFile(FILE* prodFile, product inventory[], int numProd)
{
    //              READ IN FILE /// 
    char junk;
    for (int i=0;i < numProd;i++)
    {
        fgets(inventory[i].name,100, prodFile);
        //printf("%s", inventory[i].name);
        fscanf(prodFile," %d", &inventory[i].quantity);
        //printf("%d\n", inventory[i].quantity);
        fscanf(prodFile," %f", &inventory[i].msrp);
        //printf("%f\n", inventory[i].msrp);
        fscanf(prodFile," %f ", &inventory[i].sale);
        //printf("%f\n", inventory[i].sale);
       // fscanf(prodFile,"%c", &junk);
    }

    //TODO: Read in all remaining information from the product file
    //  Read this info into an array of structures
    //Note: Product names could have spaces.
    //Note: You will need to remove the newline character from the product name
    //Note: The first line of the file was already read in main.


    return;
}

void readSalesFile(FILE* salesFile, int sales[][100], int numProd, int numSales)
{
    for(int row=0;row < numSales;row++)
    {
        for (int col=0;col < numProd;col++)
        {
            fscanf(salesFile," %d ",  &sales[col][row]);
        }
    }
    //TODO: Read in all remaining information from the sales file
    //  Read this information in to a 2D array
    //Note: The first line of the file was already read in main.
    

    return;
}

void calcRemainingInventory(product inventory[], int sales[][100], int numProd, int numSales)
{
    //TODO: Based upon the sales in the sales array, update the remaining inventory quantity
    //  in the inventory array.
    for(int i=0;i < numProd;i++)
    {
       // inventory[i].quantity = inventory[i].quantity - sales[i];
           for (int j=0;j < numSales;j++)
           {
               inventory[i].quantity = inventory[i].quantity - sales [i][j];
           }
           //printf("%d\n", inventory[i].quantity);
    }

    return;
}

void printReport(product inventory[], int numProd)
{
    //TODO: Print out all of the deails from the inventory.
    //Note: Your output should be well formatted, money should look like money, etc.
    for(int i=0;i < numProd;i++)
    {
    printf("%s", inventory[i].name);
    printf("Quantity:   %6d\n", inventory[i].quantity);
    printf("MSRP:       %6.2f\n", inventory[i].msrp);
    printf("Price:      %6.2f\n\n", inventory[i].sale);
    }
    return;
}

void outputToFile(product inventory[], int numProd)
{
    //TODO: Output the inventory information to a new file.
    //  Ask the user within this function for the name of the file to output to
    //  The format of the output file should be the same as the input inventory file
    FILE* outfile;
    char name[30];
    printf("What file name should we save to? ", name);
    scanf("%s", name);
    outfile = fopen( name, "w");
    fprintf(outfile, "%d\n", numProd);
    for(int i=0;i < numProd;i++)
    {
    fprintf(outfile, "%s", inventory[i].name);
    fprintf(outfile, "%d ", inventory[i].quantity);
    fprintf(outfile, "%.2f ", inventory[i].msrp);
    fprintf(outfile, "%.2f \n", inventory[i].sale);
    }
    fclose(outfile);
    return;
}