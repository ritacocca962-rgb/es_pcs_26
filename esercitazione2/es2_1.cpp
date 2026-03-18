using namespace std; 
#include <iostream>
#include <cmath>        
int main(void) {
	static const int N=4; 
	
	double arr[N]={5.9, 2.2, 3.2, 4.4}; 
	double M= arr[0]; 
	double m= arr[0]; 
	double somma = 0.0; 
	double media; 
	double dev_stad; 
	double somma2=0.0; 
	for (int i=0; i<N;  i++) {

		if (arr[i] >=M) {
			 M= arr[i]; 	
		}
		if (arr[i]<= m) {
			 m= arr[i]; 
		}
		somma+= arr[i]; 
		media= somma/N; 
		somma2+=(arr[i]-media)* (arr[i]-media); 
		
		dev_stad= sqrt(somma2/(N-1)); 
	}
	cout << "il massimo è " << M << "\n"; 
	cout << "il minimo è " << m << "\n"; 
	cout << "la media è " << media << "\n"; 
	cout << "la deviazione standard è " << dev_stad << "\n"; 
	
	
	return 0; 
}