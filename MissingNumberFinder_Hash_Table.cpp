// MissingNumberFinder.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>

//Missing number finder opens a file path specified in the command line
//this file has a list of unique integers in it, the idea is to run through them 
//all and then output (in another file specified at the command line) all the missing numbers from one to n
//where n is the maximum number. The output must be in numerical order.

/**
 *   Altered original file and used a hash table instead of a second array. 
 *   Time complexity is O(n).
 */

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

	// Insert all elements of mynumbers[] into set
	int arraySize = sizeof(mynumbers) / sizeof(mynumbers[0]);
	unordered_set<int> s;
	for (int i = 0; i < arraySize; i++)
		s.insert(mynumbers[i]);
	int low = 1, high = arraySize;
	// Linear Search and print all missing elements, worst case complexoty is O(n). 
	for (int x = low; x <= high; x++)
		if (s.find(x) == s.end())
			cout << x << " ";
	
	//now output the missing numbers to another file
 	int index2 = 0;
	std::ofstream filewrite(argv[2]);
	for (int i=1;i<high;i++)
	{
		int target = mynumbers[index2];
		if (i!=target)
		{
			filewrite << i << std::endl;
		}
		else
		{
			index2++;
		}
	} 
	return 0;
}
