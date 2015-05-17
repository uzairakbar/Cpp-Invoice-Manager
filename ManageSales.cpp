/*#include <iostream>
#include <fstream>
#include "managesales.h"
#include "errorcheck.h"
#include <windows.h>
#include "menu.h"
#include <iomanip>
#define MAX 20
//#include "miscfunc.h"
using namespace std;

///////////////////////

void caseE(electronics ,int&, int&, fstream&,int, float&);
void caseP(sports ,int&, int&, fstream&,int,float&);
void caseT(stationery ,int&, int&, fstream&,int, float&);
void drawRectangle(int x, int y, int a, int b, int delay = 0, char c ='*');
void clean();
int search(string);
int barsearch(string);
//////////////////////
void Edit_electronics(fstream& file, electronics& E, int N)
{
	

	E.setID(N);												//!!! E.SetAll() over here !!!
	file.seekg((N - 1)*sizeof(electronics), ios::beg);
	E.write(file);
}







///////////////////////
int othermenu();
int managesalecase ()
{
		managesales sale('c');
		//managesales receipt[MAX];
		//electronics *earray;
		//sports *parray;


		//int quantity;
		//int num;
		electronics tempelec;
		sports tempsports;
		stationery tempstat;
		string filename;
		float total=0;
		int index = 0;
		fstream myfile;
		int listx=20, listy=25;
		int paid;
		//myfile.open(sale.get_filename().c_str(), ios::in|ios::binary);
		//myfile.seekg(0, ios::end);
		//num = myfile.tellg();
		//num = num / sizeof(sale);
		//int location;
		//myfile.seekg(0, ios::beg);
		//myfile.close();

		int out = 0;

	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			
			
			SetConsoleTextAttribute(hConsole, 121);
			system("cls");
			
	int id;
	string title, barcode;
	do{
	switch(othermenu())
	{
	case 0:

		out= 1;
		gotoxy(20,8);id=geti(1, 2999);
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
		break;
	case 1: gotoxy(60,8);cin>>title; 
			id=search(title);
			out= 1;
		if(id==0)break;
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
	
		break;
	case 2: gotoxy(100,8);cin>>barcode;

		id = barsearch(barcode);
		out= 1;
		if(id==0)break;
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
	
		break;







	case 3: 
		do{
		gotoxy(118, 49);
		cout<<" PAID  :";
		SetConsoleTextAttribute(hConsole, 124);
		paid=getf(0, 2147483640);
		SetConsoleTextAttribute(hConsole, 121);
		if(paid<total)
		{
			gotoxy(118, 49);
		cout<<" PAID  :         ";
		}

		}while(paid<total);
		SetConsoleTextAttribute(hConsole, 121);
		gotoxy(119, 50 );
		cout<<"-----------";
		gotoxy(119, 51);
		cout<<"CHANGE:";
		SetConsoleTextAttribute(hConsole, 124);
		cout<<paid -total;
		SetConsoleTextAttribute(hConsole, 121);
		gotoxy(119, 52 );
		cout<<"-----------";
		_getch();




		return 1;
			
	}
	}while(1);
	_getch();
}
int othermenu ()
{
	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	

			drawRectangle(10,5,150,20);
			drawRectangle(10,23,150,60);
			gotoxy(20, 24);
			SetConsoleTextAttribute(hConsole, 121);
				cout<<setw(10)<<"ID"
					<<setw(20)<<"Title"
					<<setw(20)<<"BarCode"
					<<setw(20)<<"Quantity"
					<<setw(20)<<"Rate per item"
					<<setw(20)<<"Price";
				SetConsoleTextAttribute(hConsole, 121);

			             
			gotoxy(20,7);
			SetConsoleTextAttribute(hConsole, 124);
			cout<<"ID";
			SetConsoleTextAttribute(hConsole, 121);
			gotoxy(60, 7);
			cout<<"Title";
			gotoxy(100,7);
			cout<<"Barcode";
			gotoxy(140,17);
			cout<<"END";
			_getch();
			int choice = 0, prevchoice = 0;
			int temp;
			while(1)
			{

				temp = getch();
				if(temp == 77 || temp == 75)goto cn;
				if(temp == 13) return choice;
				temp = getch();
cn:
				if(temp == 13) return choice;
				
				if(temp==77)
				{   
					prevchoice = choice;
					choice++;
				if(choice > 3) choice = 0;
				}
				if(temp==75)
				{    prevchoice = choice;
					choice --;
				if(choice < 0 ) choice = 3;
				}
			

			switch(prevchoice)
			{
			case 0:
				gotoxy(20,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"ID";
				break;
				

			case 1:
				gotoxy(60,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"Title";
				break;
				


			case 2:
				gotoxy(100,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"Barcode";
				break;
			

			case 3:
				gotoxy(140,17);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"END";
				break;
				


			}

			switch(choice)
			{
			case 0:
				gotoxy(20,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"ID";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			case 1:
				gotoxy(60,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"Title";
				SetConsoleTextAttribute(hConsole, 121);
				break;


			case 2:
				gotoxy(100,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"Barcode";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			case 3:
				gotoxy(140,17);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"END";
				SetConsoleTextAttribute(hConsole, 121);
				break;


			}
			}


}


void caseE(electronics tempelec,int& listx,int& listy,fstream& myfile, int id, float& total)
{
	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	


	string filename;
int num, out=0;
float quantity;
	
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempelec.getID();
				gotoxy(60, 8);
				cout<<tempelec.getTitle();
				gotoxy(100, 8);
				cout<<tempelec.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempelec.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
				clean();
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				tempelec.setQuantity((tempelec.getQuantity()-quantity));
				tempelec.setID(id);												//!!! E.SetAll() over here !!!
	myfile.seekg((id- 1)*sizeof(electronics), ios::beg);
	tempelec.write(myfile);
				//myfile.seekg(id-1,ios::beg);
				//myfile.write(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
				myfile.close();
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempelec.getID()
					<<setw(20)<<tempelec.getTitle()
					<<setw(20)<<tempelec.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempelec.getRate()
					<<setw(20)<<quantity * tempelec.getRate();
				total += quantity * tempelec.getRate();
				clean();
				out = 1;
				break;

			}
		}

		if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
					if(myfile.is_open())
						myfile.close();
					
			}

			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<" ";
		}
			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
}
void caseP(sports tempsports,int& listx,int& listy,fstream& myfile, int id, float&total)
{/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	string filename;
int  num, out=0;
float quantity;
			filename = "sports.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempsports.getID();
				gotoxy(60, 8);
				cout<<tempsports.getTitle();
				gotoxy(100, 8);
				cout<<tempsports.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempsports.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
					gotoxy(20, 8);
				clean();
				out = 1;
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				tempsports.setQuantity((tempsports.getQuantity()-quantity));
				tempsports.setID(id);												//!!! E.SetAll() over here !!!
	myfile.seekg((id- 1)*sizeof(sports), ios::beg);
	tempsports.write(myfile);
				//myfile.seekg(id-1,ios::beg);
				//myfile.write(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
				myfile.close();
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempsports.getID()
					<<setw(20)<<tempsports.getTitle()
					<<setw(20)<<tempsports.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempsports.getRate()
					<<setw(20)<<quantity * tempsports.getRate();
				total += quantity * tempsports.getRate();
				clean();
				out = 1;
				break;

			}
			
			



		}
		if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
						if(myfile.is_open())
						myfile.close();
					
					
			}

			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<"      ";
		}
			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
}
void caseT(stationery tempstat, int &listx, int &listy,fstream& myfile, int id , float&total)
{/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	string filename;
int  num, out=0;
float quantity;
	
	filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
			///
			//cout<<"-"<<tempstat.getID();
			///
			if(tempstat.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempstat.getID();
				gotoxy(60, 8);
				cout<<tempstat.getTitle();
				gotoxy(100, 8);
				cout<<tempstat.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempstat.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
					gotoxy(20, 8);
				clean();
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				tempstat.setQuantity((tempstat.getQuantity()-quantity));
				tempstat.setID(id);												//!!! E.SetAll() over here !!!
	myfile.seekg((id- 1)*sizeof(stationery), ios::beg);
	tempstat.write(myfile);
				//myfile.seekg(id-1,ios::beg);
				//myfile.write(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
				myfile.close();
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempstat.getID()
					<<setw(20)<<tempstat.getTitle()
					<<setw(20)<<tempstat.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempstat.getRate()
					<<setw(20)<<quantity * tempstat.getRate();
				total += quantity * tempstat.getRate();
				clean();
				out = 1;
				break;

			}
			
			



		}
		
			if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					if(!myfile.is_open())
					{myfile.close();}
					clean();
						if(myfile.is_open())
						myfile.close();
					
					
			}


			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<"      ";
		}

			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
		
		
}



void clean()
{               gotoxy(20, 8);
				cout<<"                              ";
				gotoxy(60, 8);
				cout<<"                              ";
				gotoxy(100, 8);
				cout<<"                     ";
				gotoxy(20, 15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";}



//////////////////////////
int search(string a)
{

	string filename;
	sports tempsports;
	electronics tempelec;
	stationery tempstat;
	fstream myfile;
int  num, out=0;


///////////////////////////////////////////////////////////////////
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getTitle() == a)
			{
				return tempelec.getID();
			}
		}
			
		
	//////////////////////////////////////////////////////////////////////////
				myfile.close();
				filename = "sports.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getTitle() == a)
			{
				return tempsports.getID();
			}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
			///
			//cout<<"-"<<tempstat.getID();
			///
			if(tempstat.getTitle() == a)
			{return tempstat.getID();}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
		
	return 0;
}

//////////////////////////







int barsearch(string a)
{
	string filename;
	sports tempsports;
	electronics tempelec;
	stationery tempstat;
	fstream myfile;
int  num, out=0;


///////////////////////////////////////////////////////////////////
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getBarcode() == a)
			{
				return tempelec.getID();
			}
		}
			
		
	//////////////////////////////////////////////////////////////////////////
				myfile.close();
				filename = "sports.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getBarcode() == a)
			{
				return tempsports.getID();
			}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
			///
			//cout<<"-"<<tempstat.getID();
			///
			if(tempstat.getBarcode() == a)
			{return tempstat.getID();}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
		
	return 0;

}


*/






