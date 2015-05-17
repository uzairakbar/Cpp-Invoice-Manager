/*
stationery Source File
End Semester Project File
Author: Smaqn
*/

# include <iostream>
# include <fstream>
# include <string>
# include <conio.h>
#include "errorcheck.h"
# include "stationery.h"
# include "menu.h"
# include "miscfunc.h"
# define   ELECCSVDIR "stationery.csv"
using namespace std;

istream& operator>> (istream& in, stationery& a)	//Change made at 10:35 p.m
{
	int posx = wherex(), posy = wherey();
	gotoxy(posx, posy++);
	a.ID = a.inv_count++; float b; string c;
	cout << "Item ID : " << a.ID << endl;
	gotoxy(posx, posy++);
	cout << "Enter Title of Product : "; fflush(stdin); getline(cin, c);
	a.Title = c;
	gotoxy(posx, posy++);
	cout << "Enter Rate of Product : "; b=getf(0, 300000);
	a.Rate = b;
	gotoxy(posx, posy++);
	cout << "Enter Quantity of Product : "; b=geti(0, 300000);
	a.Quantity = b;
	gotoxy(posx, posy++);
	cout << "Enter Barcode of Product : "; fflush(stdin); cin >> c;
	a.Barcode = c;
	gotoxy(posx, posy++);
	cout << "Enter Manufacturer of Product : "; fflush(stdin); getline(cin, c);
	a.Manufacturer_Supplier = c;
	gotoxy(posx, posy++);
	cout << "Enter Description of Product : "; fflush(stdin); getline(cin, c);
	a.Description = c;
	gotoxy(posx, posy++);
	return in;

}

ostream& operator<<(ostream& out, const stationery& a)		//Change made at 10:35 p.m
{

	int posx = wherex(), posy = wherey();
	gotoxy(posx, posy++);
	out << "Product's Information" << endl;
	gotoxy(posx, posy++);
	out	<< "Type : stationery" << endl;
	gotoxy(posx, posy++);
	out	<< "Title : " << a.Title << endl;
	gotoxy(posx, posy++);
	out	<< "ID : " << a.ID << endl;
	gotoxy(posx, posy++);
	out	<< "Price : " << a.Rate << endl;
	gotoxy(posx, posy++);
	out	<< "Quantity : " << a.Quantity << endl;
	gotoxy(posx, posy++);
	out	<< "Barcode : " << a.Barcode << endl;
	gotoxy(posx, posy++);
	out	<< "Manufacturer : " << a.Manufacturer_Supplier << endl;
	gotoxy(posx, posy++);
	out	<< "Description : " << a.Description << endl;
	gotoxy(posx, posy++);
	return out;
}

// Constructors

stationery::stationery() : inventory() {}
stationery::stationery(unsigned int N) : inventory(N)
{}

stationery::stationery(float rate, float quantity, string barcode, string manu_supp, string title, string description)
{
	ID = inv_count++;
	Rate = rate;
	Quantity = quantity;
	Barcode = barcode;
	Manufacturer_Supplier = manu_supp;
	Title = title;
	Description = description;
}

// Copy Constructor

stationery::stationery(const stationery& elec)
{
	ID = inv_count;
	Rate = elec.Rate;
	Quantity = elec.Quantity;
	Barcode = elec.Barcode;
	Manufacturer_Supplier = elec.Manufacturer_Supplier;
	Title = elec.Title;
	Description = elec.Description;
}

// Set Functions

void stationery::setCount(unsigned int a)
{
	inv_count = a;
}

void stationery::setID(unsigned int a)
{
	ID = a;
}

void stationery::setRate(float a)
{
	Rate = a;
}

void stationery::setQuantity(float a)
{
	Quantity = a;
}

void stationery::setBarcode(string a)
{
	Barcode = a;
}

void stationery::setManufacturer_Supplier(string a)
{
	Manufacturer_Supplier = a;
}

void stationery::setTitle(string a)
{
	Title = a;
}

void stationery::setDescription(string a)
{
	Description = a;
}

void stationery::setAll()
{
	int posx = wherex () , posy = wherey ();
	float b; string c;
	gotoxy(posx, posy++);
	cout << "Item ID : " << ID << endl;
	gotoxy(posx, posy++);
	cout << "Enter Title of Product : "; fflush(stdin); getline(cin, c);
	Title = c;
	gotoxy(posx, posy++);
	cout << "Enter Rate of Product : "; b=getf(0, 300000);
	Rate = b;
	gotoxy(posx, posy++);
	cout << "Enter Quantity of Product : "; b=geti(0, 300000);
	Quantity = b;
	gotoxy(posx, posy++);
	cout << "Enter Barcode of Product : "; fflush(stdin); cin >> c;
	Barcode = c;
	gotoxy(posx, posy++);
	cout << "Enter Manufacturer of Product : "; fflush(stdin); getline(cin, c);
	Manufacturer_Supplier = c;
	gotoxy(posx, posy++);
	cout << "Enter Description of Product : "; fflush(stdin); getline(cin, c);
	Description = c;
	gotoxy(posx, posy++);
}

// Get Functions
unsigned int stationery::getCount()
{
	return inv_count;
}
unsigned int stationery::getID()
{
	return ID;
}

float stationery::getRate()
{
	return Rate;
}

float stationery::getQuantity()
{
	return Quantity;
}

string stationery::getBarcode()
{
	return  Barcode;
}

string stationery::getManufacturer_Supplier()
{
	return Manufacturer_Supplier;
}

string stationery::getTitle()
{
	return Title;
}

