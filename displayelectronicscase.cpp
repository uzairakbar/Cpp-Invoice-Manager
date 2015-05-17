#include "employee.h"
#include "electronics.h"
#include "miscfunc.h"
#include <windows.h>
#include <iostream>
#include "errorcheck.h"
#include <conio.h>
#include <time.h>
#include <iomanip>
#include "menu.h"
#define ELECCSVDIR "electronics.csv"
#define EMPDIR "test.dat"
int elec_menu()
{
	fstream myfile,excel;
	int n;
		string a;
		int number;
		electronics temp;
		int posx, posy;
		Menu elec_Menu(6);

		myfile.open ("electronics.dat",ios::in|ios::binary|ios::app);
			//rewind(*myfile);
		   myfile.seekg(0,ios::end);
		number = myfile.tellg();
		number = number / (sizeof(electronics));
		myfile.close();




		elec_Menu.changecolour(121,121);
    
	elec_Menu.setRectangle(60,10,110,25);

		elec_Menu.setoptions(1, "Search by I.D.");
		elec_Menu.setoptions(2, "Search by Title");
		elec_Menu.setoptions(3, "Search by Barcode");	
		elec_Menu.setoptions(4, "Display All");
		elec_Menu.setoptions(5, "Display in SpreadSheet");
		elec_Menu.setoptions(6, "Back");
		do{

		switch(elec_Menu.displaymenu(74,15))
	{
		case 1:
			
			posx=wherex();
			posy=wherey()+6;
			gotoxy(posx-3, posy++);
			
			n = get_electronics_id();
			if(n==0)break;
			gotoxy(posx, posy++);
			myfile.open("electronics.dat",ios::in);
			myfile.seekg((n-1)*sizeof(electronics),ios::beg);
			myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));

			cout<<"Id:"<<temp.getID();
			gotoxy(posx, posy++);
			cout<<"BarCode:"<<temp.getBarcode();
			gotoxy(posx, posy++);
			cout<<"Title:"<<temp.getTitle();
			gotoxy(posx, posy++);
			cout<<"Rate:"<<temp.getRate();
			gotoxy(posx, posy++);
			cout<<"Quantity:"<<temp.getQuantity();
			gotoxy(posx, posy++);
			cout<<"Supplier:"<<temp.getManufacturer_Supplier();
			gotoxy(posx, posy++);
			cout<<"Details and Description:"<<temp.getDescrpition();







			myfile.close();
			fflush(stdin);
			_getch();
			//Change made here 10:29 p.m
		break;
		case 2:
			posx=wherex();
			posy=wherey()+6;
			n=0;
			gotoxy(posx, posy++);
			cout<<"Enter Title: ";
			fflush(stdin);
			getline(cin,a);
			gotoxy(posx, posy++);
			
			//Change made here 10:29 p.m
			//////////////////////
			
			myfile.seekp(0, ios::beg);
		for(int i = 0 ; i < number; i++)
		{
			myfile.open("electronics.dat",ios::in);
			myfile.seekg(i*sizeof(electronics),ios::beg);	
			myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			//cout<<"<T>"<<temp.getTitle();
			if((temp.getTitle())==a)
			{
				n=1;
				gotoxy(posx, posy++);
				cout<<"Id:"<<temp.getID();
				gotoxy(posx, posy++);
			cout<<"BarCode:"<<temp.getBarcode();
			gotoxy(posx, posy++);

			cout<<"Title:"<<temp.getTitle();
			gotoxy(posx, posy++);
			cout<<"Rate:"<<temp.getRate();
			gotoxy(posx, posy++);
			cout<<"Quantity:"<<temp.getQuantity();
			gotoxy(posx, posy++);
			cout<<"Supplier:"<<temp.getManufacturer_Supplier();
			gotoxy(posx, posy++);
			cout<<"Details and Description:"<<temp.getDescrpition();
				_getch();
				
				
				break;
			}
			
		}
		myfile.close();
		
		if(!n)
		cout<<"No Match Found.";
		_getch();
			/////////////////////
		break;
		case 3:
			posx=wherex();
			posy=wherey()+6;
			n = 0;
			gotoxy(posx, posy++);
			cout<<"Scan or Enter Barcode : ";
			fflush(stdin);getline(cin,a);
			
			myfile.seekp(0, ios::beg);
			for(int i = 0 ; i < number ; i++)
			{

			myfile.open("electronics.dat",ios::in);
			myfile.seekg(i*sizeof(electronics),ios::beg);	
			myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			//cout<<"<T>"<<temp.getBarcode();
			if(temp.getBarcode()==a)
				{
			gotoxy(posx, posy++);
			cout<<"Id:"<<temp.getID();
			gotoxy(posx, posy++);
			cout<<"BarCode:"<<temp.getBarcode();
			gotoxy(posx, posy++);
			cout<<"Title:"<<temp.getTitle();
			gotoxy(posx, posy++);
			cout<<"Rate:"<<temp.getRate();
			gotoxy(posx, posy++);
			cout<<"Quantity:"<<temp.getQuantity();
			gotoxy(posx, posy++);
			cout<<"Supplier:"<<temp.getManufacturer_Supplier();
			gotoxy(posx, posy++);
			cout<<"Details and Description:"<<temp.getDescrpition();
					n = 1;
					break;
				}
			}
			fflush(stdin);
			myfile.close();
			gotoxy(posx, posy++);
			if(!n)cout<<"No Match found.";
			_getch();//Change made here 10:29 p.m
		break;
		case 4:
			posx=wherex()-20;
			posy=wherey()+6;
			gotoxy(posx, posy++);
			myfile.open("electronics.dat",ios::in|ios::binary);
			if(!myfile.is_open())
			{
				cout<<"File Cannot Be Found.";
				Sleep(1000);
				break;
			}
			myfile.seekg(0,ios::end);
			if(number!=0)
			{
				gotoxy(posx, posy++);
				cout<<setw(10)<<"ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<setw(10)<<"--"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<number; i++)
			{
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<setw(10)<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}
			}
			else
			{
				cout<<"No Item Exists";
				Sleep(1000);
				break;
			}

			myfile.close();
			_getch();
			//temp.displayall();
		break;
		case 5://display in spread sheet
			posx=wherex()-20;
			posy=wherey()+6;
			gotoxy(posx, posy++);
			myfile.open("electronics.dat",ios::in|ios::binary);

			if(!myfile.is_open())
			{
				cout<<"File Cannot Be Found.";
				Sleep(1000);
				break;
			}
			
			//cout<<"Number"<<number;
			//_getch();
			excel.open(ELECCSVDIR, ios::out);
			if(number!=0)
			{excel<<"ID,Rate, Quantity, Bar Code , Manufacturer , Title,Description"<<endl;
		
				
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<number; i++)
			{
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				excel<<temp.getID()<<","<<temp.getRate()<<","<<temp.getQuantity()<<","<<temp.getBarcode()<<","<<temp.getManufacturer_Supplier()<<","<<temp.getTitle()<<","<<temp.getDescrpition()<<endl;
				
				
			
			}
			}
			else
			{
				cout<<"No Item Exists";
				Sleep(1000);
				break;
			}

			myfile.close();
			excel.close();
			 a = "start ";
			if(a=="start ")
			 a = a + ELECCSVDIR;
			 system(a.c_str());
			_getch();

		
			break;
		case 6:
			return 5;
		break;
		default:
			return 0;
		break;
	}
		}while(1);
		return 5;
}
