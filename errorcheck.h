#ifndef errorcheck_h
#define errorcheck_h
#include <fstream>
using namespace std;
int geti(int min = 0, int max = 0);
float getf(int min = 0, int max = 0);
int get_electronics_id();
int get_sports_id();
int get_stationery_id();
int get_stationery_id(fstream&);
int get_electronics_id(fstream&);
int get_sports_id(fstream&);
#endif