#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;

int main() {
	ifstream fin;//read from file
	fin.open("temperature.txt");
	
	if (fin.fail())//if there is an error to open the file, then report the error and exit the program
	{
		cout << "Error in file opening!" << endl;
		exit(1);
	}

	ofstream fout;//write to file
	fout.open("average.txt",ios::app);//append the file
	if (fout.fail())
	{
		cout << "Error in file opening!" << endl;
		exit(1);
	}
	
	string line;
	while (getline(fin, line))
	{
		double sum = 0;
		int count = 0;

		istringstream line_in(line);
		string date;
		double number;

		line_in >> date;

		while (line_in >> number)
		{
			sum += number;
			count += 1;
		}
		double average = sum / count;
		fout << date << " " << fixed << setprecision(1) << average << endl;
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
