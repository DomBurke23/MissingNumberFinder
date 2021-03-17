// MissingNumberFinder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

//Missing number finder opens a file path specified in the command line
//this file has a list of unique integers in it, the idea is to run through them 
//all and then output (in another file specified at the command line) all the missing numbers from one to n
//where n is the maximum number. The output must be in numerical order.

int _tmain(int argc, _TCHAR* argv[])
{
	//first open the input file 
	//and get all the numbers
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

	//now sort the numbers into a new array
	int mynumbers2[100000];
	int lastsmallestnumber; 
	int currentsmallestnumber;
	int biggestnumber;
	int index;
	for (int i = 0;i<tick;i++)
	{
		for (int j=0;j < tick;j++)
		{
			if (j==0)
			{
				currentsmallestnumber = mynumbers[j];
				index = j;
			}
			else if (mynumbers[j] < currentsmallestnumber)
			{
				currentsmallestnumber = mynumbers[j];
				index = j;
			}
		}
		mynumbers2[i] = currentsmallestnumber;
		mynumbers[index] = INT_MAX;

	}
	biggestnumber = mynumbers2[tick-1];

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

