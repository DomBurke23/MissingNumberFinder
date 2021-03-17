// MissingNumberFinder.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>

//Missing number finder opens a file path specified in the command line
//this file has a list of unique integers in it, the idea is to run through them 
//all and then output (in another file specified at the command line) all the missing numbers from one to n
//where n is the maximum number. The output must be in numerical order.

/* swap two elements */
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/** This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int partition (int mynumbers[], int low, int high)
{
	int pivot = mynumbers[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or equal to pivot
		if (mynumbers[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&mynumbers[i], &mynumbers[j]);
		}
	}
	swap(&mynumbers[i + 1], &mynumbers[high]);
	return (i + 1);
}

/** implement recursive QuickSort a divide and conquer algorithm 
 * The time complexity of Quicksort is O(n log n) in the best case, and O(n^2) in the worst case.
 * mynumbers[] --> array to be sorted,
 * low --> Starting index,
 * high --> Ending index */
void quickSort(int mynumbers[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, mynumbers[p] is now
		at right place */
		int pi = partition(mynumbers, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(mynumbers, low, pi - 1);
		quickSort(mynumbers, pi + 1, high);
	}
}

/* Print the sorted array */
void printSortedarray(int mynumbers[], int size)
{
	int loopCounter;
	for (loopCounter=0; loopCounter < size; loopCounter++) {
		printf("%d \n", mynumbers[loopCounter]);
	}
	printf("\n");
}

// Print all elements of range [low, high] that are not present in mynumbers[0..n-1]
void printMissing(int mynumbers[], int n, int low, int high, int biggestnumber)
{
	// Do binary search for 'low' in sorted array and find index of first element
	// which either equal to or greater than low.
	int* ptr = lower_bound(mynumbers, mynumbers + n, low);
	int index = ptr - mynumbers;

	// Start from the found index and linearly search every range element x after this index in mynumbers[]
	// linear search worst case o(n)
	int i = index, x = low;
	std::ofstream filewrite(argv[2]);
	while (i < n && x <= high) {
		// If x doesn't math with current element print it
		if (mynumbers[i] != x) {
			cout << x << " ";
		    //now output the missing numbers to another file
			filewrite << i << std::endl;
		}
		// If x matches, move to next element in mynumbers[]
		else {
			i++;
		}
		// Move to next element in range [low, high]
		x++;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//first open the input file and get all the numbers
	int mynumbers[100000];
	std::ifstream fileread(argv[1]);
        int mynumber;
	int tick =0;
	while(!fileread.eof())
	{
		fileread >> mynumber;
		mynumbers[tick] = mynumber;
		tick++;
	} 
	int n = sizeof(mynumbers)/sizeof(mynumbers[0]);
	quickSort(mynumbers, 0, n-1);
	printf("Sorted array: \n");
	printSortedarray(mynumbers, n);
	int low = 1, high = n;
	printMissing(mynumbers, n, low, high, biggestnumber);
	
	return 0;
}

