#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRand(int arr[], int size, int ceil)
{
	int i, tmp;
	int used[ceil];
	for (i = 0; i < ceil; i++)
		used[i] = 0;
	for (i = 0; i < size; i++)
	{
		tmp = rand() % ceil;
		while (used[tmp])
			tmp = rand() % ceil;
		used[tmp] = 1;
		arr[i] = tmp;
	}
	return;
}

void selSort(int arr[], int size)
{
	int i, j,key,tmp;
	for (i = 0; i < size - 1; i++)
	{
		key = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[key])
			{
				key = j;
			}
		}
			tmp = arr[key];
			arr[key] = arr[i];
			arr[i] = tmp;
		
	}
}

void bubSort(int arr[], int size)
{
	int i, j,tmp;
	for (i = 1; i < size - 1; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
			tmp = arr[j+1];
			arr[j+1] = arr[j];
			arr[j] = tmp;	
			}
		}
	}
}

void insSort(int arr[], int size)
{
    int i, j;
    int key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int main()
{
	srand(time(0));
	int arr[10];
	fillRand(arr, 10, 10);
	printf("Unsorted list...\n");
	print(arr, 10);
	//--------------------
	//----Choose----------

	bubSort(arr, 10);
	//selSort(arr, 10);
	//insSort(arr, 10);

	//--------------------
	printf("Sorted list...\n");
	print(arr, 10);
	return 0;
}
