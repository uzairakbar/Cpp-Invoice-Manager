#ifndef UpdateInventory_h
#define UpdateInventory_h

#include<iostream>
#include<fstream>
#include <stdio.h>
#include<string>
#include <string.h>
#include "errorcheck.h"
#include <sstream>
#include "windows.h"
#include "electronics.h"
#include "sports.h"
#include "stationery.h"
#include "menu.h"
/////////////////////////////////////////////////////////////////////////////////////////////

void Add_electronics_Item(fstream& file)
{
	gotoxy(wherex(), wherey()+6);
	electronics New(1);
	
	file.seekg(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	cin >> New;
	New.write(file);
}

//-------------------------------------------------------------------------------------------

void Edit_electronics_Item(fstream& file, electronics &E1)
{
	int x=100, y=30, z=20;

	
	int ID;
	gotoxy(x-25, y);
	ID = get_electronics_id(file);
	electronics E(1);
	gotoxy(x - z, y); cout << "              ID:"<<ID;
	gotoxy(x - z, y + 1); cout << "       Title:";
	gotoxy(x - z, y + 2); cout << "        Rate:";
	gotoxy(x - z, y + 3); cout << "    Quantity:";
	gotoxy(x - z, y + 4); cout << "     Barcode:";
	gotoxy(x - z, y + 5); cout << "Manufacturer:";
	gotoxy(x - z, y + 6); cout << " Description:";
	if(file.fail())
	{
		file.clear();
	}
	//file.open("electronics.dat", ios::in|ios::in|ios::binary);
	int  limit = 0 + E.getCount();
	gotoxy(x, y); 
	//file.open("electronics.dat", ios::binary|ios::end|ios::beg);
	file.seekg((ID-1)*sizeof(E), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;
	}
	E.read(file);
	E.setID(ID);
	file.seekg(0, ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}


	string Title = E.getTitle();
		
	float Rate = E.getRate();
	
	
	
	
	float Quantity = E.getQuantity();
	
	
	string Barcode = E.getBarcode();
	string Manufacturer = E.getManufacturer_Supplier();
	string Description = E.getDescrpition();
	string sQuantity, sRate;
	char Cquantity[30];
ostringstream ss, pp;
ss << (int)Rate;
pp << (int)Quantity;
string s1 = ss.str();
string s2 = pp.str();

	bool Done=false;
	Menu Edit_Electronics(7);
	Edit_Electronics.changecolour(121,121);
	while (!Done)
	{
		ss.str("");pp.str("");
		ss.clear();pp.clear();
		
		ss << (int)Rate;
pp << (int)Quantity;
string s1 = ss.str();
string s2 = pp.str();

			//sRate = sprintf(Cquantity, "%.4g", Rate);
	//sQuantity = sprintf(Cquantity, "%.4g", Quantity);
		
		
		

		Edit_Electronics.setoptions(1, Title.c_str());
		Edit_Electronics.setoptions(2, s1);
		Edit_Electronics.setoptions(3, s2);
		Edit_Electronics.setoptions(4, Barcode.c_str());
		Edit_Electronics.setoptions(5, Manufacturer.c_str());
		Edit_Electronics.setoptions(6, Description.c_str());
		Edit_Electronics.setoptions(7, "DONE");

		

		switch (Edit_Electronics.updatemenu(x, y+1))
		{
		case 1:
			gotoxy(x, y+1); cout << "               ";
			gotoxy(x, y+1); cin >> Title; break;
		case 2:
			gotoxy(x, y+2); cout << "               ";
			gotoxy(x, y+2); Rate=getf(0, 2147483640); break;
		case 3:
			gotoxy(x, y+3); cout << "               ";
			gotoxy(x, y+3); Quantity=geti(0, 300000); break;
		case 4:
			gotoxy(x, y+4); cout << "               ";
			gotoxy(x, y+4); cin >> Barcode; break;
		case 5:
			gotoxy(x, y+5); cout << "               ";
			gotoxy(x, y+5); cin >> Manufacturer; break;
		case 6:
			gotoxy(x, y+6); cout << "               ";
			gotoxy(x, y+6); cin >> Description; break;
		case 7:
			E.setTitle(Title);
			//E.setRate(Rate); E.setQuantity(Quantity);
			E.setBarcode(Barcode); E.setManufacturer_Supplier(Manufacturer);
			E.setDescription(Description);

			Done = true;
		}
		
	}
	E.setTitle(Title); E.setRate(Rate); E.setQuantity(Quantity);
			E.setBarcode(Barcode); E.setManufacturer_Supplier(Manufacturer);
			E.setDescription(Description);
	file.seekp((ID - 1)*sizeof(electronics), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
		E.write(file);
}

//-------------------------------------------------------------------------------------------

void Print_electronics_Item(fstream& file, electronics& E)
{
	int N, posx = wherex(), posy = wherey()+4;
	gotoxy(posx, posy++);
	cout << "Enter ID to Print Item\t: ";
	cin >> N;
	gotoxy(posx, posy++);
	file.seekg((N - 1)*sizeof(electronics), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.read(file);
	
	if (!strcmp((E.getTitle()).c_str(), "\0"))
	{
		gotoxy(posx, posy++);
		cout << "The Item Doesnot Exist.";
	}
	else
		cout << E;
}

//-------------------------------------------------------------------------------------------

void Delete_electronics_Item(fstream& file, electronics& E)
{
	int N, posx = wherex(), posy = wherey()+6;
	gotoxy(posx, posy++);
	N = get_sports_id(file);
	gotoxy(posx, posy++);
	E = electronics(N);
	file.seekg((N - 1)*sizeof(electronics), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.write(file);
}

//-------------------------------------------------------------------------------------------

bool update_electronics()
{
	//system("mode 168");
	electronics E(1);
	int posx = wherex(), posy = wherey()+4;

	gotoxy(posx, posy++);
	string s = "electronics.dat";


	fstream file(s.c_str(), ios::binary | ios::out | ios::app);

	if (!file)
	{
		gotoxy(posx, posy++);
		cerr << "\nError! File Not Opening. ";
		system("PAUSE");
		exit(1);
	}

	file.seekp(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return 0;}

	E.setCount((file.tellp() / sizeof(electronics)) + 1);

	file.close();
	file.open("electronics.dat", ios::binary | ios::out | ios::in);

	Menu Update_Electronics(4);
    Update_Electronics.changecolour(121,121);
	Update_Electronics.setRectangle(60,10,110,25);
	Update_Electronics.setoptions(1, "Add An Item");
	Update_Electronics.setoptions(2, "Update An Item");
	Update_Electronics.setoptions(3, "Delete An Item");
	Update_Electronics.setoptions(4, "Back");
	//Update_Electronics.setoptions(5, "Display An Item");				// !!! Temp !!!

	bool back=false;
	while (1)
	{
		switch (Update_Electronics.displaymenu(74, 15))
		{
		case 1:	Add_electronics_Item(file);		_getch(); break;
		case 2:	Edit_electronics_Item(file, E);	_getch(); break;
		case 3: Delete_electronics_Item(file, E);	_getch(); break;
		case 4: file.close(); return true;
		default: return false;
		}
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void Add_sports_Item(fstream& file)
{
	sports New(1000);
	
	file.seekg(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	cin >> New;
	New.write(file);
}

//-------------------------------------------------------------------------------------------

void Edit_sports_Item(fstream& file, sports& E)
{
	int N;
	int posx = wherex(), posy = wherey()+4;
	gotoxy(posx, posy++);
	N = get_sports_id(file);
	gotoxy(posx, posy++);
	E.setID(N);
	gotoxy(posx, posy++);
	E.setAll();														//!!! E.SetAll() over here !!!
	file.seekg((N - 1000)*sizeof(sports), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.write(file);
}

//-------------------------------------------------------------------------------------------

void Print_sports_Item(fstream& file, sports& E)
{
	int posx= wherex(), posy= wherey()+4;
	int N;
	gotoxy(posx, posy++);
	cout << "Enter ID to Print Item\t: ";
	cin >> N;
	gotoxy(posx, posy++);
	file.seekg((N - 1000)*sizeof(sports), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.read(file);

	if (!strcmp((E.getTitle()).c_str(), "\0"))
	{
		gotoxy(posx, posy++);
		cout << "The Item Doesnot Exist.";
	}
	else{
		gotoxy(posx, posy++);
		cout << E;
	}
}

//-------------------------------------------------------------------------------------------

void Delete_sports_Item(fstream& file, sports& E)
{
	int N;
	gotoxy(wherex(), wherey()+4);
	N = get_sports_id(file);
	file.seekg((N - 1000)*sizeof(sports), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.write(file);
}

//-------------------------------------------------------------------------------------------

bool update_sports()
{
	//system("mode 168");
	sports E(1000);

	gotoxy(wherex(), wherey()+5);
	string s = "sports.dat";


	fstream file(s.c_str(), ios::binary | ios::out | ios::app);

	if (!file)
	{
		gotoxy(wherex(), wherey()+5);
		cerr << "\nError! File Not Opening. ";
		system("PAUSE");
		exit(1);
	}

	file.seekp(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return 0;}

	E.setCount((file.tellp() / sizeof(sports)) + 1000);

	file.close();
	file.open("sports.dat", ios::binary | ios::out | ios::in);

	Menu Update_Sports(4);
	Update_Sports.changecolour(121,121);
	Update_Sports.setRectangle(60,10,110,25);


	Update_Sports.setoptions(1, "Add An Item");
	Update_Sports.setoptions(2, "Update An Item");
	Update_Sports.setoptions(3, "Delete An Item");
	Update_Sports.setoptions(4, "Back");
	//Update_Sports.setoptions(5, "Display An Item");				// !!! Temp !!!

	do
	{
		switch (Update_Sports.displaymenu(74, 15))
		{
		case 1:gotoxy(wherex(), wherey()+5);	Add_sports_Item(file);		_getch(); break;
		case 2:	gotoxy(wherex(), wherey()+5);Edit_sports_Item(file, E);	_getch(); break;
		case 3: gotoxy(wherex(), wherey()+5);Delete_sports_Item(file, E);	_getch(); break;
		case 4: gotoxy(wherex(), wherey()+5);file.close(); return true;
		default: return false;
		}
	} while (1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void Add_stationery_Item(fstream& file)
{
	int posx = wherex(), posy = wherey()+6;
	
	stationery New(2000);
	gotoxy(posx, posy++);
	
	file.seekg(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	cin >> New;
	New.write(file);
}

//-------------------------------------------------------------------------------------------

void Edit_stationery_Item(fstream& file, stationery& E)
{

	int N, posx = wherex(), posy = wherey()+6;
	gotoxy(posx, posy++);
	
	N = get_stationery_id(file);
	file.seekg((N - 2000)*sizeof(stationery), ios::beg);
	
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	gotoxy(posx, posy++);
	E.setID(N);
	gotoxy(posx, posy++);
	E.setAll();														//!!! E.SetAll() over here !!!
	int check = 0;
	
	E.write(file);
}

//-------------------------------------------------------------------------------------------

void Print_stationery_Item(fstream& file, stationery& E)
{
	int N, posx = wherex(), posy = wherey()+6;

	gotoxy(posx, posy++);
	cout << "Enter ID to Print Item:";
	cin >> N;
	file.seekg((N - 2000)*sizeof(stationery), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.read(file);

	if (!strcmp((E.getTitle()).c_str(), "\0"))
	{
		gotoxy(posx, posy++);
		cout << "The Item Doesnot Exist.";
	}
	else
	{
		gotoxy(posx, posy++);
		cout << E;
	}
}

//-------------------------------------------------------------------------------------------

void Delete_stationery_Item(fstream& file, stationery& E)
{
	int posx = wherex(), posy = wherey()+5;
	int N;
	gotoxy(posx, posy++);
	N=get_stationery_id(file);
	gotoxy(posx, posy++);
	
	E = stationery(N);
	file.seekg((N - 2000)*sizeof(stationery), ios::beg);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return ;}
	E.write(file);
	cout<<"Item Removed.";
	Sleep(1000);
}

//-------------------------------------------------------------------------------------------

bool update_stationery()
{
	int posx = wherex(), posy = wherey ()+5;
	stationery E(2000);

	
	string s = "stationery.dat";

	fstream file(s.c_str(), ios::binary | ios::out | ios::app);

	if (!file)
	{
		gotoxy(posx, posy++);
		cerr << "\nError! File Not Opening. ";
		system("PAUSE");
		exit(1);
	}

	file.seekp(0, ios::end);
	if(file.fail())
	{ cout<<"Could not find location";file.clear();return 0 ;}

	E.setCount((file.tellp() / sizeof(stationery)) + 2000);

	file.close();
	file.open("stationery.dat", ios::binary | ios::out | ios::in);

	Menu Update_Stationery(4);
	Update_Stationery.changecolour(121,121);
	Update_Stationery.setRectangle(60,10,110,25);

	Update_Stationery.setoptions(1, "Add An Item");
	Update_Stationery.setoptions(2, "Update An Item");
	Update_Stationery.setoptions(3, "Delete An Item");
	Update_Stationery.setoptions(4, "Back");
//	Update_Stationery.setoptions(5, "Display An Item");				// !!! Temp !!!

	do
	{
		switch (Update_Stationery.displaymenu(74, 15))
		{
		case 1:	Add_stationery_Item(file);		_getch(); break;
		case 2:	Edit_stationery_Item(file, E);	_getch(); break;
		//case 5: Print_stationery_Item(file, E);	_getch(); break;
		case 3: Delete_stationery_Item(file, E);	_getch(); break;
		case 4: file.close(); return true;
		default: return false;
		}
	} while (1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

bool update_food_items()
{
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////

bool update_inventory()
{
	//system("mode 168");
	Menu Update_Inventory(4);
    Update_Inventory.changecolour(121,121);
	Update_Inventory.setRectangle(60,10,110,25);
	
	Update_Inventory.setoptions(1, "Electronics");
	Update_Inventory.setoptions(2, "Sports Items");
	Update_Inventory.setoptions(3, "Stationery Items");
	Update_Inventory.setoptions(4, "Back");
	

	do
	{
		switch (Update_Inventory.displaymenu(74, 15))
		{
		case 1: gotoxy(wherex(), wherey()+5);update_electronics(); break;
		case 2: gotoxy(wherex(), wherey()+5);update_sports(); break;
		case 3: gotoxy(wherex(), wherey()+5);update_stationery(); break;
		case 4: gotoxy(wherex(), wherey()+5);return true; break;
		case 5: return true;
		default:return false;
		}
	} while (1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

#endif