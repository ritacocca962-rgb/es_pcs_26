#include <iostream>
#include "operazioni.hpp"
int main() {
	
	// casi in cui non ci sono anomalie 
 
	rational<int> r1(1,2); 
	rational<int> r2(1,6); 
	rational<int> r3=r1+r2; 
	rational<int> r4=r1*r2; 
	rational<int> r5=r1-r2; 
	rational<int> r6=r1/r2; 
	std::cout<< "casi in cui non ci sono anomalie con i valori : "<< r1 <<" "<< "e" << " "<<r2 << std::endl; 
	std::cout << r3<< std::endl; 
	std::cout<< r4<< std::endl; 
	std::cout<< r5<< std::endl; 
	std::cout<< r6<< std::endl; 
	std::cout<< "\n";
	
	rational<int> i1(1,0); 
	rational<int> i2(7,6); 
	rational<int> i3=i1+i2; 
	rational<int> i4=i1*i2; 
	rational<int> i5=i1-i2; 
	rational<int> i6=i1/i2; 
	std::cout << "casi in cui risultano anomalie: " << std::endl; 
	std::cout << i3<< std::endl; 
	std::cout<< i4<< std::endl; 
	std::cout<< i5<< std::endl; 
	std::cout<< i6<< std::endl; 
	std::cout<< "\n";
	
	rational<int> n1(3,0); 
	rational<int> n2(0,0); 
	rational<int> n3=n1+n2; 
	rational<int> n4=n1*n2; 
	rational<int> n5=n1-n2; 
	rational<int> n6=n1/n2; 
	std::cout << n3<< std::endl; 
	std::cout<< n4<< std::endl; 
	std::cout<< n5<< std::endl; 
	std::cout<< n6<< std::endl;
	rational<int> r7=  i1/n1; 
	
	std::cout<< r7<< " " << "(caso Inf/Inf)" <<  std::endl; 
	
	int v1= r2.num(); 
	int v2 = i3.den(); 
	std::cout << "\n";
	std::cout<< v1 << " " << v2<< std::endl;
	return 0; 
};

