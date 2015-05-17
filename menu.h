#ifndef menu_h
#define menu_h

#include <string>
#include<iostream>
#include <conio.h>
#include <windows.h>
#include "miscfunc.h"
using namespace std;



class Menu
{
private:
	int number_of_options, menucolour, aftercolour,rectx, recty, recta, rectb;
	bool rect;
	string* p;

public:
	void setRectangle(int topleftx, int toplefty, int bottomrightx, int bottomrighty)
	{
		rect= true;
	rectx=topleftx;
	recty=toplefty;
	recta=bottomrightx;
	rectb=bottomrighty;

	};
	void changecolour(int main, int second)
	{menucolour = main;
	aftercolour=second;}
	Menu(int number=1):number_of_options(number), menucolour(7),aftercolour(7),rect(false)
	{
		p=new string[number];
	}

	~Menu()
	{delete [] p;}

	void setoptions (int number,string a)
	{
		if(number>number_of_options) return;
		p[number-1]=a;
	}

	int displaymenu(const int x=0,const int y=0)
	{
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, menucolour);
		
		system("cls");
		if(rect)
		drawRectangle(rectx, recty, recta,rectb );
		//gotoxy(x,y);

		
		
		int choice=1,pervy=y;
		char c;
		for(int i=0;i<number_of_options;i++ )
			{
				gotoxy(x,y+i);
				choice==(i+1)?cout<<"-->":cout<<"   ";
				cout<<i+1<<"."<<p[i];
				
			}
		do
		{	
			c=_getch();
			if(c==80||c==72)continue;
			if(c==13)break;
			c=_getch();
			if (c==80&&choice<=number_of_options)
				{		
					choice ++;
					gotoxy(x, pervy);
					cout<<"   ";
					pervy++;
					if(choice>number_of_options)
					{choice = 1;
					gotoxy(x,y);
					pervy=y;
					
					}
					else 
					{gotoxy(x, pervy);}
					cout<<"-->";




					
					
				}
			else if (c==72&&choice>=1)
				{		/*choice --;
					if(choice<1)choice = number_of_options;
					gotoxy(x, pervy);
					cout<<"   ";
					pervy--;
					gotoxy(x, pervy);
					cout<<"-->";*/
					choice --;
					gotoxy(x, pervy);
					cout<<"   ";
					pervy--;
					if(choice<1)
					{choice = number_of_options;
					gotoxy(x,y+number_of_options-1);
					pervy=y+number_of_options-1;

					
					}
					else 
					{gotoxy(x, pervy);}
					cout<<"-->";
				}

			SetConsoleTextAttribute(hConsole, aftercolour);



		}while(1);
		gotoxy(x, y +number_of_options+2);
		return choice;
	}

	static void setcolor(string a)
	{
		string as;
		as="color ";
		as=as+a;
		system(as.c_str());
		


	}

	

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
             
    
             
     
     } //REMOVE






/////////////////////////////////

int updatemenu(const int x=0,const int y=0)
	{
		/////////////////////////////////////////////
	HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col=12;



            FlushConsoleInputBuffer(hConsole);
    

/////////////////////////////////////////////
			SetConsoleTextAttribute(hConsole, menucolour);
		
		
		if(rect)
		drawRectangle(rectx, recty, recta,rectb );
		//gotoxy(x,y);

		
		
		int choice=1,pervy=y, pervchoice=1;
		char c;
		for(int i=0;i<number_of_options;i++ )
			{
				gotoxy(x,y+i);
				if(i==0)
				{SetConsoleTextAttribute(hConsole, 124);}
				cout<<p[i];
					if(i==0)
				{SetConsoleTextAttribute(hConsole, 121);}
				
			}
		do
		{	
			c=_getch();
			if(c==80||c==72)continue;
			if(c==13)break;
			c=_getch();
			if (c==80&&choice<=number_of_options)
				{		pervchoice = choice;
					choice ++;
					gotoxy(x, pervy);

					SetConsoleTextAttribute(hConsole, 121);
					cout<<p[pervchoice - 1];
					SetConsoleTextAttribute(hConsole, 124);
					pervy++;
					if(choice>number_of_options)
					{choice = 1;
					gotoxy(x,y);
					pervy=y;
					
					}
					else 
					{gotoxy(x, pervy);}
					cout<<p[choice-1];




					
					
				}
			else if (c==72&&choice>=1)
				{		/*choice --;
					if(choice<1)choice = number_of_options;
					gotoxy(x, pervy);
					cout<<"   ";
					pervy--;
					gotoxy(x, pervy);
					cout<<"-->";*/
					pervchoice = choice;
					choice --;
					gotoxy(x, pervy);

					SetConsoleTextAttribute(hConsole, 121);
					cout<<p[pervchoice-1];
					SetConsoleTextAttribute(hConsole, 124);
					pervy--;
					if(choice<1)
					{choice = number_of_options;
					gotoxy(x,y+number_of_options-1);
					pervy=y+number_of_options-1;

					
					}
					else 
					{gotoxy(x, pervy);}
					SetConsoleTextAttribute(hConsole, 124);
					cout<<p[choice-1];
					SetConsoleTextAttribute(hConsole, 121);
				}

			SetConsoleTextAttribute(hConsole, aftercolour);



		}while(1);
		gotoxy(x, y +number_of_options+2);
		return choice;
	}
/////////////////////////////////
};


#endif