#include <iostream>
#include <fstream>
#include "managesales.h"
#include "errorcheck.h"
#include <windows.h>
#include "menu.h"
#include <iomanip>
#define MAX 20
//#include "miscfunc.h"
using namespace std;

///////////////////////

void caseE(electronics ,int&, int&, fstream&,int, float&);
void caseP(sports ,int&, int&, fstream&,int,float&);
void caseT(stationery ,int&, int&, fstream&,int, float&);
void drawRectangle(int x, int y, int a, int b, int delay = 0, char c ='*');
void clean();
int search(string);
int barsearch(string);
//////////////////////
void Edit_electronics(fstream& file, electronics& E, int N)
{
	

	E.setID(N);												//!!! E.SetAll() over here !!!
	file.seekg((N - 1)*sizeof(electronics), ios::beg);
	E.write(file);
}







///////////////////////
int othermenu();
void cleanlowerbox();
int managesalecase ()
{
		managesales sale('c');
		//managesales receipt[MAX];
		//electronics *earray;
		//sports *parray;


		//int quantity;
		//int num;
		electronics tempelec;
		sports tempsports;
		stationery tempstat;
		string filename;
		float total=0;
		int index = 0;
		fstream myfile;
		int listx=20, listy=25;
		int paid;
		//myfile.open(sale.get_filename().c_str(), ios::in|ios::binary);
		//myfile.seekg(0, ios::end);
		//num = myfile.tellg();
		//num = num / sizeof(sale);
		//int location;
		//myfile.seekg(0, ios::beg);
		//myfile.close();

		int out = 0;

	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			
			
			SetConsoleTextAttribute(hConsole, 121);
			system("cls");
			
	int id;
	string title, barcode;
	do{
	switch(othermenu())
	{
	case 0:

		out= 1;
		gotoxy(20,8);id=geti(1, 2999);
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
		break;
	case 1: gotoxy(60,8);cin>>title; 
			id=search(title);
			out= 1;
		if(id==0)break;
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
	
		break;
	case 2: gotoxy(100,8);cin>>barcode;

		id = barsearch(barcode);
		out= 1;
		if(id==0)break;
	
		sale.set_id(id);
		sale.set_type();
		gotoxy(30, 40);
		
		////
		//cout<<sale.get_type();
		//_getch();
		////
		switch(sale.get_type())
		{

		case 'E':
			caseE(tempelec, listx, listy, myfile,id, total);
			
		break;
		
	case 'P':
		caseP(tempsports, listx, listy, myfile,id, total);
		break;
		
	case 'T':
		caseT(tempstat, listx, listy, myfile,id, total);
		break;
		}
	
		break;







	case 3: 
		do{
		gotoxy(118, 49);
		cout<<" PAID  :";
		SetConsoleTextAttribute(hConsole, 124);
		paid=getf(0, 2147483640);
		SetConsoleTextAttribute(hConsole, 121);
		if(paid<total)
		{
			gotoxy(118, 49);
		cout<<" PAID  :         ";
		}

		}while(paid<total);
		SetConsoleTextAttribute(hConsole, 121);
		gotoxy(119, 50 );
		cout<<"-----------";
		gotoxy(119, 51);
		cout<<"CHANGE:";
		SetConsoleTextAttribute(hConsole, 124);
		cout<<paid -total;
		SetConsoleTextAttribute(hConsole, 121);
		gotoxy(119, 52 );
		cout<<"-----------";
		total=0;
		
		_getch();
		listy=25;

	
		cleanlowerbox();
		break;



	case 4:return 1;
				
		break;
	}
	}while(1);
	_getch();
}
int othermenu ()
{
	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	

			drawRectangle(10,5,150,20);
			drawRectangle(10,23,150,60);
			gotoxy(20, 24);
			SetConsoleTextAttribute(hConsole, 121);
				cout<<setw(10)<<"ID"
					<<setw(20)<<"Title"
					<<setw(20)<<"BarCode"
					<<setw(20)<<"Quantity"
					<<setw(20)<<"Rate per item"
					<<setw(20)<<"Price";
				SetConsoleTextAttribute(hConsole, 121);

			             
			gotoxy(20,7);
			SetConsoleTextAttribute(hConsole, 124);
			cout<<"ID";
			SetConsoleTextAttribute(hConsole, 121);
			gotoxy(60, 7);
			cout<<"Title";
			gotoxy(100,7);
			cout<<"Barcode";
			gotoxy(140,17);
			cout<<"END";
			gotoxy(140,18);
			cout<<"EXIT";
			_getch();
			int choice = 0, prevchoice = 0;
			int temp;
			while(1)
			{

				temp = getch();
				if(temp == 77 || temp == 75)goto cn;
				if(temp == 13) return choice;
				temp = getch();
cn:
				if(temp == 13) return choice;
				
				if(temp==77)
				{   
					prevchoice = choice;
					choice++;
				if(choice > 4) choice = 0;
				}
				if(temp==75)
				{    prevchoice = choice;
					choice --;
				if(choice < 0 ) choice = 4;
				}
			

			switch(prevchoice)
			{
			case 0:
				gotoxy(20,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"ID";
				break;
				

			case 1:
				gotoxy(60,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"Title";
				break;
				


			case 2:
				gotoxy(100,7);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"Barcode";
				break;
			

			case 3:
				gotoxy(140,17);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"END";
				break;
			

			case 4:
				gotoxy(140,18);
				SetConsoleTextAttribute(hConsole, 121);
				cout<<"EXIT";
				break;

			}

			switch(choice)
			{
			case 0:
				gotoxy(20,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"ID";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			case 1:
				gotoxy(60,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"Title";
				SetConsoleTextAttribute(hConsole, 121);
				break;


			case 2:
				gotoxy(100,7);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"Barcode";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			case 3:
				gotoxy(140,17);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"END";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			case 4:
				gotoxy(140,18);
				SetConsoleTextAttribute(hConsole, 124);
				cout<<"EXIT";
				SetConsoleTextAttribute(hConsole, 121);
				break;

			}
			}


}


void caseE(electronics tempelec,int& listx,int& listy,fstream& myfile, int id, float& total)
{
	/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	


	string filename;
int num, out=0;
float quantity;
	
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempelec.getID();
				gotoxy(60, 8);
				cout<<tempelec.getTitle();
				gotoxy(100, 8);
				cout<<tempelec.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempelec.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
				clean();
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				tempelec.setQuantity((tempelec.getQuantity()-quantity));
				tempelec.setID(id);												//!!! E.SetAll() over here !!!
	
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempelec.getID()
					<<setw(20)<<tempelec.getTitle()
					<<setw(20)<<tempelec.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempelec.getRate()
					<<setw(20)<<quantity * tempelec.getRate();
				total += quantity * tempelec.getRate();
				clean();
				out = 1;
				break;

			}
		}
		myfile.clear();
			
		
			myfile.seekg((id- 1)*sizeof(stationery), ios::beg);
	if(myfile.fail())
	{cout<<".";
	myfile.clear();
	fstream check("electronics.dat", ios::binary|ios::in|ios::out);
	tempelec.write(check);
	check.close();
	}
	else
	{
	if(out!=0)
		tempelec.write(myfile);
	if(myfile.fail())
	{cout<<".";}
	}
		

		if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
					if(myfile.is_open())
						myfile.close();
					
			}

			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<" ";
		}
			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
}
void caseP(sports tempsports,int& listx,int& listy,fstream& myfile, int id, float&total)
{/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	string filename;
int  num, out=0;
float quantity;
			filename = "sports.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())

			{
				cout<<"Could not find file"; _getch();
			}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempsports.getID();
				gotoxy(60, 8);
				cout<<tempsports.getTitle();
				gotoxy(100, 8);
				cout<<tempsports.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempsports.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
					gotoxy(20, 8);
				clean();
				out = 1;
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				int temp = tempsports.getQuantity();
				temp = temp - quantity;
				tempsports.setQuantity(temp);
				//cout<<"temp"<<tempsports.getQuantity();
				tempsports.setID(id);												//!!! E.SetAll() over here !!!
	
				//myfile.seekg(id-1,ios::beg);
				//myfile.write(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
				//myfile.close();
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempsports.getID()
					<<setw(20)<<tempsports.getTitle()
					<<setw(20)<<tempsports.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempsports.getRate()
					<<setw(20)<<quantity * tempsports.getRate();
				total += quantity * tempsports.getRate();
				clean();
				out = 1;
				break;

			}
		}
		myfile.clear();
			myfile.seekg((id- 1000)*sizeof(sports), ios::beg);
	if(myfile.fail())
	{cout<<".";
	myfile.clear();
	fstream check("sport.dat", ios::binary|ios::in|ios::out);
	tempsports.write(check);
	check.close();
	}
	else
	{
	if(out!=0)
		tempsports.write(myfile);
	if(myfile.fail())
	{cout<<".";}
	}
	
			



		
		if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
						if(myfile.is_open())
						myfile.close();
					
					
			}

			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<"      ";
		}
			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
}
void caseT(stationery tempstat, int &listx, int &listy,fstream& myfile, int id , float&total)
{/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
	string filename;
int  num, out=0;
float quantity;
	
	filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
		
			if(tempstat.getID() == id)
			{
				gotoxy(20, 8);
				cout<<tempstat.getID();
				gotoxy(60, 8);
				cout<<tempstat.getTitle();
				gotoxy(100, 8);
				cout<<tempstat.getBarcode();
				gotoxy(20, 15);
				cout<<"Enter Quantity:";
				cin>>quantity;
				if(quantity>tempstat.getQuantity()||quantity<0)
				{
					gotoxy(20, 16);
					cout<<"Not enough Items present.";
					out = 1;
					Sleep(1000);
					myfile.close();
					gotoxy(20, 8);
				clean();
					break;
				}
				gotoxy(20,15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";
				tempstat.setQuantity((tempstat.getQuantity()-quantity));
				tempstat.setID(id);												//!!! E.SetAll() over here !!!
	
				//myfile.seekg(id-1,ios::beg);
				//myfile.write(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
				
				gotoxy(listx,listy++);
				cout<<setw(10)<<tempstat.getID()
					<<setw(20)<<tempstat.getTitle()
					<<setw(20)<<tempstat.getBarcode()
					<<setw(20)<<quantity
					<<setw(20)<<tempstat.getRate()
					<<setw(20)<<quantity * tempstat.getRate();
				total += quantity * tempstat.getRate();
				clean();
				out = 1;
				break;

			}
		
			



		}


			myfile.clear();
			
		
			myfile.seekg((id- 2000)*sizeof(stationery), ios::beg);
	if(myfile.fail())
	{cout<<".";
	myfile.clear();
	fstream check("stationery.dat", ios::binary|ios::in|ios::out);
	tempstat.write(check);
	check.close();
	}
	else
	{
	if(out!=0)
		tempstat.write(myfile);
	if(myfile.fail())
	{cout<<".";}
	}
		
			if(out == 0)
			{
				SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					if(!myfile.is_open())
					{myfile.close();}
					clean();
						if(myfile.is_open())
						myfile.close();
					
					
			}


			for (int i = 6 ; i < 40 ; i++)
		{
			gotoxy(0,i);
			cout<<"      ";
		}

			gotoxy(119, 48);
			cout<<"TOTAL :";
			SetConsoleTextAttribute(hConsole, 124);
			cout<<total;
			SetConsoleTextAttribute(hConsole, 121);
		
		
}



