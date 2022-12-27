//Minimize Cash Flow among a given set of friends who have borrowed money from each other
//Source code: https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
//Time Complexity: O(N²)


#include<iostream>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[]) //function to find the minimum element in an array. Receives an array as parameter
{
	int minInd = 0; //variable to store the index, starts with 0
	for (int i=1; i<N; i++) //for every index in the array
		if (arr[i] < arr[minInd]) //if the element in index i is smaller than the element in the minimum index
			minInd = i; //the minimum index receives i as the new minimum
	return minInd; //returns the index with the minimum value
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[]) //function to find the maximum element in an array.Receives an array as parameter
{
	int maxInd = 0; //variable to store the index, starts with 0
	for (int i=1; i<N; i++) //for every index in the array
		if (arr[i] > arr[maxInd]) //if the element in index i is greater than the element in the maximum index
			maxInd = i; //the maximum index receives i as the new maximum
	return maxInd; //returns the index with maximum value
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y) 
{
	return (x<y)? x: y; //if x is smaller than y, return x, if y is smaller than x, return y.
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[])
{
	// Find the indexes of minimum and maximum values in amount[]
	// amount[mxCredit] indicates the maximum amount to be given
	//				 (or credited) to any person .
	// And amount[mxDebit] indicates the maximum amount to be taken
	//				 (or debited) from any person.
	// So if there is a positive value in amount[], then there must
	// be a negative value
	int mxCredit = getMax(amount), mxDebit = getMin(amount);

	// If both amounts are 0, then all amounts are settled
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	// Find the minimum of two amounts
	int min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	// If minimum is the maximum amount to be
	cout << "Person " << mxDebit << " pays " << min
		<< " to " << "Person " << mxCredit << endl;

	// Recur for the amount array. Note that it is guaranteed that
	// the recursion would terminate as either amount[mxCredit]
	// or amount[mxDebit] becomes 0
	minCashFlowRec(amount);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
	// Create an array amount[], initialize all value in it as 0.
	int amount[N] = {0};

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int p=0; p<N; p++)
	for (int i=0; i<N; i++)
		amount[p] += (graph[i][p] - graph[p][i]);

	minCashFlowRec(amount);
}

// Driver program to test above function
int main()
{
	// graph[i][j] indicates the amount that person i needs to
	// pay person j
	int graph[N][N] = { {0, 1000, 2000},
						{0, 0, 5000},
						{0, 0, 0},};

	// Print the solution
	minCashFlow(graph);
	return 0;
}
