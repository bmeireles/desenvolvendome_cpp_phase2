//Selection sort
//Source code: https://www.geeksforgeeks.org/selection-sort/
//Time complexity: O(N²)
//Auxilary space: O(1)


#include <bits/stdc++.h>
using namespace std;

//Swap function
void swap(int *xp, int *yp) //function to swao 2 elements in the array. Receives as parameters 2 indexes
{
	int temp = *xp; //the temporary variable receives the value in index xp
	*xp = *yp; //xp becomes yp
	*yp = temp; //yp receives the value in the temp variable, wuich is from xp, completing the swap
}

void selectionSort(int arr[], int n) //function to order the array. Receives as parameters an array, and the size
//of the array
{
	int i, j, min_idx; //variables i and j to loop through the array, and min_idx to save the index of the smaller element

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++) //for every index in the array we will compare the element in index i with all the others
    //and find the smallest element
	{
	
		// Find the minimum element in unsorted array
		min_idx = i; //the minimum element starts with i
		for (j = i+1; j < n; j++) //for every element other than i
		if (arr[j] < arr[min_idx]) //if the element in j is smaller than the minimum
			min_idx = j; //j becomes the index of the minimum value

		// Swap the found minimum element with the first element
		if(min_idx!=i) //if the minimum element is not in index i, we have to swap the elements
			swap(&arr[min_idx], &arr[i]); //call the index function and swap the index of the minimum element with the
            //element in index i
	}
}

//Function to print an array
void printArray(int arr[], int size)
{
	int i; 
	for (i=0; i < size; i++) //for every index in the array
		cout << arr[i] << " "; //print the element in index i
	cout << endl;
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 25, 12, 22, 11}; //create an array
	int n = sizeof(arr)/sizeof(arr[0]); //calculate the size of the array
	selectionSort(arr, n); //call the function selectionSort to sort the array
	cout << "Sorted array: \n";
	printArray(arr, n); //call the function printArray, to check in the array was sorted
	return 0;
}
