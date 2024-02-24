#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	 // Base case: if low index is greater than high index, value is not found
  if (low > high) {
    return -1;
  }
  
  // Calculate middle index
  int mid = (low + high) / 2;
  
  // If the middle element is the value we are looking for, return its index
  if (numbers[mid] == value) {
    return mid;
  }
  
  // If the middle element is greater than the value, search in the left half of the array
  if (numbers[mid] > value) {
    return search(numbers, low, mid - 1, value);
  }
  
  // If the middle element is smaller than the value, search in the right half of the array
  return search(numbers, mid + 1, high, value);
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}