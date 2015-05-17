# include "inventory.h"
# include <iostream>
# include <string>

# include <fstream>
using namespace std;

unsigned int inventory:: inv_count=1;

	// Constructors
	inventory :: inventory () 
	{
		ID=inv_count++;
		Rate=0;
		Quantity=0;
		Barcode="\0";
		Manufacturer_Supplier="\0";
		Title = "\0";
		Description = "\0";
	}
	inventory :: inventory (unsigned int N) : ID(N), Rate(0.0), Quantity(0.0), Barcode("\0"), Manufacturer_Supplier("\0"), Title("\0"), Description("\0")
	{}
	inventory :: inventory(float rate,float quantity,string barcode,string manu_supp,string title,string description) 
	{
		ID=inv_count++;
		Rate= rate;
		Quantity = quantity;
		Barcode = barcode;
		Manufacturer_Supplier = manu_supp;
		Title = title;
		Description = description;
	}
	// Copy Constructor
	inventory :: inventory(const inventory& a )
	{
		ID= a.ID;
		Rate= a.Rate;
		Quantity = a.Quantity;
		Barcode = a.Barcode;
		Manufacturer_Supplier = a.Manufacturer_Supplier;
		Title = a.Title;
		Description = a.Description;
	}
	// Destructor
	/*inventory :: ~inventory()
	{
		cout<<"Inventory's destructor has been called "<<endl;
	}*/

