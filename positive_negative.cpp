//Positive elements at even and negative at odd positions
//Source code: https://www.geeksforgeeks.org/positive-elements-at-even-and-negative-at-odd-positions-relative-order-not-maintained/
//Time Complexity: O(n2)
//Auxiliary Space: O(1)


#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[], int size)
{
	int positive = 0, negative = 1; //variables to use as pointers

	while (true) { //while the index is smaller than the size of the array

		/* Move forward the positive pointer till negative number not encountered */
		while (positive < size && a[positive] >= 0) //while the positive pointer is smaller than the size and
        //the element in the positive index is greater or equal to 0
			positive += 2; //move the pointer 2 indexes forward

		/* Move forward the negative pointer till positive number not encountered */
		while (negative < size && a[negative] <= 0) //while the negative pointer is smaller than the size and
        //the element in the negative index is smaller or equal to 0
			negative += 2; //move the pointer 2 indexes forward

        //After these both while's, the the positive and negative pointers should be in valid numbers to be swapped.
		// Swap array elements to fix their position.
		if (positive < size && negative < size) //if the positive and negative indexes are inside the the range
        //of the array size
			swap(a[positive], a[negative]); //swap the elements in positive and negative indexes

		/* Break from the while loop when any index exceeds the size of the array */
		else
			break;
	}
}

// Driver code
int main()
{
	int arr[] = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 }; //create an array
	int n = (sizeof(arr) / sizeof(arr[0])); //calculate the size of the array

	rearrange(arr, n); //call the function with the parameters
	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; //print the array in index i

	return 0;
}
