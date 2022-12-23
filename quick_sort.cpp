//Quick sort
//Source code: https://www.geeksforgeeks.org/quick-sort/
//Time complexity: O(N logN)
//Auxilary space: O(logN)

/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a; //the temporary variable receives the value from a
	*a = *b; //a receives the element from b
	*b = t; //b receives the element from the temporary vatiable
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high) //function to execute the partition of the array. Receives as parameters
//an array, the low and high indexes
{
	int pivot = arr[high]; // we start with the pivot as the last element of the array
	int i = (low - 1); // Index of the smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) { // for every element in the range of the subarray between low and high
		if (arr[j] < pivot) {// If current element is smaller than the pivot
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]); //call the function swap, to swap the elements in index i and j
		}
	}
	swap(&arr[i + 1], &arr[high]); //after the loop, the new i(+1) is the index where we stopped moving the element,
	//so that every element in the left is smaller than him, and every element in the right is greater than him. Now
	//we can swap the pivot with the elemetn in i+1
	return (i + 1); //return the value of the new pivot
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high) //function to sort the array. Receives as parameters an array, a low
//and hight indexes
{
	if (low < high) { //if the lowest index is smaller than the highest, we can execute the partition. If they are
	//equal or higher, it means the array is already sorted
		/* pi is partitioning index, arr[p] is now at right place */
		int pi = partition(arr, low, high); //pi is the pivot returned from the partition function

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1); //call recursively the quicksort function, to sort the elements from low to 
		//the pivot -1
		quickSort(arr, pi + 1, high); //call recursively the quicksort function, to sort the elements from the pivot+1 to 
		//the high index
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) //for every index in the array
		cout << arr[i] << " "; //print the element in index i
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 }; //create an array
	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
	quickSort(arr, 0, n - 1); //call the function quicksort to sort the array
	cout << "Sorted array: \n";
	printArray(arr, n); //print the array sorted
	return 0;
}

