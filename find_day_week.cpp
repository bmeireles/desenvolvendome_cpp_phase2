//Tomohiko Sakamoto’s Algorithm- Finding the day of the week
//Time Complexity: O(1)
//Auxiliary Space: O(1)


#include <iostream>
using namespace std;

int day_of_the_week(int year, int month, int day) //Function to calculate the day of the week, according to a given
//date. Receives as parameters a year, month and day values.
{
    // Calculate the day of the week given a date (0=sunday, 1=monday, ..., 6=saturday)
    int day_week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
    //month (1=january, 2=february...12=december)
    // year/4 is necessary because we have to know if the year is a leap year, to add in day in february
    // year/100 is done to exclude the leap years that are not multiple of 100
    // year/400 is done to exclude the leap years that are not multiple of 400


    // Print the day of the week
    cout << "Day of the week: ";
    switch (day_week) {
        case 0: cout << "Sunday"; break;
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
  }
  cout << endl;


}

int main(void)
{
	int day = 14, month = 11, year = 2017;
	day_of_the_week(year, month, day);
	return 0;
}
