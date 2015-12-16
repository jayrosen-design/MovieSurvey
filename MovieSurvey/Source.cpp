//Jay Rosen
// This program calculates the Average and Mode for number of movies watched by college students in 1 month
#include <iostream>
using namespace std;

// SurveyStats class declaration
class SurveyStats
{
private:
	int *students,									  //pointer to students array of ints
		numStudents,							  	 //size of students array
		average,									//hold average
		mode;									   //hold mode
	void getMovies(int[], int);
	void sortSurvey(int[], int);
	void setAverage(int[], int);
	void setMode(int[], int);


public:
	void getSurvey();
	int getInput();
	void validate(int& n);


}; // End SurveyStats class declaration


   // Program that uses the SurveyStats class




   /**************************************************************
   *               SurveyStats::getStudents                      *
   *		Get the number of students who took the survey		  *
   *      and dynamically allocate into a new array				  *
   **************************************************************/
void SurveyStats::getSurvey()
{
	//validate input
	numStudents = getInput();

	//dynamic allocation of students array
	students = new int[numStudents];

	//pass array to getMovies
	getMovies(students, numStudents);

}

/**************************************************************
*               SurveyStats::getMovies	                        *
*	Get the number of movies each surveyed student watched      *
**************************************************************/
void SurveyStats::getMovies(int students[], int numStudents)
{
	cout << "\n\t How many movies did each participant watch last month?\n\n";

	//Iterate question for number of students surveyed and validate input
	for (int count = 0; count < numStudents; count++)
	{
		cout << "\t\tStudent " << (count + 1) << ": ";
		students[count] = getInput();
	}

	//Pass array to sortSurvey
	sortSurvey(students, numStudents);
}

/**************************************************************
*               SurveyStats::sortSurvey	                       *
*	Sort the dynamic allocated array into ascending order     *
**************************************************************/
void SurveyStats::sortSurvey(int students[], int numStudents)
{

	for (int count = 0; count < numStudents; count++)
	{
		for (int j = count + 1; j < numStudents - 1; j++)
		{
			if (students[count] > students[j])
			{
				int temp = students[count];
				students[count] = students[j];
				students[j] = temp;
			}
		}
	}

	//Pass the sorted array to setAverage and setMode
	setAverage(students, numStudents);
	setMode(students, numStudents);

}


/******************************************************
*	            SurveyStats::setAverage               *
*	Determine Average of array  and display average   *
******************************************************/

void SurveyStats::setAverage(int students[], int numStudents)
{

	int number = students[0];
	int average = 0;
	int total = 0;

	for (int count = 0; count < numStudents; count++)
	{
		total += students[count];
	}
	average = total / numStudents;

	cout << "\n\n\t\tAverage : " << average << endl;

}




/**************************************************
*		      SurveyStats::setMode                  *
*	Determine Mode of array and display Mode        *
****************************************************/

void SurveyStats::setMode(int students[], int numStudents)
{

	int number = students[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i<numStudents; i++)
	{
		if (students[i] == number)
		{
			countMode++;
		}
		else
		{
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1;
			number = students[i];
		}
	}

	cout << "\t\tMode : " << mode << " \n\n\t\t";
}




/*************************************************************
*                 SurveyStats::getInput                      *
*	Get input from user and send to validate function.		 *
*************************************************************/
int SurveyStats::getInput()
{
	int num;
	cin >> num;

	validate(num);

	return num;
}

/************************************************************************
*	                     SurveyStats::validate                          *
*	Determine if input is non-integer and display error message.        *
************************************************************************/
void SurveyStats::validate(int& n)
{
	while (!cin)
	{
		cin.sync();
		cin.clear();
		cout << "\n\n\t\t Error: Invalid input, try again: \n\t\t ";
		cin >> n;
	}
}

/*************************************
*                main               *
*************************************/

int main()
{

	cout << "\n\n\t On the first of every month, students at Santa Fe College";
	cout << "\n\t are survyed for how many movies they watched the previous month.";

	cout << "\n\n\t How many students participated in The Monthly Movie survey? ";

	SurveyStats SurveyTaker;
	SurveyTaker.getSurvey();

	system("pause");

	return 0;
}