string stationery::getDescrpition()
{
	return Description;
}

//File-Handling Functions
void stationery::seek_object(fstream& file, int a)
{
	file.seekp(sizeof(stationery)*(a - 1), ios::beg);
}

void stationery::read(fstream& file)
{
	file.read(reinterpret_cast<char*>(this), sizeof(stationery));
}

void stationery::write(fstream& file)
{
	file.write(reinterpret_cast<char*>(this), sizeof(stationery));
}

bool stationery::read_from_file(int a) //also have to enter csv/excel file read-write modes ("Change made at 10:45 p.m")
{
	int temp;
	fstream file("stationery.dat", ios::in | ios::binary | ios::app);
	temp = this->countcheck(file);
	if (a>temp) { cout << "Maximum ID exceeded " << endl; return false; }
	this->seek_object(file, a);
	this->read(file);
	if (file.eof())
	{
		return false;
	}

	return true;
}

void stationery::write_in_file(int a) //also have to enter csv/excel file read-write modes
{
	fstream file("stationery.dat", ios::out | ios::app | ios::binary);
	this->seek_object(file, a);
	this->write(file);
}

//Specialised Functions
void stationery::display()
{
	int posx = wherex(), posy = wherey();
	gotoxy(posx, posy);
	cout << "Product's Information" << endl;
	gotoxy(posx, posy);
		cout<< "Type : stationery" << endl;
		gotoxy(posx, posy);
		cout<< "Title : " << Title << endl;
		gotoxy(posx, posy);
		cout<< "ID : " << ID << endl;
		gotoxy(posx, posy);
		cout<< "Price : " << Rate << endl;
		gotoxy(posx, posy);
		cout<< "Quantity : " << Quantity << endl;
		gotoxy(posx, posy);
		cout<< "Barcode : " << Barcode << endl;
		gotoxy(posx, posy);
		cout<< "Manufacturer : " << Manufacturer_Supplier << endl;
		gotoxy(posx, posy);
		cout<< "Description : "<< Description << endl;
		gotoxy(posx, posy);
}

float stationery::calculate_price()
{
	return Rate;
}


int stationery::displayall()
{
	stationery tempelec;
	int i = 1;
	fstream myfile;

	int num = 2;
	string dir = "start ";
	//dir = dir + ELECCSVDIR;
	Menu DisplayAll(3);

	DisplayAll.setoptions(1, "Display Spreadsheet");
	DisplayAll.setoptions(2, "Display in console window");
	DisplayAll.setoptions(3, "Back");


	switch (DisplayAll.displaymenu(74, 15))
	{
	case 1:
		myfile.open(ELECCSVDIR, ios::out);
		myfile << "ID,Rate, Quantity, Bar Code , Manufacturer , TItle,Discription" << endl;
		/*E(0,0)="ID";
		E(0,1)="Rate";
		E(0,2)="Quantity";
		E(0,3)="Bar Code";
		E(0,4)="Manufacturer";
		E(0,5)="Title";
		E(0,6)="Description";*/

		tempelec.read_from_file(i++);

		myfile << tempelec.getID() << "," << tempelec.getRate() << "," << tempelec.getQuantity() << "," << tempelec.getBarcode() << "," << tempelec.getManufacturer_Supplier() << "," << tempelec.getTitle() << "," << tempelec.getDescrpition() << endl;

		while (1)
		{
			if (!tempelec.read_from_file(i++))
			{
				break;
			}
			else
			{
				myfile << tempelec.getID() << "," << tempelec.getRate() << "," << tempelec.getQuantity() << "," << tempelec.getBarcode() << "," << tempelec.getManufacturer_Supplier() << "," << tempelec.getTitle() << "," << tempelec.getDescrpition() << endl;
			}



		}
		dir = dir + ELECCSVDIR;
		cout << dir;
		myfile.close();
		system(dir.c_str());
		_getch();


		break;
	case 2:this->read_from_file(i); while (1){ this->display(); if (this->read_from_file(++i))break; }_getch();
		break;
	case 3:return 3;
		break;
	default:return 0;
		break;
	}
	return 3;
}
int stationery::countcheck(fstream& file)				//Change made at 10:45 p.m
{
	int temp;
	file.seekg(0, ios::end);
	temp = file.tellp() / sizeof(stationery);
	file.seekg(0, ios::beg);
	return temp;
}

//Search Functions
void stationery::search_by_id(int n)		//Changes made at 10:50 p.m
{
	int x, y;
	x = wherex() + 15;
	y = wherey();
	gotoxy(x, y);
	x = this->read_from_file(n);
	if (x)this->display();
}

void stationery::search_by_title(string n)		//Changes made at 10:54 p.m
{
	int x, y; fstream file("stationery.dat", ios::in | ios::binary | ios::app);
	x = wherex() + 16;
	y = wherey();
	gotoxy(x, y);
	while (1)
	{
		int i = 1;
		if (i>countcheck(file)){ cout << "No such Title exists." << endl; break; }
		this->read_from_file(i++);
		if (n == this->getTitle()){ this->display(); break; }
	}
}

void stationery::search_by_barcode(string n)
{
	int x, y;
	x = wherex() + 18;
	y = wherey();
	gotoxy(x, y);
	getline(cin, n);
	while (1)
	{
		int i = 1;
		this->read_from_file(i++);
		if (n == this->getBarcode()){ this->display(); break; }
	}
}

//Destructor 
//stationery :: ~stationery()
//{
//	clog << "stationery destructor is called " << endl;
//}
