#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include "randfiller.h"
#include "sorts.hpp"
#include "timecounter.h"

int main()
{
	randfiller rf; //chiamo la funzione rf per riempire il vettore
	timecounter tc;
	for (int n=4; n <= 8192 ; n*=2) {  
		std::vector<int> vec(n); 
		rf.fill(vec, -1000,1000); 
		std::vector<int> vec_bubble = vec; 
		std::vector<int> vec_ins = vec;
		std::vector<int> vec_sel = vec; 
		std::vector<int> vec_time = vec; 
		std::vector<int> vec_mergesort= vec; 
		std::vector<int> vec_quick= vec;
		
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
		
		tc.tic(); 
		mergesort(vec_mergesort, 0, (int)vec_mergesort.size()-1); 
		double t_merge= tc.toc(); 
		
		tc.tic(); 
		quicksort(vec_quick, 0, (int)vec_quick.size()-1);  
		double t_quick= tc.toc(); 
		
		std::cout << "bubblesort: "<< t_bubble << "\n";  
		std::cout << "insertionsort: "<< t_ins << "\n";  
		std::cout << "selectionsort: "<< t_sel << "\n"; 
		std::cout << "time: " << t_time << "\n"; 
		std::cout << "mergesort: "<< t_merge << "\n"; 
		std::cout << "quicksort: "<< t_quick << "\n"; 	
	};
	
	std::cout << "calcolo della media su 100 vettori" << "\n"; 
	int num_vec=100; 
	int dim= 1000;  
	std::vector<std:: vector<int>> matrix(num_vec, std:: vector <int>(dim)); 
	for (int i=0; i< num_vec; ++i){ 
		rf.fill(matrix[i], -1000, 1000); 
	};
	tc.tic(); 
	for (int i=0; i< num_vec; ++i) {
		quicksort(matrix[i], 0, (int)matrix[i].size()-1);
	};
	double tempo_tot= tc.toc(); 
	double media = tempo_tot / num_vec; 
	std::cout<< "tempo medio quicksort: " << media <<"\n"; 

    return 0; 	
};
