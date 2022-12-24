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
double fractionalKnapsack(int W, struct Item arr[], int N) //function to solve the fractional knapsack problem. Receives
//as parameters the capacity w, the array of items, and the size of the array
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp); //call the sort function to sort the array based on the ratio of each item, using the
    //comparison function

	double finalvalue = 0.0; //we create a variable for the final value as a double because if can be a double

	// Looping through all items
	for (int i = 0; i < N; i++) { //for every item in the array
		
		// If adding Item won't overflow, add it completely
		if (arr[i].weight <= W) {  //if the weight of the item is smaller or equal to the total capacity
			W -= arr[i].weight; //subtract that weight from the total capacity
			finalvalue += arr[i].value; //and add the value of this item to the final value
		}

		// If we can't add current Item, add fractional part of it
		else { // if the weight of the item is greater than the total capacity
			finalvalue += arr[i].value * ((double)W / (double)arr[i].weight); //we add to the final value that item
            //value, but fractioned, the calculation is value times(current_total_capacity divided by the weight)
			break; //stop adding beacause this was the last one that could fit the capacity
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	int W = 50; //choose the total capacity
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; //create an array of items

	int N = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array

	// Function call
	cout << fractionalKnapsack(W, arr, N); //call the function fractionalKnapsack and return the final value
	return 0;
}
