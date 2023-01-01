//Reorder an array according to given indexes
//Source code: https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/


#include<iostream>
using namespace std;

//First solution: with auxilary array
//Time Complexity: O(n) 
//Auxiliary Space: O(n)

// Function to reorder elements of arr[] according to index[]
void reorder(int arr[], int index[], int n)
{
	int temp[n]; //create an auxilary array, the same size of the arr[]

	// arr[i] should be present at index[i] index
	for (int i=0; i<n; i++) //for every index in temp
		temp[index[i]] = arr[i]; //the element in arr[i] is copied to temp at the position index[i] (the position is
		//the element in index[i])
 
	// Copy temp[] to arr[]
	for (int i=0; i<n; i++) //for every index in array
	{
		arr[i] = temp[i]; //copy the element in temp at the same index in arr[]
		index[i] = i; //the element becomes the same number as the index, in this way we can reorder this array
	}
}

// Driver program
int main()
{
	int arr[] = {50, 40, 70, 60, 90}; //create an array
	int index[] = {3, 0, 4, 1, 2}; //create an array with index positions
	int n = sizeof(arr)/sizeof(arr[0]); //calculate the size of the array

	reorder(arr, index, n); //call the function with the array we would like to reorder

	cout << "Reordered array is: \n";
	for (int i=0; i<n; i++)
		cout << arr[i] << " "; //print the reordered array of elements

	cout << "\nModified Index array is: \n";
	for (int i=0; i<n; i++)
		cout << index[i] << " "; //print the reordered array of indexes
	return 0;
}
