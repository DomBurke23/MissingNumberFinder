/* C implementation QuickSort */
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print the sorted array */
void printSortedArray(int arr[], int size)
{
	int loopCounter;
	for (loopCounter=0; loopCounter < size; loopCounter++)
		printf("%d \n", arr[loopCounter]);
	printf("\n");
}

// Print all elements of range [low, high] that
// are not present in arr[0..n-1]
void printMissing(int arr[], int n, int low, int high)
{
	// Sort the array
//	sort(arr, arr + n);

	// Do binary search for 'low' in sorted array and find index of first element
	// which either equal to or greater than low.
	int* ptr = lower_bound(arr, arr + n, low);
	int index = ptr - arr;

	// Start from the found index and linearly
	// search every range element x after this
	// index in arr[]
	int i = index, x = low;
	while (i < n && x <= high) {
		// If x doesn't math with current element
		// print it
		if (arr[i] != x)
			cout << x << " ";

		// If x matches, move to next element in arr[]
		else
			i++;

		// Move to next element in range [low, high]
		x++;
	}

	// Print range elements thar are greater than the
	// last element of sorted array.
	while (x <= high)
		cout << x++ << " ";
}


// Driver program to test above functions
int main()
{
	int arr[] = { 58,53
,63 ,17,73,15,81,76,83,30,9,51,91,67,88,39,14
,87,34,77,11,19,31,71,35,94,59,43,40,93,78,70
,86,66,100,26,23,75,41,7,2,52,72,5,1,54,86,79
,50,37,22,47,29 };
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
//	printSortedArray(arr, n);
	int low = 1, high = n;
	printMissing(arr, n, low, high);
	return 0;
}
