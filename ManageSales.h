#include <fstream>
#include "electronics.h"
#include "sports.h"
#include "stationery.h"
#include <string>
using namespace std;
class managesales
{
private:
	string title, barcode;
	unsigned int id;
	char type;
	float price;
	float quantity;
	string filename;
public:
	//Constructor, Destructor 
	managesales(){}
	managesales(char a)
	{
		filename = "available.dat";
		fstream myfile, salesfile;
		int num;
		myfile.open("electronics.dat", ios::in|ios::binary);
		salesfile.open(filename.c_str(), ios::out|ios::binary);
		if(!myfile.is_open())
		{
			cout<<"Could not open electronics.dat";
		}
		else
		{
			electronics temp;
			myfile.seekg(0, ios::end);
			num = myfile.tellg();
			num = num / sizeof(electronics);
			myfile.seekg(0, ios::beg);
			for(int i  = 0; i<num;i++)
			{
				//myfile.seekg(0, ios::beg);

				myfile.seekg(sizeof(electronics)*i, ios::beg);
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(electronics));
				title = temp.getTitle();
				barcode = temp.getBarcode();
				id = temp.getID();
				this->set_type();
				price = temp.getRate();
				quantity = temp.getQuantity();
				salesfile.write(reinterpret_cast<char*>(this), sizeof(*this));

			}



		}
		myfile.close();

			myfile.open("sports.dat", ios::in|ios::binary);
			if(!myfile.is_open())
		{
			cout<<"Could not open sports.dat";
		}
		else
		{
			sports temp;
			myfile.seekg(0, ios::end);
			num = myfile.tellg();
			num = num / sizeof(electronics);
			myfile.seekg(0, ios::beg);
			for(int i  = 0; i<num;i++)
			{
				myfile.seekg(sizeof(sports)*i, ios::beg);
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(sports));
				title = temp.getTitle();
				barcode = temp.getBarcode();
				id = temp.getID();
				this->set_type();
				price = temp.getRate();
				quantity = temp.getQuantity();
				salesfile.write(reinterpret_cast<char*>(this), sizeof(*this));

			}



		}
			myfile.close();




			myfile.open("stationery.dat", ios::in|ios::binary);
			if(!myfile.is_open())
		{
			cout<<"Could not open stationery.dat";
		}
		else
		{
			stationery temp;
			myfile.seekg(0, ios::end);
			num = myfile.tellg();
			num = num / sizeof(stationery);
			myfile.seekg(0, ios::beg);
			for(int i  = 0; i<num;i++)
			{
				myfile.seekg(sizeof(stationery)*i, ios::beg);
				myfile.read(reinterpret_cast<char*>(&temp), sizeof(stationery));
				title = temp.getTitle();
				barcode = temp.getBarcode();
				id = temp.getID();
				this->set_type();
				price = temp.getRate();
				quantity = temp.getQuantity();
				salesfile.write(reinterpret_cast<char*>(this), sizeof(*this));

			}



		}
			myfile.close();
			salesfile.close();


	}



	
	//All get functions


	int search_by_id()
	{
		int location;
		fstream sales(this->get_filename().c_str(),ios::in|ios::binary);
		managesales temp;
		sales.seekg(0, ios::end);
		int num;
		num = sales.tellg();
		num = num / sizeof(managesales);
		sales.seekg(0, ios::beg);
		for(int i = 0 ; i< num ; i++)
		{
			sales.seekg(sizeof(managesales)*i, ios::beg);
			sales.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if(temp.get_id()==this->get_id())
			{*this = temp;location = sales.tellg();location = location / sizeof(managesales);return location;}
			
		}
		return 0;


	}
	////////////////////////////////
	int search_by_title()
	{
		int location;
		fstream sales(this->get_filename().c_str(),ios::in|ios::binary);
		managesales temp;
		sales.seekg(0, ios::end);
		int num;

		num = sales.tellg();
		num = num / sizeof(managesales);
		sales.seekg(0, ios::beg);
		for(int i = 0 ; i< num ; i++)
		{
			sales.seekg(sizeof(managesales)*i, ios::beg);
			sales.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if(temp.get_title()==this->get_title())
			{*this = temp;location = sales.tellg();location = location / sizeof(managesales);return location;}
			
		}
		return 0;


	}
	////////////////////////////////
int search_by_barcode()
	{
		fstream sales(this->get_filename().c_str(),ios::in|ios::binary);
		managesales temp;
		sales.seekg(0, ios::end);
		int num;
		int location;
		num = sales.tellg();
		num = num / sizeof(managesales);
		sales.seekg(0, ios::beg);
		for(int i = 0 ; i< num ; i++)
		{
			sales.seekg(sizeof(managesales)*i, ios::beg);
			sales.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if(temp.get_barcode()==this->get_barcode())
			{*this = temp;location = sales.tellg();location = location / sizeof(managesales);return location;}
			
		}
		return 0;


	}
	////////////////////////////////

	void write_in_file(int location)
	{
		fstream myfile;
		myfile.open(this->get_filename().c_str(), ios::out|ios::in|ios::binary);
		myfile.seekg(location*sizeof(*this), ios::beg);
		myfile.write(reinterpret_cast<char*>(this), sizeof(*this));
		myfile.close();

		string s;
		switch(this->get_type())
		{
		case 'E':
			s = "electronics.dat";
			break;
		case 'P':
			s = "sports.dat";
			break;
		case 'T':
			s = "stationery.dat";
			break;
		}


		myfile.open(s.c_str(), ios::in|ios::out|ios::binary);
		myfile.seekg(location, ios::beg);
		electronics temp;
		temp.search_by_id(this->get_id());
		myfile.write(reinterpret_cast<char*>(this), sizeof(*this));
		


		

	}







////////////////////////////////////////

	 string get_filename()
	{return filename;}
	float get_quantity()
	{
		return quantity;
	}
	float get_price()
	{
		return price;
	}
	char get_type()
	{return type;}
	string get_title()
	{return title;}
	string get_barcode()
	{return barcode;}
	unsigned int get_id()
	{return id;}
	//All set functions
	void set_filename(string a)
	{
		filename = a;
	}

	void set_quantity(float a)
	{quantity = a;}
	void set_price(float a)
	{
		price = a;
	}

	void set_type()
	{
		if(id>0 && id < 1000) 
			type = 'E';
		if(id>=1000 && id < 2000) 
			type = 'P';
		if(id>=2000 && id < 3000) 
			type = 'T';

	}
	void set_title(string a)
	{
		title  =  a;

	}
	void set_barcode(string a)
	{
		barcode =a ;
	}

	void set_id(unsigned int a)
	{id =a ;}
};
//string managesales::filename = "availableitems.dat";

int managesalecase ();