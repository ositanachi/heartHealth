#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
void heading();
void evaluate_cholesterol(int, int, string&, string&);
void evaluate_blood_pressure(int, int, string&, string&);
float evaluate_ratio(int, int, string&);
string outputName(string, char);

void heading()
{
	cout << "**********************************************************\n";
	cout << "Osi Otugo\n";
	cout << "@02662492\n";
	cout << "November 16, 2015\n";
	cout << "Lab 11\n";
	cout << "Read patient record data\n";
	cout << "**********************************************************\n";
}

int main()
{
	//Declare variables used
	int numOfPatients, totalVisits, hdlLevel, ldlLevel, systolicBP, diastolicBP;
	char patientType;
	string name, hdlEval = "", ldlEval = "", diastolicEval = "", 
		systolicEval = "", ratioEval = "";
	ifstream myFile;
	myFile.open("infile.txt");
	//Prompt user for the number of patient records (s)he wants to view)
	cout << "Enter the number of patient records:  ";
	cin >> numOfPatients;
	cout << endl;
	//Counter controlled loop that terminates once it gets to the user's input
	for (int patients = 0; patients < numOfPatients; patients++)
	{
		//Records the patient's name, type (new or current), amount of visits
		myFile >> name >> patientType >> totalVisits;
		//Calls the function value return function, output name to output the patient's status
		cout << outputName(name, patientType) << endl;
		//Counter controlled loop that terminates once its read the patient's file
		for (int visits = 1; visits <= totalVisits; visits++)
		{
			//Store data from patient's file into respective variables
			myFile >> hdlLevel >> ldlLevel >> systolicBP >> diastolicBP;
			//Call the evaluate cholesterol function
			evaluate_cholesterol(hdlLevel, ldlLevel, hdlEval, ldlEval);
			//Call the evaluate blood pressure function
			evaluate_blood_pressure(systolicBP, diastolicBP, systolicEval, diastolicEval);
			cout << "DATA SET " << visits << endl;
			cout << "Cholesterol Profile" << endl;
			cout << "  HDL: " << hdlLevel << " LDL: " << ldlLevel << endl;
			//Following statement calls the value returning function, evaluate_ratio
			cout << fixed << "  Ratio: " << setprecision(4) 
				<< evaluate_ratio(hdlLevel, ldlLevel, ratioEval) << endl;
			cout << "  HDL is " << hdlEval << endl;
			cout << "  LDL is " << ldlEval << endl;
			cout << "  " << ratioEval << endl;
			cout << "Blood Pressure Profile" << endl;
			cout << "  Systolic: " << systolicBP << "  Diastolic: " << diastolicBP << endl;
			cout << "  Systolic reading is " << systolicEval << endl;
			cout << "  Diastolic reading is " << diastolicEval << endl << endl;
		}
	}
	system("pause");
}
//Function evaluates the cholesterol
void evaluate_cholesterol(int hdlLevel, int ldlLevel, string& hdlEval, string& ldlEval)
{
	/*Two sets of nested if statements to determine the interpretation of the HDL and LDL levels*/
	if (hdlLevel >= 60)
		hdlEval = "Excellent";
		else if (hdlLevel >= 40)
			hdlEval = "Is okay";
			else
				hdlEval = "Too low";
	if (ldlLevel >= 190)
		ldlEval = "Very high";
		else if (ldlLevel >= 160)
			ldlEval = "High";
			else if (ldlLevel >= 130)
				ldlEval = "Borderline High";
				else if (ldlLevel >= 100)
					ldlEval = "Near Optimal";
					else
						ldlEval = "Optimal";
}
//Function evaluates the blood pressure
void evaluate_blood_pressure(int systolicBP, int diastolicBP, string& systolicEval, string &diastolicEval)
{
	/*Two sets of nested if statements to determine what the systolic blood pressure 
	and diastolic blood pressure interpretation should be*/
	if (systolicBP < 120)
		systolicEval = "Optimal";
		else if (systolicBP < 130)
			systolicEval = "Normal";
			else if (systolicBP < 140)
				systolicEval = "Normal High";
				else if (systolicBP < 160)
					systolicEval = "Stage 1 hypertension";
					else if (systolicBP < 180)
						systolicEval = "Stage 2 hypertension";
						else
							systolicEval = "Stage 3 hypertension";
	if (diastolicBP < 80)
		diastolicEval = "Optimal";
		else if (diastolicBP < 85)
			diastolicEval = "Normal";
			else if (diastolicBP < 90)
				diastolicEval = "High normal";
				else if (diastolicBP < 100)
					diastolicEval = "Stage 1 hypertension";
					else if (diastolicBP < 110)
						diastolicEval = "Stage 2 hypertension";
						else
							diastolicEval = "Stage 3 hypertension";
}
//Function returns the ratio of hdl to ldl
float evaluate_ratio(int hdlLevel, int ldlLevel, string& ratioEval)
{
	float ratio;
	//Cast variable into a float to perform float division
	ratio = float(hdlLevel) / float(ldlLevel);
	//Simple if statement to determine what the string should contain
	if (ratio > 0.3)
		ratioEval = "Ratio of HDL to LDL good";
		else
			ratioEval = "Ratio of HDL to LDL is not good";
	//Return ratio
	return ratio;
}
//Following function outputs the patient's name and type (new, current, returning, or referral)
string outputName(string name, char patientType) 
{
	//Switch statement to output the patient's type (current, returning, new, or referral)
	switch (patientType)
	{
	case ('C') :
		return "Current Patient's Name- " + name;
	case ('N') :
		return "New Patient's Name- " + name;
	case ('R') :
		return "Returning Patient's Name-  " + name;
	case ('F') :
		return "Referral Patient's Name- " + name;
	}
}
/*
Enter the number of patient records:  4

Current Patient's Name- Jones
DATA SET 1
Cholesterol Profile
HDL: 60 LDL: 124
Ratio: 0.4839
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 130  Diastolic: 84
Systolic reading is Normal High
Diastolic reading is Normal

DATA SET 2
Cholesterol Profile
HDL: 65 LDL: 121
Ratio: 0.5372
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 133  Diastolic: 80
Systolic reading is Normal High
Diastolic reading is Normal

DATA SET 3
Cholesterol Profile
HDL: 70 LDL: 120
Ratio: 0.5833
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 130  Diastolic: 81
Systolic reading is Normal High
Diastolic reading is Normal

New Patient's Name- Smith
DATA SET 1
Cholesterol Profile
HDL: 30 LDL: 195
Ratio: 0.1538
HDL is Too low
LDL is Very high
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 120  Diastolic: 85
Systolic reading is Normal
Diastolic reading is High normal

Referral Patient's Name- Williams
DATA SET 1
Cholesterol Profile
HDL: 45 LDL: 185
Ratio: 0.2432
HDL is Is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 190  Diastolic: 112
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension

DATA SET 2
Cholesterol Profile
HDL: 50 LDL: 181
Ratio: 0.2762
HDL is Is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 193  Diastolic: 115
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension

Returning Patient's Name-  Foster
DATA SET 1
Cholesterol Profile
HDL: 55 LDL: 165
Ratio: 0.3333
HDL is Is okay
LDL is High
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 163  Diastolic: 115
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 3 hypertension

DATA SET 2
Cholesterol Profile
HDL: 65 LDL: 145
Ratio: 0.4483
HDL is Excellent
LDL is Borderline High
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 167  Diastolic: 95
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 1 hypertension

DATA SET 3
Cholesterol Profile
HDL: 57 LDL: 165
Ratio: 0.3455
HDL is Is okay
LDL is High
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 163  Diastolic: 105
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 2 hypertension

DATA SET 4
Cholesterol Profile
HDL: 59 LDL: 163
Ratio: 0.3620
HDL is Is okay
LDL is High
Ratio of HDL to LDL good
Blood Pressure Profile
Systolic: 165  Diastolic: 108
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 2 hypertension

Press any key to continue . . .
*/