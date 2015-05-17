#include "miscfunc.h"
#include <iostream>
#include "electronics.h"
#include <iomanip>
#include "menu.h"
#include <sstream>
#include "sports.h"
#include "stationery.h"
using namespace std;
int geti(int min , int max )
{
	int flag=0;
	if(min!=0 || max!=0)flag = 1;
    int posx = wherex(), posy = wherey();
	int x;
	
	jump:
	do{
        gotoxy(posx, posy);
        cout<<"        ";
        gotoxy(posx, posy);
		cin>>x;
		if(!cin.fail())
			break;
		else{
			gotoxy(posx, posy);
			cout<<"     ";
			
		cin.clear();
		cin.ignore(1000,'\n');
		}
	}while(1);
	
	if(flag)
	{
                    if(x<min || x > max)
                    goto jump;
                      }


return x;
}

float getf(int min , int max )
{
	int flag=0;
	if(min!=0 || max!=0)flag = 1;
    int posx = wherex(), posy = wherey();
	float x;
jump:
			
	do{
        gotoxy(posx, posy);
        cout<<"        ";
        gotoxy(posx, posy);
		cin>>x;
		if(!cin.fail())
			break;
		else{
			gotoxy(posx, posy);
			cout<<"     ";
			
		cin.clear();
		cin.ignore(1000,'\n');
		}
	}while(1);
	
	if(flag)
	{
                    if(x<min || x > max)
                    goto jump;
                      }

return x;
}


int get_electronics_id()
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	electronics temp(1);
	fstream myfile("electronics.dat", ios::binary|ios::out|ios::in);
	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(electronics);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"--"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+1;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty));
			
		
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}







int get_sports_id()
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	sports temp(1);
	fstream myfile("sports.dat", ios::binary|ios::out|ios::in);
	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(sports);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"  ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"  --"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+1000;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty))+999;
			
			
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}




int get_stationery_id()
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	stationery temp(1);
	fstream myfile("stationery.dat", ios::binary|ios::out|ios::in);
	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(stationery);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"  ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"  --"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+2000;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty))+1999;
			
			
		
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}











//////////////////////////////////
int get_stationery_id(fstream& myfile)
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	stationery temp(1);

	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(stationery);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"  ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"  --"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+2000;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty))+1999;
			
			
		
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}





//////////////////////////////////


int get_electronics_id(fstream& myfile)
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	electronics temp(1);
	
	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(electronics);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"--"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+1;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty));
			
			
		
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}







int get_sports_id(fstream& myfile)
{
	int posx = wherex(), posy = wherey()+1, consty = wherey()+3;

	sports temp(1);
	
	myfile.seekg(0, ios::end);
	int count = myfile.tellg();
	if(count == 0 )
	{
		gotoxy(wherex(), wherey());
		cout<<"No Items Present";
		return 0;
	}
	count = count / sizeof(sports);
	myfile.seekg(0 , ios::beg);
	
		
			
				gotoxy(posx, posy++);
				cout<<"  ID"<<setw(10)<<"Title"<<setw(10)<<"Quantity"<<setw(10)<<"Barcode";
				gotoxy(posx, posy++);
				cout<<"  --"<<setw(10)<<"-----"<<setw(10)<<"--------"<<setw(10)<<"-------";
			myfile.seekg(0,ios::beg);
			for(int i  =0 ; i<count; i++)
			{
				
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				gotoxy(posx, posy++);
				
				
				cout<<temp.getID()<<setw(10)<<temp.getTitle()<<setw(10)<<temp.getQuantity()<<setw(10)<<temp.getBarcode();
			}

			Menu mymenu(count);
			mymenu.changecolour(121,121);
			int number;
			string id_string;
			ostringstream ostr;
			gotoxy(posx, consty);
			for(int i = 0 ; i  <  count ; i++)
			{
				number  = i+1000;
				 

     //output string stream
    ostr << number; //use the string stream just like cout,
    //except the stream prints not to stdout but to a string.

    string id_string = ostr.str(); 

	
				mymenu.setoptions(i+1, id_string);
				ostr.str("");
				ostr.clear();

			}
			int choice;
			choice = (mymenu.updatemenu(posx, consty))+999;
			
			
		
			for (int i = 0 ; i < count+6 ; i++)
			{
				gotoxy(posx, (consty++) - 3);
				cout<<"                                                                      ";

			}
			
			return choice;


}


