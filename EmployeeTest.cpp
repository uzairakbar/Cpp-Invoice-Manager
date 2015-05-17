/*
#include "employee.h"
#include "manageemployees.h"
//#include "inputexception.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include "menu.h"
#define EMPDIR "employee.dat"
using namespace std;
int login_screen(fstream&, bool&);
void MainMenu(int);
void drawRectangle(int x, int y, int a, int b, int delay = 0, char c ='*')
{
     gotoxy(x,y);
     for(int i = x;i<=a;i++)
     { 
             Sleep(delay);
             cout<<c;
             gotoxy(i, y);
             
             
     }
      gotoxy(a, y);
      for(int i = y;i<=b+1;i++)
     { 
              Sleep(delay);
             cout<<c;
             gotoxy(a, i);
         }
         gotoxy(x, y);
           for(int i = y;i<=b;i++)
     { 
              Sleep(delay);
              
             cout<<c;
             gotoxy(x, i);
             
             
             
             }
     gotoxy(x, b);
      for(int i = x;i<=a;i++)
     { 
              Sleep(delay);
            cout<<c;
             
             gotoxy(i, b);
         }
             
    
             
     
     }
int main()
{

	
	bool is_manager;
	int employeeid;
	fstream datafile;
	
    employeeid= login_screen(datafile, is_manager);
	
	if(!employeeid)
	{
		return 0;
	}

	MainMenu(is_manager);



	 return 0;



	
}


int login_screen(fstream& myfile, bool & is_manager)
{
			string password="\0";
			int username;
	        system("color 79");
			system("mode 168");
	
	drawRectangle(30,10,140,45);
			gotoxy(85-(strlen("Store Mangement System")/2),12);
		string a = "Store Mangement System";
	int i = 0;
	while(a[i]!='\0')
	{
		cout<<a[i];
		Sleep(5);               ////////////////////////////
		i++;
	}

	
	gotoxy(85-strlen("Employee Id:"),16);
	cout<<"Employee Id:";
	//username = getint();
	cin>>username;

gotoxy(85-strlen("Employee Id:"),17);

	
	cout<<"Password   :";
	//fflush(stdin);
	//getline(cin, password);
	i=0;
	char c;
	do{
		c=_getch();
		if(c!='\r')
		{password=password+c;
		cout<<"*";
		i++;}
		else
		{
			password[i]='\0';
			break;
		}
	}
	while(1);
	myfile.open(EMPDIR, ios::binary | ios::in);
	if(!myfile)
	{
		gotoxy(85-strlen("Employee Id:"),44);
		cerr<<"\nFile cannot be found\n";
		_getch();
	}

	Employee tempemp(1);
	tempemp.read_from_file(myfile, username-1000);
	is_manager = tempemp.get_is_manager();


	myfile.close();
	//cout<<tempemp.get_password();

	if(tempemp.get_password() == password)

	{
	gotoxy(85-strlen("Employee Id:"),42);
	cout<<"Login Successful.";
	Sleep(1000);
	return username;
	
	}
	
	else 
	{
		gotoxy(85-strlen("Employee Id:"),42);
		cout<<"Id or password incorrect.";
		Sleep(1000);
		return false;}
}


void MainMenu(int is_manager)
{   int x;
	if(is_manager)
	{
		x=5;
	}
	else
	{
	 x= 4;
	}

	
	
	Menu MainMenu(x);
	MainMenu.changecolour(121,121);
	MainMenu.setRectangle(60,10,110,25);
	
	if(x==5)
	{
		MainMenu.setoptions(5, "Manage Employees");
	}
		
		MainMenu.setoptions(1, "Open Inventory");
		
		MainMenu.setoptions(2, "Update Inventory");
		
		MainMenu.setoptions(3, "Manage Sales");
		
		MainMenu.setoptions(4, "Exit");
	
	switch(MainMenu.displaymenu(75,15))
	{
	
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		 manageemployees();
		break;
	default:
		break;
	
	}
}


*/
