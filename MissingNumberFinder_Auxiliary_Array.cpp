// MissingNumberFinder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std; 

//Missing number finder opens a file path specified in the command line
//this file has a list of unique integers in it, the idea is to run through them 
//all and then output (in another file specified at the command line) all the missing numbers from one to n
//where n is the maximum number. The output must be in numerical order.

int _tmain(int argc, _TCHAR* argv[])
{
	//first open the input file 
	//and get all the numbers
	int mynumbers[100000];
	int mynumbers[] = { 1, 7, 3, 12, 5, 10, 8, 4, 9 }; 
	
	std::ifstream fileread(argv[1]);
    int mynumber;
	int tick =0;
	while(!fileread.eof())
	{
		fileread >> mynumber;
		mynumbers[tick] = mynumber;
		tick++;
	}
	
	int array_size = sizeof(mynumbers) / sizeof(mynumbers[0]); 	
	// Keep track of numbers missing 
	int helper[array_size]; 

	// Traverse the input array and mark 
	// visited elements either by marking 
	// them as negative in mynumbers[] or in 
	// helper[]. 
	for (int i = 0; i < array_size; i++) { 
		int temp = abs(mynumbers[i]); 

		// If element is smaller than or 
		// equal to length, mark its 
		// presence in mynumbers[] 
		if (temp <= array_size) 
			mynumbers[temp - 1] *= (-1); 

		// Mark presence in helper[] 
		else if (temp > array_size) { 
			if (temp % array_size != 0) 
				helper[temp % array_size - 1] = -1; 
			else
				helper[(temp % array_size) + array_size - 1] = -1; 
		} 
	} 

	// Print missing numbers to another file 
	std::ofstream filewrite(argv[2]);
	for (int i = 0; i < array_size; i++) {
		if (mynumbers[i] > 0) {
		    int missing_number;
			missing_number = i+1; 
			cout << (missing_number) << " "; 
			filewrite << missing_number << std::endl;
		}
	}
	for (int i = 0; i < array_size; i++) {
		if (helper[i] >= 0) {
			cout << (array_size + i + 1) << " "; 
		}
	}

	//now output the missing numbers to another file
	int index2 = 0;
	std::ofstream filewrite(argv[2]);
	for (int i=1;i<biggestnumber;i++)
	{
		int target = mynumbers2[index2];
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

