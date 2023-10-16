// Name: Andrew Pinkerton
// Program Description: Payroll
// Date: 9/29/2023
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;


class payRoll
{
private:
	string fName, lName, jobTitle, empNum;

	double hWorked, wage, tax = .35, netPay, grossPay, OTWage, OTPay, OTHours;

	int ded;
public:
	void getData(ifstream& iFile, vector<payRoll>& Microsoft) //input data from file
	{

		payRoll temp;

		iFile >> temp.fName;

		iFile >> temp.lName;

		iFile.ignore();

		getline(iFile, temp.jobTitle);

		iFile >> temp.empNum;

		iFile >> temp.hWorked;

		iFile >> temp.wage;

		iFile >> temp.ded;

		Microsoft.push_back(temp);
	}
	bool calcOT(vector<payRoll>& Microsoft, int i, bool OT) // returns true if OTHours > 40
	{

		if (Microsoft[i]
			.hWorked > 40)

		{

			Microsoft[i]
				.OTWage = Microsoft[i]
				.wage * 1.5;

			Microsoft[i]
				.OTHours = Microsoft[i]
				.hWorked - 40;

			Microsoft[i]
				.OTPay = Microsoft[i]
				.OTHours * Microsoft[i]
				.OTWage;

			Microsoft[i]
				.grossPay = (40 * Microsoft[i]
					.wage) + Microsoft[i]
				.OTPay;

			OT = true;

		}

		else

		{

			Microsoft[i]
				.OTPay = 0;

			Microsoft[i]
				.OTWage = 0;

			Microsoft[i]
				.OTHours = 0;

			Microsoft[i]
				.grossPay = Microsoft[i]
				.hWorked * Microsoft[i]
				.wage;

		}

		return OT;
	}
	void taxDed(vector<payRoll>& Microsoft, int i) // finds applicable tax deduction
	{

		if (Microsoft[i]
			.ded <= 0)

		{

			Microsoft[i]
				.tax = .35;

		}

		else if (Microsoft[i]
			.ded == 1)

		{

			Microsoft[i]
				.tax = .3;

		}

		else if (Microsoft[i]
			.ded == 2)

		{

			Microsoft[i]
				.tax = .25;

		}

		else if (Microsoft[i]
			.ded == 3)

		{

			Microsoft[i]
				.tax = .2;

		}

		else if (Microsoft[i]
			.ded >= 4)

		{

			Microsoft[i]
				.tax = .15;

		}
	}
	void calcPay(vector<payRoll>& Microsoft, int i)
	{

		Microsoft[i]
			.tax = Microsoft[i]
			.tax * Microsoft[i]
			.grossPay; // this will take thet Microsoft[i].tax rate and multiply it by gross pay

		// determine net pay by reducing Microsoft[i].tax from gross pay

		Microsoft[i]
			.netPay = Microsoft[i]
			.grossPay - Microsoft[i]
			.tax; // Calculates net pay
	}
	void output(vector<payRoll>& Microsoft, int i, bool OT) // Output to console
	{

		int COL1 = 25;

		cout << fixed << left << setprecision(0);

		cout << setw(COL1) << "Name: " << Microsoft[i]
			.lName << ", " << Microsoft[i]
			.fName << endl;

		cout << setw(COL1) << "Job Title: " << Microsoft[i]
			.jobTitle << endl;

		cout << setw(COL1) << "Employee Number: " << Microsoft[i]
			.empNum << endl;

		cout << setw(COL1) << "Hours Worked: " << Microsoft[i]
			.hWorked << endl;

		if (OT == true)

		{

			cout << setw(COL1) << "Overtime Hours Worked: " << Microsoft[i]
				.OTHours << endl;

		}

		cout << setw(COL1) << setprecision(2) << "Hourly Wage: " << "$" << Microsoft[i]
			.wage << endl;

		cout << setw(COL1) << setprecision(0) << "Deductions Claimed: " << Microsoft[i]
			.ded << endl;

		cout << setw(COL1) << setprecision(2) << "Gross Pay: " << "$" << Microsoft[i]
			.grossPay << endl;

		cout << setw(COL1) << "Taxes Withheld: " << "$" << Microsoft[i]
			.tax << endl;

		cout << setw(COL1) << "Net Pay: " << "$" << Microsoft[i]
			.netPay << endl << endl;
	}
};

int main()
{

	vector<payRoll> Microsoft;

	ifstream iFile;

	iFile.open("input.txt");

	int i = 0;

	while (
		!iFile.eof()
		)

	{

		bool OT = false;

		getData(iFile, Microsoft);

		OT = calcOT(Microsoft, i, OT);

		taxDed(Microsoft, i);

		calcPay(Microsoft, i);

		output(Microsoft, i, OT);

		i++;

	}

	return 0;
}