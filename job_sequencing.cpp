//Job sequencing problem
//Source code: https://www.geeksforgeeks.org/job-sequencing-problem/
//Time Complexity: O(N2)
//Auxiliary Space: O(N)


#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job item. Because it is only used for data format, it is best to use a struct that a class
struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
};

// Comparator function for sorting jobs. By comparing job profits we can sort the array in decreasing order
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit); //if the profit of job a is greater, return true. If the profit of job b is 
	//greater than a, return false
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n) //function to sort jobs and find the maximum profit from specific jobs. Receives
//as parameters an array of jobs, and the size of the array
{
	// Sort all jobs according to decreasing order of profit, using the comparison function
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++) //for every index in n
		slot[i] = false; //mark the value in the index as false

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) { //for every index in n
		// Find a free slot of time for this job (Note that we start from the last possible slot, because nothing is
		//gained by scheduling it earlier, and scheduling it earlier could take the place of another job with a more
		//limited deadline.)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) { //for every index j in slots, look backwards
			// Free slot found
			if (slot[j] == false) { //if this slot is avalable for a job
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++) //for every index in slot
		if (slot[i]) //if slot[i] exists
			cout << arr[result[i]].id << " "; //print the value of the job id, wuich was selected in the result array
}

// Driver's code
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } }; //create an array of jobs

	int n = sizeof(arr) / sizeof(arr[0]); //calculate the size of the array
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	// Function call
	printJobScheduling(arr, n); //call the function printJobsScheduling and print the result
	return 0;
}

