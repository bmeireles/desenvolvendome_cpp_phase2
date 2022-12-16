//Fibonacci search
//Source code: https://www.geeksforgeeks.org/fibonacci-search/


#include <bits/stdc++.h>
using namespace std;

// Utility function to find minimum of two elements
int min(int x, int y) { //function to calculate the minimum number between 2 values
    return (x <= y) ? x : y; //if x is smaller or equal to y, return x. Else, return y
    }

/* Returns index of x if present, else returns -1 */
int fibMonaccianSearch(int arr[], int x, int n) //function that uses fibonacci numbers to search for an element in a 
//sorted array. Receives as parameters an array, the size of the array n, and the number x to be found.
{
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0; // (m-2)'th Fibonacci number
	int fibMMm1 = 1; // (m-1)'th Fibonacci number
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	// fibM is going to store the smallest Fibonacci Number greater than or equal to n. So we have to increase fibM
    //using the fibonacci formula, until it reaches n, or gets greater.
	while (fibM < n) { //while fibM is smaller than n
		fibMMm2 = fibMMm1; //fib2 receives the value of fib1
		fibMMm1 = fibM; //fib1 receives the value of fibM
		fibM = fibMMm2 + fibMMm1; //fibM receives the sum of fib2 and fib1. This continues until fibM reaches n
	}

	int offset = -1; //the offset marks the range of the array that has benn eliminated, starting from the front.
	//It will be updated in the loop

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */
	while (fibM > 1) {
		// Check if fibMm2 is a valid location
		int i = min(offset + fibMMm2, n - 1); //i receives the minimum number between offset+fib2 and n-1. This is
        //the index of fib2
		//Since fibMm2 marks approximately one-third of our array, as well as the indices it marks, are sure to be 
		//valid ones, we can add fibMm2 to offset and check the element at index i = min(offset + fibMm2, n). 

		// If x is greater than the value at index fibMm2, move the variables to 1 fibonacci numbers down and reset
		//the offset. This eliminites approx. 1/3 of the array
		if (arr[i] < x) { //if x is greater than the value in index i
			fibM = fibMMm1; //fib decreases 1 fibonacci number, which is fib1
			fibMMm1 = fibMMm2; //fib1 decreases 1 fibonacci number, which is fib2
			fibMMm2 = fibM - fibMMm1; //fib2 decreases 1 fibonacci number. because fib = fib1+fib2, fib2 = fib-fib1
			offset = i; //the new offset is i
		}

		// If x is smaller than the value at index fibMm2,move the variables to 2 fibonnaci numbers down.
		// This makes the elimination of approx.2/3 of the array
		else if (arr[i] > x) { //if x is smaller than the value in index i
			fibM = fibMMm2; //fib decreases 2 fibonacci numbers, which is fib2
			fibMMm1 = fibMMm1 - fibMMm2; //fib1 decreases 2 fibonacci numbers
			fibMMm2 = fibM - fibMMm1; //fib2 decreases 2 fibonacci numbers
		}

		/* element found. return index */
		else //if it is not smaller or greater, it is equal to x and the element was found
			return i; //return the index of the element
	}

	/* comparing the last element with x */
	if (fibMMm1 && arr[offset + 1] == x) //there might be a single element remaining for comparison, check 
	//if fibMm1 is 1. If Yes, compare x with that remaining element. If match, return index.
		return offset + 1;

	/*element not found. return -1 */
	return -1; //if nothing worked, the element is not in the array. Return -1
}

// Driver Code
int main()
{
	int arr[] = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235}; //create a sorted array
	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of n
	int x = 235; // create a number to find in the array
	int ind = fibMonaccianSearch(arr, x, n); //ind receives the result of the function
if(ind>=0) //if ind is greater or equal to 0, the number exists in the array
	cout << "Found at index: " << ind;
else // the number doesn't exist in the array
	cout << x << " isn't present in the array";

	return 0;
}

