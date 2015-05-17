/*
                           cpp file for "employee.h"
						   Author:Haris Suhail

						   The following file contains definitions of the functions
						   stated below:
						   //             ALL GET FUNCTIONS
							string get_first_name();
							string get_last_name();
							string get_password();
							int get_id();
							float get_pay_rate();
							float get_hours_worked();
							float get_total_pay();


						//             ALL SET FUNCTIONS
							void set_first_name(string);
							void set_last_name(string);
							void set_password(string);
							void set_id(int);
							void set_pay_rate(float);
							void set_hours_worked(float);
							void set_total_pay(float);


	//           FILE IO

							void read_from_file(fstream);
							void write_to_file(fstream);


								//      GET AND DISPLAY ALL
	void set_all_values();
	void display_all();



*/

#include "employee.h"
#include "inputexception.h"
#include <iostream>
#include "errorcheck.h"
#include <string>
#include <windows.h>
#include <fstream>
#include "miscfunc.h"
using namespace std;


int Employee::counter = 1001;

Employee::Employee():first_name("\0"),  last_name("\0"), password("\0"), pay_rate(0), hours_worked(0), id(counter++),is_manager(0)
{}
Employee::Employee(int x):first_name("\0"),  last_name("\0"), password("\0"), pay_rate(0), hours_worked(0)
{}

//                    ~~~~~~~~~~~~~~~GET FUNCTIONS~~~~~~~~~~~~~~~
int Employee::get_counter()
{
	return counter;
}
string Employee::get_first_name()
{
	return this->first_name;
}

bool Employee::get_is_manager()
{return is_manager;}
string Employee::get_last_name()
{
	return this->last_name;
}
string Employee::get_password()
{
	return password;
}
int Employee::get_id()
{
	return this->id;
}
float Employee::get_pay_rate()
{
	return this->pay_rate;
}
float Employee::get_hours_worked()
{
	return this->hours_worked;
}
float Employee::get_total_pay()
{
	return this->total_pay;
	
}



//                  ~~~~~~~~~~~~~~SET FUNCTIONS~~~~~~~~~~~~~~~~
void Employee::set_is_manager(bool a)
{
	is_manager=a;
}
void Employee::set_counter(int x)
{
	counter = x;
}

void Employee::set_first_name(string first_name)
{
	this->first_name=first_name;
}
void Employee::set_last_name(string last_name)
{
	this->last_name = last_name;
}
void Employee::set_password(string password)
{this->password=password;}
void Employee::set_id(int id)
{
	this->id = id;
}
void Employee::set_pay_rate(float pay_rate)
{this->pay_rate = pay_rate;}
void Employee::set_hours_worked(float hours_worked)
{
	this->hours_worked = hours_worked;
}
void Employee::set_total_pay(float total_pay)
{
	this->total_pay = total_pay;
}


//                ~~~~~~~~~~~~~~~~~~     FILE IO    ~~~~~~~~~~~~~~~~~~~

void Employee::read_from_file(fstream &fin)
{
	 fin.read(reinterpret_cast<char*>(this), sizeof(*this));
	

}
void Employee::write_to_file(fstream &fout)
{
 fout.write(reinterpret_cast<char*>(this), sizeof(*this));
}


void Employee::read_from_file(fstream& fin, int seek)
{
	fin.seekg(sizeof(*this)*(seek-1),ios::beg);
	fin.read(reinterpret_cast<char*>(this), sizeof(*this));
}
void Employee::write_to_file(fstream& fout, int seek)
{
	fout.seekp(sizeof(*this)*(seek-1),ios::beg);
	fout.write(reinterpret_cast<char*>(this), sizeof(*this));
}
//             ~~~~~~~~~~~~~~~~~~~~~ GET AND DISPLAY ALL ~~~~~~~~~~~~~~~~~

	
void Employee::set_all_values()
	{
		int x_ = wherex(), y = wherey();
		string tempstring;
		gotoxy(x_,y++);
		

		//cout<<"\n=====================================================\n";
		cout<<"Updating data for Employee ID "<<this->id<<"."<<endl;
		gotoxy(x_,y++);
		cout<<"Enter First Name:";
		fflush(stdin);
		getline(cin, first_name);
	
		gotoxy(x_,y++);
		cout<<"Enter Last Name:";
		fflush(stdin);
		getline(cin, last_name);
		gotoxy(x_,y++);
		cout<<"Enter 1 if employee is manager:";
		int x;
		x = geti(0,1);
		if(x!=0)
		{
			is_manager = 1;
		}
		else is_manager = 0;

		gotoxy(x_,y++);
	
		cout<<"Enter payrate:";
		pay_rate = getf(0,  300000);
gotoxy(x_,y++);
		cout<<"Enter hours Worked:";
		hours_worked = getf(0, 300000);

		total_pay = hours_worked * pay_rate;
		do{
			gotoxy(x_,y++);
		cout<<"Enter Employee account password:";
		fflush(stdin);
		getline(cin,tempstring);
		gotoxy(x_,y++);
		cout<<"Reconfirm Password:";
		fflush(stdin);
		getline(cin,password);
		if(password==tempstring)break;
		else
		{
			gotoxy(x_,y++);
			cout<<"<<Password Mismatch, Please re-enter>>";
		}
		}while(1);
		//cout<<"\n=====================================================\n";

		gotoxy(x_,y++);
		cout<<"All data set\n";

		gotoxy(x_,y++);










	}
void Employee::display_all()
	{
		int x = wherex(), y = wherey();
		//cout<<"\n------------------------------------------------";
		gotoxy(x,y++);
		cout<<"Showing data for Employee ID "<<id<<".";
		gotoxy(x,y++);
		cout<<"First Name:"<<first_name;
		gotoxy(x,y++);
		cout<<"Last Name:"<<last_name;
		gotoxy(x,y++);
		cout<<"Pay Rate:"<<pay_rate;
		gotoxy(x,y++);
		cout<<"Total hours worked:"<<hours_worked;
		gotoxy(x,y++);
		cout<<"Total pay accumulated:"<<hours_worked*pay_rate;
		gotoxy(x,y++);
		//cout<<"\n------------------------------------------------\n";


	}
