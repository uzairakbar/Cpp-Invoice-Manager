#ifndef exceptionhandle_h
#define exceptionhandle_h
#include <iostream>
#include "miscfunc.h"
using namespace std;


int getint(int min = 0, int max = 0)
{
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
	
	if((min)&&(max))
	{
                    if(x<min || x > max)
                    goto jump;
                      }


return x;
}

float getfloat(int min = 0, int max = 0)
{
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
	
	if((min)&&(max))
	{
                    if(x<min || x > max)
                    goto jump;
                      }

return x;
}


#endif