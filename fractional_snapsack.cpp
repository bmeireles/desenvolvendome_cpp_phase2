//Fractional snapsack problem
//Source code:
//Time Complexity: O(N log N)
//Auxiliary Space: O(N)


#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and corresponding value of Item
struct Item {
	int value, weight; //the item has a value and a weight variable

	// Constructor
	Item(int value, int weight) //the constructor has the same name of the class/struct
	{
		this->value = value;
		this->weight = weight;
	}
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b) //function to compare items and sort the list. Receives as parameters 2 items
{
	double r1 = (double)a.value / (double)a.weight; //calculate the ratio of item a(value divided by weight)
	double r2 = (double)b.value / (double)b.weight; //calculate the ratio of item b(value divided by weight)
	return r1 > r2; //compare the ratio of a with the ratio of b. If ratio of a(r1) is greater, returns true. If ratio
    //of b(r2) is greater, returns false.
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			finalvalue
				+= arr[i].value
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
