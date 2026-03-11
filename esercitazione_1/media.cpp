using namespace std;  
#include <fstream>
#include <string>
#include <iostream>
int main(void) {
	string filename= "input_es1.txt";
	ifstream ifs(filename); 
	while (!ifs.eof()) {
		string location;
		double temp1, temp2, temp3, temp4;
		ifs >> location >> temp1 >> temp2 >> temp3 >> temp4; 
		double media= (temp1+temp2+temp3+temp4)/4.0; 
		
		cout << location << " "<<  media << endl; 
		}
	return 0; 
	}