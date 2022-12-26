//Paper cut into minimum number of squares
//Source code: https://www.geeksforgeeks.org/paper-cut-minimum-number-squares/
//Time Complexity: O(log(max(a,b))) 
//Auxiliary Space: O(1)


#include<bits/stdc++.h>
using namespace std;

// Returns min number of squares needed
int minimumSquare(int a, int b)
{
	long long result = 0, rem = 0;

	// swap if a is small size side .
	if (a < b)
		swap(a, b);

	// Iterate until small size side is
	// greater than 0
	while (b > 0)
	{
		// Update result
		result += a/b;

		long long rem = a % b;
		a = b;
		b = rem;
	}

	return result;
}

// Driver code
int main()
{
	int n = 13, m = 29;
	cout << minimumSquare(n, m);
	return 0;
}

