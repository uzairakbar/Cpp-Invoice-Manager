/*
                Inventory Header File
				End Semester Project File 
				Author: Smaqn
*/
# ifndef inventory_h
# define inventory_h
# include <iostream>
# include <string>
# include <fstream>
using namespace std;

class inventory							//Abstract Class
{
protected:
	static unsigned int inv_count;
	unsigned int ID;	
	float Rate;
	float Quantity;
	string Barcode;
	string Manufacturer_Supplier;
	string Title;
	string Description;
public:
	// Constructors
	inventory ();
	inventory(unsigned int) ;
	inventory(float,float,string,string,string,string) ;

	// Copy Constructor
	inventory(const inventory& );

	// Set Functions
	virtual void setCount(unsigned int) =0;
	virtual void setID (unsigned int) =0;
	virtual void setRate(float) =0;
	virtual void setQuantity (float) =0;
	virtual void setBarcode (string) =0;
	virtual void setManufacturer_Supplier (string) =0;
	virtual void setTitle (string) =0;
	virtual void setDescription (string) =0;
	virtual void setAll()=0;
	
	// Get Functions
	virtual unsigned int getCount() =0;
	virtual unsigned int getID () =0;
	virtual float getRate () =0;
	virtual float getQuantity () =0;
	virtual string getBarcode () =0;
	virtual string getManufacturer_Supplier () =0;
	virtual string getTitle () =0;
	virtual string getDescrpition () =0;

	//File-Handling Functions
	virtual void seek_object(fstream&,int) =0;
	virtual void read(fstream&) =0;
	virtual void write(fstream&)=0;
	virtual bool read_from_file(int) =0;
	virtual void write_in_file(int) =0;

	//Specialised Functions
	virtual void display () =0;
	virtual float calculate_price () =0;

	//Destructor 
	//virtual ~inventory();

};

/*
	Derived Classes
	1.Electronics 
	2.Food Items
	3.Stationary
	4.Sports Equipment
*/

# endif