// finalapp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void view_logs();
// void create_log();
void append_log();

class taskObj
{
public:
	string date, info;

	void getData()
	{
		date = "";
		info = "";
		cout << "Enter date DD/MM/YYYY (Include slashes): ";
		cin.ignore();
		getline(cin, date);
		if (date != "q" || date != "Q")
		{
			cout << "Enter details about your task. Press enter when done.\n";
			getline(cin, info);
		}
	}
	void view_logs(ifstream &fileRead)
	{

		string line;
		while (getline(fileRead, line))
		{
			cout << line << endl;
		}

		fileRead.close();
	}
	void append_logs(ofstream &fileWrite)
	{
		string writeline;
		getData();
		writeline = date + " " + info;
		fileWrite << writeline << endl;
	}
};

int main() {
	// cout << "\u25A0"; Just a reminder on how to print a block character.

	/*
	// Used for listing files in a directory, not currently working in repl
	// Or I can't figure it out. ¯\_(ツ)_/¯
	string path = "/logs/";
	for (auto & p : directory_iterator(path)){
	cout << p << endl;
	}
	*/


	int choice;
	string writeline;
	taskObj task;
	cout << " ____  __   ____  __ _  ____  ____"<<endl;
	cout << "(_  _)/ _\\ / ___)(  / )(  __)(  _ \\ " << endl;
	cout << "  )( /    \\\\___ \\ )  (  ) _)  )   /"<<endl;
	cout << " (__)\\_/\\_/(____/(__\\_)(____)(__\\_)" << endl;

	/*ofstream file("tasks.txt", std::ios_base::app);
	if(!file){
	cerr<<"Error creating file..";
	return 0;
	}else{
	cout<<"Tasks file loaded successfully.\n"<<endl;
	}
	*/

	do {
		cout << setw(20) << "MENU" << endl << endl;

		cout << "1. View tasks." << endl;
		cout << "2. Append task list." << endl;
		cout << "3. Quit" << endl;
		cout << setw(0) << "Please enter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				{
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
				ofstream fileWrite("tasks.txt", std::ios_base::app);

				task.append_logs(fileWrite);

				fileWrite.close();
				break;
				
				}
			case 3:
				{
				return 0;
				break;
				}
		}

	} while (choice != 3);

	return 0;
}
