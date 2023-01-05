//Tomohiko Sakamoto’s Algorithm- Finding the day of the week
//Source code: https://www.geeksforgeeks.org/tomohiko-sakamotos-algorithm-finding-day-week/
//Time Complexity: O(1)
//Auxiliary Space: O(1)


#include <bits/stdc++.h>
using namespace std;

// function to implement tomohiko
// sakamoto algorithm
int day_of_the_week(int y, int m, int d)
{
	// array with leading number of days values
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	
	// if month is less than 3 reduce year by 1
	if (m < 3)
		y -= 1;
	
	return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

// Driver Code
int main(void)
{
	int day = 13, month = 7, year = 2017;
	cout<<(day_of_the_week(year, month, day));
	return 0 ;
}

