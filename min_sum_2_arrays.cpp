//Minimum sum of product of 2 arrays
//Source code: https://www.geeksforgeeks.org/minimum-sum-product-two-arrays/
//Time complexity: O(N)
//Auxilary space: O(1)


#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum product
int minproduct(int a[], int b[], int n, int k) //function to find the minimum sum of the product of 2 arrays. Receives
//as parameters 2 arrays, the size of both arrays(it should be the same) and the number k of modifications allowed
{
	int diff = 0, res = 0; //difference and result variables
	int temp; //temporary variable
	for (int i = 0; i < n; i++) { //for every index in the range of the arrays

		// Find product of current elements and update
		// result.
		int pro = a[i] * b[i]; //pro is the product of the element in index i an the array and the same index in array b
		res = res + pro; //sum that product in res. In this way we will have the total sum, and the maximum sum in res

		// If both product and b[i] are negative, we must
		// increase value of a[i] to minimize result.
		if (pro < 0 && b[i] < 0) //because we want the minimum product possible, if b[i] and pro are negative, it means
		//that a[i] is positive, so increasing a[i] will make pro even smaller
			temp = (a[i] + 2 * k) * b[i]; //temp is the new product of a[i] and b[i], with a[i] increased 2 times k (2
			//modifications are enough)

		// If both product and a[i] are negative, we must
		// decrease value of a[i] to minimize result.
		else if (pro < 0 && a[i] < 0) //if a[i] and pro are negative, it means that b[i], is positive, but we cant modify
		//b[i]. So we decrease a[i] to make the product smaller
			temp = (a[i] - 2 * k) * b[i]; //temp is the new product of a[i] and b[i], with a[i] decreased 2 times k

		// Similar to above two cases for positive product.
		else if (pro > 0 && a[i] < 0) //if the product is positive and a[i] is negative, then b[i] is also negative,
		//so we have to increase a[i]
			temp = (a[i] + 2 * k) * b[i]; //temp is the new product of a[i] and b[i], with a[i] increased 2 times k
		else if (pro > 0 && a[i] > 0) //if the product is positive and a[i] is also positive, then b[i] is negative,
		//so we have to decrease a[i] 
			temp = (a[i] - 2 * k) * b[i]; //temp is the new product of a[i] and b[i], with a[i] decreased 2 times k

		// Check if current difference becomes higher than
		// the maximum difference so far.
		int d = abs(pro - temp); //d is the absolute difference between the product and the temporary product
		if (d > diff) // if the difference is greater than the one saved in diff, 
			diff = d; //we save this value in the diff varible so we wont lose in in the loop. This way the greatest
			//difference will be saved in the diff variable
	}

	return res - diff; //return the total result minus the biggest difference, that is the minimum sum
}

// Driver function
int main()
{
	int a[] = { 2, 3, 4, 5, 4 }; //create first array, which can be modified
	int b[] = { 3, 4, 2, 3, 2 }; //create second array
	int n = 5, k = 3; //n is the size of both arrays and k is the number of modifications allowed
	cout << minproduct(a, b, n, k) << endl; //call the function minproduct and print the result
	return 0;
}

