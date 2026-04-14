#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include "randfiller.h"
#include "sort.hpp"
#include "timecounter.h"

int main() {
	randfiller rf; //chiamo la funzione rf per riempire il vettore
	timecounter tc;
	for (int n=4; n<=8192 ; n*=2) {  
		std::vector<int> vec(n); 
		rf.fill(vec, -1000,1000); 
		std::vector<int> vec_bubble = vec; 
		std::vector<int> vec_ins = vec;
		std::vector<int> vec_sel = vec; 
		std::vector<int> vec_time = vec; 
		
		tc.tic(); 
		bubblesort(vec_bubble); 
		double t_bubble=tc.toc(); 
		
		tc.tic(); 
		insertion(vec_ins); 
		double t_ins=tc.toc(); 
		
		tc.tic(); 
		selection(vec_sel); 
		double t_sel=tc.toc(); 
	
		tc.tic();   
		std::sort(vec_time.begin(), vec_time.end());
		double t_time = tc.toc();
		
		std::cout << "bubblesort: "<< t_bubble << "\n"; 
		std::cout << " "; 
		std::cout << "insertionsort: "<< t_ins << "\n"; 
		std::cout << " "; 
		std::cout << "selectionsort: "<< t_sel << "\n"; 
		std::cout << " ";
		std::cout << "time: " << t_time << "\n"; 
		std::cout << " ";
		
	};
	
	
    return 0; 	
};
		







	
	

