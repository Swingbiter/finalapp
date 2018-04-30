#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <time.h>
using namespace std;

void getTime(string &timeNow);

class taskObj
{
public:
	string date, info;

	// Grabs data from user.
	void getData(char autodate = 'y')
	{
		date = "";
		info = "";
		if (autodate == 'n' || autodate == 'N')
		{
		cout << "Enter date DD/MM/YYYY (Include slashes): ";
		cin.ignore();
		getline(cin, date);
		}
		else 
		{
			getTime(date);
			cin.ignore();
		}
		if (date != "q" || date != "Q")
		{
			cout << "Enter details: ";
			getline(cin, info);
		}
	}

	// This loops through the lines of text in the log file and display them to the user.
	void view_logs(ifstream &fileRead)
	{
		cout << "##########  B E G I N  T A S K S  ##########" << endl;
		string line;
		while (getline(fileRead, line))
		{
			cout << line << endl;
		}
		cout << "##########    E N D    T A S K S  ##########" << endl;

		fileRead.close();
	}
	// Allows user to add to the log file.
	void append_logs(ofstream &fileWrite, char autodate)
	{
		string writeline;
		getData(autodate);
		writeline = date + " " + info;
		fileWrite << writeline << endl;
	}
};

int main() {
	int choice;
	char autodate = 'y';
	string writeline;
	taskObj task;

	do {
		// Menu with beautiful ASCII art.
		cout << " ____  __   ____  __ _  ____  ____" << endl;
		cout << "(_  _)/ _\\ / ___)(  / )(  __)(  _ \\ " << endl;
		cout << "  )( /    \\\\___ \\ )  (  ) _)  )   /" << endl;
		cout << " (__)\\_/\\_/(____/(__\\_)(____)(__\\_)" << endl;
		cout << setw(20) << "MENU" << endl << endl;

		cout << "1. View tasks." << endl;
		cout << "2. Append task list." << endl;
		cout << "3. Settings" << endl;
		cout << "4. Quit" << endl;
		cout << setw(0) << "Please enter your choice: ";
		cin >> choice;

		// Decides what to do based on input.
		switch (choice)
		{
			case 1:
				{
				// The view case.
				ifstream fileRead("tasks.txt", std::ios_base::in);
				if (!fileRead) {
					cerr << "Error creating file..";
				}
				else {
					cout << "Tasks file loaded successfully.\n" << endl;
				}

				task.view_logs(fileRead);
				break;
				}
			case 2:
				{
				// The append case.
				ofstream fileWrite("tasks.txt", std::ios_base::app);
				if (!fileWrite) {
					cerr << "Error creating file..";
				}
				else {
					cout << "Tasks file loaded successfully.\n" << endl;
				}

				task.append_logs(fileWrite, autodate);

				fileWrite.close();
				break;
				
				}
			case 3:
				{
				// The settings case.
				cout << "##########  S E T T I N G S  ##########" << endl;
				cout << "Autodate? Y/N: ";
				cin >> autodate;
				cin.ignore();
				break;
				}
			case 4:
			{
				// The exit case.
				return 0;
				break;
			}
			default:
				cout << "Please enter a valid input";
				break;
		}

	} while (choice != 4);

	return 0;
}

// This gets the time and date automatically for the user.
void getTime(string &timeNow)
{
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeNow = asctime(timeinfo);
}
