//Common characters in n strings
//Source code: https://www.geeksforgeeks.org/common-characters-n-strings/
//Time complexity : O(n) 
//Auxiliary Space : O(1)


#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26; //variable for the maximum number of characters
//The const keyword specifies that a variable's value is constant and tells the compiler to prevent
// the programmer from modifying it

void commonCharacters(string str[], int n) //function to find the common characters between multiple strings. Receives as
//parameters an array of strings, and the size n of the array
{
	// primary array for common characters
	// we assume all characters are seen before.
	bool prim[MAX_CHAR]; //prim is an array the size of max_char of boolean type
	memset(prim, true, sizeof(prim)); //marks all spaces in prim as true

	// for each string
	for (int i = 0; i < n; i++) { //for every string in the array

		// secondary array for common characters
		// Initially marked false
		bool sec[MAX_CHAR] = { false }; //sec is also an array the size of max_char, with spaces marked false

		// for every character of ith string
		for (int j = 0; str[i][j]; j++) {

			// if character is present in all strings before, mark it.
			if (prim[str[i][j] - 'a']) //if the ascii of the character in str[i][j] minus the ascii of a(97)
			//returns a valid number of index for the array prim, and there is an element in 'true'
				sec[str[i][j] - 'a'] = true; //mark in the second array in the same index as true
		}
		//the operation str[i][j] - 'a' returns a number, which is the result of the subtraction 
        //of the ascii's values from each character. Example: 'b' - 'a' = 98 - 97 = 1

		// copy whole secondary array into primary
		memcpy(prim, sec, MAX_CHAR); //memcpy() is used to copy a block of memory from a location to another
	}

	// displaying common characters
	for (int i = 0; i < 26; i++) //for every index in prim
		if (prim[i]) //if the element in index i exists
			printf("%c ", i + 'a'); //print the character of ascii value i+'a'
}

// Driver's Code
int main()
{
	string str[] = { "geeksforgeeks", "gemkstones", "acknowledges", "aguelikes" }; //create an array of strings
	int n = sizeof(str)/sizeof(str[0]); //calculate the size of the array
	commonCharacters(str, n); //call the function commonCharacters to print the results
	return 0;
}
