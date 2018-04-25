 /**
 *Joshua Whiteford
 *Lab 14
 *File Processing
 */

/**< Preprocessor Directives */
#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    /**< Varable Declraton  */
    double Max = 0, Min = 0, avg, sum, top, toverb, standD, tempa, tempb, Val;
    int n = 0, i = 0, Asc;

    /**< Settng up an array to store all the value in the input file  */
    int readin[1000];

    /**< creating a txt file called Display that the program can write too */
    ofstream Display( "Display.txt", ios::out );

    /**< Allows the program to input or read from a file called Readin */
    ifstream Readin( "ReadIn.txt", ios::in );

    /**< Checks to See if the Display File Opened! */
	if (!Display)
	{
		cerr << "The Display File Failed to Open!" << endl;
		exit( 1 );
	}
	/**< Checks to See if the Readin File Opened! */
	if (!Readin)
	{
		cerr << "The ReadIn File Failed to Open!" << endl;
		exit( 1 );
	}

	/**< Sends the Program into a loop until all of the data in the Readin file has be inputted! */
	while(Readin >> Val)
    {
        /**< Sets each values in the readin[] array to be equal to the values being read in at that time from the input file */
        readin[n] = Val;

        /**< Loop to find the max */
        if(n == 0)
        {
            Max = Val;
        }

        else if( Val > Max)
        {
            Max = Val;
        }

        /**< Looop to find the Min */
        if(n == 0)
        {
            Min = Val;
        }
        else if( Val < Min)
        {
            Min = Val;
        }
        /**< Counts the amount of values in the inputed file */
        n++;
        cout << Val << endl;

        /**< Adds all the inputted values  */
        sum = sum + Val ;

        /**< Calculation to get the average */
        avg = sum/n;

        /**< Calculations to get the Standard Deviation */
        top = top + pow( Val - avg , 2 );
        toverb = top/(n-1);
        standD = sqrt(toverb);
    }

    /**< Displaying the results to the User */
    cout << "max is: " << Max << endl;
    cout << "min is: " << Min << endl;
    cout << "average is: " << avg << endl;
    cout << "stddev is: " << standD << endl;

    /**< Loop to display the results in ascending order */
    for ( i = 0; i < n-1; i++)
    {
        /**< Loop to determine which elements are bigger in order to sort them by size */
        if(readin[i] > readin[i+1])
        {
            tempa = readin[i];
            tempb = readin[i+1];
            readin[i] = tempb;
            readin[i+1] = tempa;
            i=i-2;
        }
    }

    cout << "For ascending order, enter '1'. For descending order, enter '2'" << endl;
    cin >> Asc;

    if(Asc == 1)
    {
        /**< Output to the Display txt file in ascending order */
        for(i=0;i<n;i++)
        {
            Display << readin[i] << endl;
            cout << readin[i] << endl;
        }
    }
    else if(Asc == 2)
    {
        /**< Output to the Display txt file in descending order */
        for(i=n-1;i>=0;i--)
        {
            Display << readin[i] << endl;
            cout << readin[i] << endl;
        }
    }

    return 0;
}
