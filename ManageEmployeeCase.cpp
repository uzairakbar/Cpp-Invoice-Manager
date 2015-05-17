#include "ManageEmployeeCase.h"
#include "miscfunc.h"
#define EMPDIR "employee.dat"
#include <iostream>
#include <windows.h>
#include "menu.h"
#include "employee.h"
#include <iomanip>
#include "errorcheck.h"

int manageemployees(){
/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			//system("mode 167");
	Employee *s;
	Menu main(6);
	//Menu::setcolor("0C");
	main.setoptions(1,"Add Employee");
	main.setoptions(2,"Update Employee Data");
	main.setoptions(3,"Delete Employee Data");
	main.setoptions(4,"Show Employee Data");
	main.setoptions(5,"Show all Data");
	main.setoptions(6,"Back");

	main.changecolour(121,121);

	

	Employee tempEmployee(1), temp2(1);
	fstream file;
	file.open(EMPDIR,ios::app|ios::binary);
	file.seekp(0, ios::end);
	int a = file.tellp();
	a=a/(sizeof(Employee));
	Employee::set_counter((a+1)+1000);
	file.close();
	
	
	int num,count;
	string temp;
	float tempfloat;
	do
	{
	file.open(EMPDIR,ios::app);
	file.seekp(0, ios::end);
	int a = file.tellp();
	a=a/(sizeof(Employee));
	file.close();
	int yaxis;
	main.setRectangle(60,10,110,25);
		switch(main.displaymenu(74,15))
		{
			
		case 1:
			////SetConsoleTextAttribute(hConsole, 13);
			s=new Employee;
			gotoxy(61,32);
			s->set_all_values();
			file.open(EMPDIR,ios::app);
			
			if(!file)cerr<<"Error Opening File";
			s->write_to_file(file);
			gotoxy(wherex(),wherey());
			cout<<"Employee Added!\n";
			delete s;
			file.close();
			Sleep(500);
			////SetConsoleTextAttribute(hConsole, 12);
			break;
		case 2:
			//SetConsoleTextAttribute(hConsole, 13);
			yaxis=28;
			gotoxy(61,yaxis++);
			cout<<"Enter number of Employee:";
			
			num=geti(1001, a+1000);
			num-=1000;
			file.open(EMPDIR,ios::out|ios::binary|ios::in);
			file.seekg(sizeof(Employee)*(num-1));
			tempEmployee.read_from_file(file);
			gotoxy(61,yaxis++);
			cout<<"To be edited:";
			gotoxy(61,yaxis++);
			tempEmployee.display_all();
			file.seekp(sizeof(Employee)*(num-1),ios::beg);
			gotoxy(61,(yaxis+=7));
			cout<<"------------------";
			gotoxy(61,yaxis++);
			cout<<"Enter New data:";
			gotoxy(61,yaxis++);
			/////////////////////////////////////////
			cout<<"Enter New First Name:";
			
			
			fflush(stdin);
			getline(cin, temp);
			tempEmployee.set_first_name(temp);
			gotoxy(61,yaxis++);
			cout<<"Enter New Last Name:";
			
			
			fflush(stdin);
			getline(cin, temp);
			tempEmployee.set_last_name(temp);
			gotoxy(61,yaxis++);
			cout<<"Enter New Payrate:";
			
			tempfloat=getf(0, 300000);
			gotoxy(61,yaxis++);
			
			
			tempEmployee.set_pay_rate(tempfloat);
			/////////////////////////////////////////
			tempEmployee.write_to_file(file);
			gotoxy(61,yaxis++);
			cout<<"Data Updated";
			Sleep(500);
			file.close();

			//SetConsoleTextAttribute(hConsole, 12);

			break;
		case 3:
			yaxis=28;
			//SetConsoleTextAttribute(hConsole, 13);
			gotoxy(61,yaxis++);
			cout<<"Enter roll number of Employee:";
			
			num=geti(1001, 1001+a);
			num-=1000;
			gotoxy(61,yaxis++);
			if(num<0 || num>a){cerr<<"No such Employee"; _getch();
			//SetConsoleTextAttribute(hConsole, 12);
			break;
			//SetConsoleTextAttribute(hConsole, 12);
			}
			temp2.set_id(num);
			file.open(EMPDIR,ios::out|ios::binary|ios::in);
			file.seekp(sizeof(Employee)*(num-1),ios::beg);
			temp2.write_to_file(file);
			gotoxy(61,yaxis++);

			cout<<"Employee Deleted!";
			Sleep(500);
			file.close();
			//SetConsoleTextAttribute(hConsole, 12);
			break;
		case 4:
			yaxis=28;
			//SetConsoleTextAttribute(hConsole, 13);
			file.open(EMPDIR, ios::in|ios::binary);
			yaxis=28;
			gotoxy(61,yaxis++);

			cout<<"Enter Employee ID Number of Employee:";
			num=geti(1001, 1001+a);
			num-=1000;gotoxy(61,yaxis++);
			if(num<0 || num>a){cerr<<"No such Employee"; _getch();file.close();
			//SetConsoleTextAttribute(hConsole, 12);
			break;}
			file.seekg(sizeof(Employee)*(num-1), ios::beg);
			tempEmployee.read_from_file(file);
			gotoxy(61,yaxis++);
			if(tempEmployee.get_first_name()=="\0")
			{
				cout<<"No data";
				_getch();

				//SetConsoleTextAttribute(hConsole, 12);
				break;
			}
			tempEmployee.display_all();
			file.close();
			_getch();
			//SetConsoleTextAttribute(hConsole, 12);

			
			break; 

		case 5:
			

			//SetConsoleTextAttribute(hConsole, 13);
             

			yaxis=28;
			file.open(EMPDIR, ios::in | ios::binary|ios::out);
			gotoxy(61,yaxis++);
			if(!file){cerr<<"Error opening File case 5"; _getch(); return 0;}

			gotoxy(61,yaxis++);
			cout<<setw(5)<<"ID"<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(20)<<"Pay Rate";
			gotoxy(61,yaxis++);
			cout<<setw(5)<<"-----"<<setw(20)<<"----------"<<setw(20)<<"---------"<<setw(20)<<"--------";
			
		
			count = a;
			while(count -- )
			{
				tempEmployee.read_from_file(file);
				if(tempEmployee.get_first_name()!="\0")
				{//cout<<endl;
					gotoxy(61,yaxis++);
				cout<<setw(5)<<tempEmployee.get_id()<<setw(20)<<tempEmployee.get_first_name()<<setw(20)<<tempEmployee.get_last_name()<<setw(20)<<tempEmployee.get_pay_rate()<<endl;
				}
			};

			file.close();
			

			_getch();
			//SetConsoleTextAttribute(hConsole, 12);
			break;
		case 6:

			//close files and delete objects

			return 0;
			break;
		default:
      ;
		}
	}while(1);


}



