//Find the time after K minutes from given time
//Source code: https://www.geeksforgeeks.org/program-to-find-the-time-after-k-minutes-from-given-time/
//Time Complexity: O(1)
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
// function to obtain the new time
void findTime(string T, int K) //function to calculate the time after adding k minutes. Receives as parameters
// the initial time as a string T, and the k minutes to be added 
{

	// convert the given time in minutes
    //"21:39"
    // 01234 => positions
	int minutes = ((T[0] - '0') //the ascii of the number in T[0] minus the ascii of 0(48).Multiply the result by 10
					* 10 //because the value is in the first digit
				+ T[1] - '0') //sum the previous value with the ascii of the number in T[1] minus the ascii of 0(48).
					* 60 //Multiply everything by 60 to transform it in minutes
				+ ((T[3] - '0') //the ascii of the number in T[3] minus the ascii of 0(48).Multiply the result by 10
						* 10 //because the value is in the first decimal place
					+ T[4] - '0'); //sum the previous value with the ascii of the number in T[4] minus the ascii of 0(48).

	// Add K to current minutes
	minutes += K; //here we have the total minutes

	// Obtain the new hour and new minutes from minutes
	int hour = (minutes / 60) % 24; //calculate the hours in the total minutes by dividing it by 60, and then taking
	//the rest of the division by 24, because we want to presnt the hours in the hh:mm format

	int min = minutes % 60; //the minutes becomes the rest of the division by 60 

	// Print the hour in appropriate format
	if (hour < 10) { //if the hour is smaller than 10, we put a 0 before so we will have 2 digits
		cout << 0 << hour << ":";
	}
	else { //if it is greater than 10, print it as it is
		cout << hour << ":";
	}

	// Print the minute in appropriate format
	if (min < 10) {//if the minute is smaller than 10, we put a 0 before
		cout << 0 << min;
	}
	else { //if it is greater than 10, print it as it is
		cout << min;
	}
}

// Driver code
int main()
{

	string T = "21:39"; //create a string with the initial time

	int K = 43; //variable to store the minutes to bea added

	findTime(T, K); //call the function with the parameters
}
