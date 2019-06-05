#include <iostream>


void merge(int* myArray, int* leftArray, int* rightArray, unsigned int length)
{
	int i = 0;
	int j = 0;
	int k = 0;

	int leftArraySize = length / 2;
	int rightArraySize = length - leftArraySize;

	while (i < leftArraySize && j < rightArraySize)
	{
		if (leftArray[i] < rightArray[j])	// if left element is smaller than right element
		{
			myArray[k] = leftArray[i];		// copy left element to parent
			++i;							// since you copied the left element, go to index 1
		}
		else
		{
			myArray[k] = rightArray[j];		// right element is smaller, copy  right  element to parent
			++j;							// since you copied the right element, go to index 1
		}
		++k;								// no matter what you need to go to next index of parent
	}

	while (i < leftArraySize)				// one of the conditions from previous while loop is met and we exited but not sure 
	{										// which one, so we check and fill the remaining elements to parent
		myArray[k] = leftArray[i];
		++i;
		++k;
	}

	while (j < rightArraySize)
	{
		myArray[k] = rightArray[j];
		++j;
		++k;
	}

}


void mergeSort(int* myArray, int length)
{

	int mid = length / 2;	// middle number is 3

	int* leftArray = new int[mid];		// divide the parent array to 2 part [0-3] & [4-7]
	int* rightArray = new int[length - mid];

	if (length < 2)	// if single element remained, return 
		return;

	else
	{

		for (int i = 0; i < mid; i++)			// fill left array [0-3]
		{
			leftArray[i] = myArray[i];
		}

		for (int i = 0; i < length - mid; i++)		// fill right array [4-7]
		{
			rightArray[i] = myArray[i + mid];
		}

		// my recursion calls
		mergeSort(leftArray, mid);						// send leftarray and 3 to mergeSort again			
		mergeSort(rightArray, length - mid);			// send rightarray and 4 to mergesort again
		merge(myArray, leftArray, rightArray, length);

	}
}


int main()
{
	int myArray[] = { 3,6,1,56,14,23,4 };
	int length = sizeof(myArray) / sizeof(int);	// length is 7
	
	
	mergeSort(myArray, length);		// send entire array and length = 7 to mergeSort
	
	for (int i = 0; i < length; i++)
	{
		std::cout << myArray[i] << "  ";		// print the result
	}
	std::cout << "\n" << std::endl;
}