//Find missing number
//Source code: https://www.geeksforgeeks.org/find-the-missing-number/
//Time Complexity: O(N)
//Auxiliary Space: O(N)


//First approach: hashing /counting
#include <bits/stdc++.h>
using namespace std;

void findMissing(int arr[], int N) //function to find the missing number of an array. Receives as parameters an array,
// and the size of the array
{
	int i; //variable for iteration
	int temp[N + 1]; //create a temporary array, one index greater than the original array, to store the counting of
	//the numbers
	for(int i = 0; i <= N; i++){ //for every index in temp
	temp[i] = 0; //initialize the value as 0
	}

	for(i = 0; i < N; i++){ //for every index in array
	temp[arr[i] - 1] = 1; //if array[i]-1 is an existing index in temp, mark this index in temp as 1. This way we know
	//that the value exists in array[i]
	}


	int ans; //variable to save the missing number
	for (i = 0; i <= N ; i++) { //for every index in temp
		if (temp[i] == 0) //if there is any index marked as 0, this is the missing number
			ans = i + 1; //the missing number is the index+1
	}
	cout << "The missing number is: "<< ans << endl;
}

/* Driver code */
int main()
{
	int arr[] = { 1, 3, 7, 5, 6, 2 }; //create an array
	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
	findMissing(arr, n); //call the function to find the missing number
}
