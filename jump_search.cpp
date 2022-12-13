//Jump search
//Source code: https://www.geeksforgeeks.org/jump-search/
//Time Complexity : O(√n) 
//Auxiliary Space : O(1)
//Performance in comparison to linear and binary search:
//linear search  <  jump search  <  binary search


#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n) //function to find a number in an array through the jumpsearch algorithm. Receives
//as parameters an array, the size of the array and the number to be found x.
{
	// Finding block size to be jumped
	int step = sqrt(n); //uses the squareroot function to create the first step, which will define the first block of
	//indexes to search for the number

	// Finding the block where element is
	// present (if it is present)
	int prev = 0; //initialize the previous variable as 0, which represents the first number of the block
	while (arr[min(step, n)-1] < x) //while the element of the array, from the minimum between step and n is smaller
	//than x, we still haven't found the right block
	{
		prev = step; //so go to the next block, we substitute the previous value for the step
		step += sqrt(n); //and the new step is the last one plus the squareroot of n
		if (prev >= n) //if the previous number becomes greater than the size of the array, then the number x doesn't
		//exist in the array
			return -1; //return -1 because the value doesn't exist
	}

	// Doing a linear search for x in block
	// beginning with prev.
	while (arr[prev] < x)
	{
		prev++;

		// If we reached next block or end of
		// array, element is not present.
		if (prev == min(step, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

// Driver program to test function
int main()
{
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
				34, 55, 89, 144, 233, 377, 610 };
	int x = 55;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Find the index of 'x' using Jump Search
	int index = jumpSearch(arr, x, n);

	// Print the index where 'x' is located
	cout << "\nNumber " << x << " is at index " << index;
	return 0;
}

// Contributed by nuclode
