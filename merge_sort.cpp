//Merge sort
//Source code: https://www.geeksforgeeks.org/merge-sort/
//Time Complexity: O(N log(N))
//Auxiliary Space: O(n)

#include <iostream>
using namespace std;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right) //function to merge 2 subarrays.
//Receives as parameters an array, the left, right and the middle index 
{
	auto const subArrayOne = mid - left + 1; //variable to save the size of the subarray 1
	auto const subArrayTwo = right - mid; //variable to save the size of the subarray 2

	// Create temp arrays
	auto *leftArray = new int[subArrayOne], //create a temporary array for the elements in suabarray 1
		*rightArray = new int[subArrayTwo]; //create a temporary array for the elements in subarray 2

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++) //for every index in leftarray
		leftArray[i] = array[left + i]; //leftarray receives the element in the original array
	for (auto j = 0; j < subArrayTwo; j++) //for every index in rightarray
		rightArray[j] = array[mid + 1 + j]; //rightarray receives the element from the original array, from mid to the end

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne //while the initial index of subarray1 is smaller than subarray 1
		&& indexOfSubArrayTwo < subArrayTwo) { //and the initial index of subarray2 is smaller than subarray 2
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) { //if the element in the leftarray is 
		//smaller or equal to the element in the right array, the element in the left comes first 
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; //so the original array receives the element
			//from the left array
			indexOfSubArrayOne++; //add 1 to the initial index of subarray 1 to continue the loop
		}
		else { //if the element in the right array is smaller, this element comes first in the sorted array
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; //so the original array receives the element
			//from the right array
			indexOfSubArrayTwo++; //add 1 to the initial index of subarray 2 to continue the loop
		}
		indexOfMergedArray++; //add 1 to the initial index of the merged array to continue the loop
	}
	// Copy the remaining elements of left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) { //while the initial index of subarray 1 is smaller than subarray 1
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; //the original array is going to receive an 
		//element from leftarray in the correct order
		indexOfSubArrayOne++; //add 1 to the initial index of subarray 1 to continue the loop
		indexOfMergedArray++; //add 1 to the initial index of the merged array to continue the loop
	}
	// Copy the remaining elements of right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) { //while the initial index of subarray 2 is smaller than subarray 2
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; //the original array is going to receive an
		//element from the rightarray in the correct order
		indexOfSubArrayTwo++; // add 1 to the initial index of subarray 2 to continue the loop
		indexOfMergedArray++; //add 1 to the initial index of subarray 2 to continue the loop
	}
	delete[] leftArray; //delete the left and right arrays
	delete[] rightArray;
}

// begin is for left index and end is right index of the sub-array of arr to be sorted */
void mergeSort(int array[], int const begin, int const end) //function to order the array using the function merge.
//Receives as parameters an array, and the indexes of the beginning and end of the array
{
	if (begin >= end) //if the begin index is greater or equal to the end index, there is no more subarrays to split
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2; //calculate the middle index
	mergeSort(array, begin, mid); //call the function recursively from the beginning to the middle of the array
	mergeSort(array, mid + 1, end); //call the function recursively from the middle to the end of the array
	merge(array, begin, mid, end); //call the merge function to merge the subarrays
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size) 
{
	for (auto i = 0; i < size; i++) //for every index in array
		cout << A[i] << " "; //print the element in index i
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 }; //create an array
	auto arr_size = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array

	cout << "Given array is \n";
	printArray(arr, arr_size); //print the initial array

	mergeSort(arr, 0, arr_size - 1); //call the function mergeSort

	cout << "\nSorted array is \n";
	printArray(arr, arr_size); //print the sorted array
	return 0;
}