int accountdetails(int id)
{
	int yaxis;
	string oldpass, newpass;
	Employee tempEmployee;
	int num;
    Menu accountdetails(3);
	accountdetails.changecolour(121,121);
    
	accountdetails.setRectangle(60,10,110,25);
	accountdetails.setoptions(1,"Show Data");
	accountdetails.setoptions(2,"Change Password");
	accountdetails.setoptions(3,"Back");

	fstream file;
	do{
	switch(accountdetails.displaymenu(74, 15))
	{
	case 1:
		yaxis=28;
			//SetConsoleTextAttribute(hConsole, 13);
			file.open(EMPDIR, ios::in|ios::binary);
			yaxis=28;
			gotoxy(61,yaxis++);

			num=id;
			num-=1000;gotoxy(61,yaxis++);
			file.seekg(sizeof(Employee)*(num-1), ios::beg);
			tempEmployee.read_from_file(file);
			gotoxy(61,yaxis++);
			if(tempEmployee.get_first_name()=="\0")
			{
				cout<<"No data";
				_getch();

				//SetConsoleTextAttribute(hConsole, 12);
				break;
			}
			tempEmployee.display_all();
			file.close();
			_getch();
			//SetConsoleTextAttribute(hConsole, 12);


		break;
	case 2:
		yaxis=28;

		file.open(EMPDIR, ios::in|ios::binary);
		if(!file.is_open())
		{
			cout<<"There was an Error in opening the file. Password not set. Please try again.";
			Sleep(1000);
			return 21;

		}
			
			

			num=id;
			num-=1000;
			file.seekg(sizeof(Employee)*(num-1), ios::beg);
			tempEmployee.read_from_file(file);
			file.close();
			file.clear();

			gotoxy(61,yaxis++);
		yaxis=28;
		gotoxy(61,yaxis++);
		cout<<"Enter old Password:";
		fflush(stdin);
		getline(cin, oldpass);

		if(oldpass==tempEmployee.get_password())
		{
			do
			{
				yaxis++;
				gotoxy(61,yaxis++);
				cout<<"Enter new password:";
				fflush(stdin);
		getline(cin, oldpass);
				gotoxy(61,yaxis++);
				cout<<"Re-renter password:";
				fflush(stdin);
		getline(cin, newpass);
				gotoxy(61,yaxis++);
				if(newpass==oldpass)
				{
					tempEmployee.set_password(newpass);
				file.open(EMPDIR, ios::out|ios::binary);
				file.seekg(sizeof(Employee)*(num-1), ios::beg);
				tempEmployee.write_to_file(file);
				cout<<"Password set.";
				Sleep(500);break;
				}
				else 
				{
					gotoxy(61,yaxis++);
					cout<<"Password mismatch, Try again.";
				}
				}while(1);

				}
		

		


		
		else
		{gotoxy(61, yaxis++);
		cout<<"Wrong Password.";
		Sleep(500);
		}
		return 0;
	case 3:
		return 2;
		break;
	default:
		return 0;

	}

	}while(1);

	return 1;
}

		