void clean()
{               gotoxy(20, 8);
				cout<<"                              ";
				gotoxy(60, 8);
				cout<<"                              ";
				gotoxy(100, 8);
				cout<<"                     ";
				gotoxy(20, 15);
				cout<<"                                   ";
				gotoxy(20, 16);
				cout<<"                                   ";}



//////////////////////////
int search(string a)
{

	string filename;
	sports tempsports;
	electronics tempelec;
	stationery tempstat;
	fstream myfile;
int  num, out=0;


///////////////////////////////////////////////////////////////////
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getTitle() == a)
			{
				return tempelec.getID();
			}
		}
			
		
	//////////////////////////////////////////////////////////////////////////
				myfile.close();
				filename = "sports.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getTitle() == a)
			{
				return tempsports.getID();
			}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
			///
			//cout<<"-"<<tempstat.getID();
			///
			if(tempstat.getTitle() == a)
			{return tempstat.getID();}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
		
	return 0;
}

//////////////////////////







int barsearch(string a)
{
	string filename;
	sports tempsports;
	electronics tempelec;
	stationery tempstat;
	fstream myfile;
int  num, out=0;


///////////////////////////////////////////////////////////////////
filename = "electronics.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(electronics);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(electronics), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempelec), sizeof(tempelec));
			///
			//cout<<"-"<<tempelec.getID();
			///
			if(tempelec.getBarcode() == a)
			{
				return tempelec.getID();
			}
		}
			
		
	//////////////////////////////////////////////////////////////////////////
				myfile.close();
				filename = "sports.dat";
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(sports);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(sports), ios::beg);
			if(!myfile.is_open())
			{cout<<"Could not find file"; _getch();}
			myfile.read(reinterpret_cast<char*>(&tempsports), sizeof(tempsports));
			///
			//cout<<"-"<<tempsports.getID();
			///
			if(tempsports.getBarcode() == a)
			{
				return tempsports.getID();
			}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		filename = "stationery.dat";
		
			
		myfile.open(filename.c_str(), ios::in|ios::binary|ios::out);
		myfile.seekg(0, ios::end);
		num  = myfile.tellg();
		num = num / sizeof(stationery);
		/////
		//cout<<" ASD" <<num;
		//_getch();
		/////
		for(int i = 0; i < num ; i++)
		{
			
			myfile.seekg(i*sizeof(stationery), ios::beg);
			if(!myfile.is_open())

			{
				gotoxy(20, 15);
				cout<<"Could not find file"; _getch();gotoxy(20,15);cout<<"                   ";
			}
			myfile.read(reinterpret_cast<char*>(&tempstat), sizeof(tempstat));
			///
			//cout<<"-"<<tempstat.getID();
			///
			if(tempstat.getBarcode() == a)
			{return tempstat.getID();}
		}
		myfile.close();
		//////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, 124);
				gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"                     ";
					Sleep(200);
					gotoxy(20, 16);
					cout<<"Item Does not Exist.";
					_getch();
					SetConsoleTextAttribute(hConsole, 121);
					clean();
		
	return 0;

}

void cleanlowerbox()
{
	int __x=16,__y=25;
	
		 __x=17,__y=25;
	
	for (;__y<55;__y++)
	{	

		gotoxy(__x,__y);
		cout<<setw(130)<<" ";
		                                                            
	}	   
}