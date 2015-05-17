/*
sports Header File
End Semester Project File
Author: Smaqn
*/
# ifndef sports_h
# define sports_h
# include "inventory.h"
# include <iostream>
# include <string>
# include <fstream>
using namespace std;

class sports : public inventory
{
public:
	// Constructors
	sports();
	sports(unsigned int);
	sports(float, float, string, string, string, string);

	// Copy Constructor
	sports(const sports&);

	// Over-loaded Operators
	friend istream& operator>> (istream&, sports&);
	friend ostream& operator<< (ostream&, const sports&);
	//void operator= (const sports&);										// !!! NEW !!!

	// Set Functions
	virtual void setCount(unsigned int);
	virtual void setID(unsigned int);
	virtual void setRate(float);
	virtual void setQuantity(float);
	virtual void setBarcode(string);
	virtual void setManufacturer_Supplier(string);
	virtual void setTitle(string);
	virtual void setDescription(string);
	virtual void setAll();

	// Get Functions
	virtual unsigned int getCount();
	virtual unsigned int getID();
	virtual float getRate();
	virtual float getQuantity();
	virtual string getBarcode();
	virtual string getManufacturer_Supplier();
	virtual string getTitle();
	virtual string getDescrpition();

	//File-Handling Functions
	virtual void seek_object(fstream&, int);
	virtual void read(fstream&);
	virtual void write(fstream&);
	virtual bool read_from_file(int);
	virtual void write_in_file(int);

	//Search Functions
	virtual void search_by_id(int);
	virtual void search_by_title(string);
	virtual void search_by_barcode(string);

	//Specialised Functions
	virtual void display();
	virtual float calculate_price();
	virtual int displayall();
	virtual int countcheck(fstream&);		//Changes made at 10:45 p.m
	//Destructor 
	//virtual ~sports();

};

#endif  