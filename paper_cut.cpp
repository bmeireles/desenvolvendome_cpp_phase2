//Paper cut into minimum number of squares
//Source code: https://www.geeksforgeeks.org/paper-cut-minimum-number-squares/
//Time Complexity: O(log(max(a,b))) 
//Auxiliary Space: O(1)


#include<bits/stdc++.h>
using namespace std;

// Returns min number of squares needed
int minimumSquare(int a, int b) //function to calculate the minimum number of squares that can fit a paper. Receives as 
//parameters the sides of the paper.
{
	long long result = 0, rem = 0; //variables for the result(number of squares) and the remaining paper size
	//long long int data type in C++ is used to store 64-bit integers. It is one of the largest data types to
	// store integer values. It can store positive values as well as negative values.

	if (a < b) // swap if a is small size side
		swap(a, b);

	// Iterate until small size side is
	// greater than 0
	while (b > 0) //while size b is greater than 0, we can cut the paper 
	{
		// Update result
		result += a/b; //result becomes the sum of the current result plus the division of side a by b

		long long rem = a % b; //rem receives the rest of the division of side a by b
		a = b; // a becomes b, that is the smaller size
		b = rem; // b becomes rem, that is the rest of the division
		//the loop test again if b is greater than 0, and if it is true it calculates the result and rem with 
		//new values a and b
	}

	return result; //after the loop is finished, return the total result
}

// Driver code
int main()
{
	int n = 13, m = 29; //sides of the paper
	cout << minimumSquare(n, m); //call function minimumSquare and print the result
	return 0;
}

