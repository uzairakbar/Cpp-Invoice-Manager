/*
                Employee Header File
				End Semester Project File 
				Author: Haris Suhail
*/
#ifndef employee_h
#define employee_h
#include <string>
#include <fstream>
using namespace std;
class Employee
{protected:
	static int counter;
	bool is_manager;
	string first_name, last_name, password;
	int id;
	float pay_rate, hours_worked, total_pay;
public:
	Employee();
	Employee(int);
	//             ALL GET FUNCTIONS
	static int get_counter();
	string get_first_name();
	string get_last_name();
	string get_password();
	int get_id();
	float get_pay_rate();
	float get_hours_worked();
	float get_total_pay();
	bool get_is_manager();
	//             ALL SET FUNCTIONS
	void set_is_manager(bool);
	static void set_counter(int);
	void set_first_name(string);
	void set_last_name(string);
	void set_password(string);
	void set_id(int);
	void set_pay_rate(float);
	void set_hours_worked(float);
	void set_total_pay(float);
	//           FILE IO
	void read_from_file(fstream&);
	void write_to_file(fstream&);
	void read_from_file(fstream&, int);
	void write_to_file(fstream&, int);
	//      GET AND DISPLAY ALL
	void set_all_values();
	void display_all();
};


#endif