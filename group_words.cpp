//Group words with same set of characters
//Source code: https://www.geeksforgeeks.org/print-words-together-set-characters/
//Time complexity: O(n*k) where n is number of words in dictionary and k is maximum length of a word.
//Auxiliary Space: O(n*k), where n is number of words in dictionary and k is maximum length of a word.


#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

// Generates a key from given string. The key contains all unique characters of a given string in
// sorted order consisting of only distinct elements.
string getKey(string &str) //function to generate a key for a string. Receives as parameter the string
//reference
{
	bool visited[MAX_CHAR] = { false }; //create an array of boolean type, with size max_char, an initialize
    //all spaces as false

	// store all unique characters of current word in key
	for (int j = 0; j < str.length(); j++) //for every character in a string
		visited[str[j] - 'a'] = true ; //mark the index of the calculation (str[j] - 'a') in visited as true.
	string key = ""; //initialize the key string as empty
	for (int j=0; j < MAX_CHAR; j++) //for every index in visited array
		if (visited[j]) //if the value in index j is true
			key = key + (char)('a'+j); //the key is updated as the previous key plus the character of the ascii (of
            // 'a' + the ascii of index j)
	return key;
    //the operation str[j] - 'a' returns a number, which is the result of the subtraction 
    //of the ascii's values from each character. Example: 'b' - 'a' = 98 - 97 = 1
}

// Print all words together with same character sets.
void wordsWithSameCharSet(string words[], int n)
{
	// Stores indexes of all words that have same
	// set of unique characters.
	unordered_map <string, vector <int> > Hash;

	// Traverse all words
	for (int i=0; i<n; i++)
	{
		string key = getKey(words[i]);
		Hash[key].push_back(i);
	}

	// print all words that have the same unique character set
	for (auto it = Hash.begin(); it!=Hash.end(); it++)
	{
	for (auto v=(*it).second.begin(); v!=(*it).second.end(); v++)
		cout << words[*v] << ", ";
	cout << endl;
	}
}

// Driver program to test above function
int main()
{
	string words[] = { "may", "student", "students", "dog",
				"studentssess", "god", "cat", "act", "tab",
				"bat", "flow", "wolf", "lambs", "amy", "yam",
				"balms", "looped", "poodle"};
	int n = sizeof(words)/sizeof(words[0]);
	wordsWithSameCharSet(words, n);
	return 0;
}
