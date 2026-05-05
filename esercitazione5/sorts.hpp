
#pragma once
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <optional>
#include <cmath>

template<typename T>    // in questo file metto tutti gli algoritmi per ordinare 
bool is_sorted(const std::vector<T>& vec){   
	if (vec.size()==0){
		return true;   // se il vettore ha 0 elementi allora lo consideriamo già ordinato
	};
	for (size_t i=0; i<(vec.size()-1); ++i) {  
		if (vec[i] > vec[i+1]) {
			return false; 
		};
	};
	return true;	
};

// implemento bubblesort
template<typename T> 
void bubblesort(std::vector<T>& vec) // non metto const perche deve poter essere modificata
{
	for (size_t i=0; i < vec.size(); i++){ 
		for (size_t j=(vec.size()-1); j > i; j--) { // parto dall'ultimo el e vado verso sinistra 
			if (vec[j]<vec[j-1]){
				std::swap(vec[j],vec[j-1]);
					};
				};
			};
};
// implemento l'insertion 
template<typename T> 

void insertion(std::vector<T>& vec)
{
	
	for (size_t j=1; j < (vec.size()); j++){
		T val=vec[j]; 
		size_t i=j;
		while(i>0 && vec[i-1]>val) {
			vec[i]=vec[i-1];	
			--i;
		};
		vec[i]=val;
	};
};
//implemento la selection sort
template<typename T>

void selection(std::vector<T>& vec)
{
	for (size_t i=0; i < (vec.size()-1); i++){
		size_t min = i; 
		for (size_t j=i+1; j< vec.size(); j++) {
			if (vec[j]<vec[min]) {
				min=j; 
			};
		};
		std::swap(vec[i],vec[min]);	
			
	};
};

//implemento il merge 
template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r)
{
	int n1=q-p+1; 
	int n2= r-q; 
	
	std::vector<T> L(n1), R(n2); // mi creo i due vettori 
	for (int i=0; i< n1-1; i++) {
		L[i]= vec[p+i-1]; 
	};
	for (int j=0; j<n2-1; j++){ 
		R[j]= vec[q+j]; 
	};
	
	int i=0; 
	int j=0; 
	int k=p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k]=L[i]; 
			i+=1; 
		} else {
			vec[k] = R[j]; 
			j+=1; 
		};
		k+=1; 
	};
	while (i < n1) {
		vec[k] = L[i]; 
		i+=1; 
		k+=1; 
	}; 
	while ( j < n2) {
		vec[k] = R[j]; 
		j+=1; 
		k+=1; 
	};
};

//implemento il mergesort
template<typename T>
void mergesort(std::vector<T>& vec, int p, int r) { 
	if (p<r) {
		int q = std::floor((p+r)/2); 
		mergesort( vec, p, q);
		mergesort( vec, q+1, r);
		merge(vec, p, q, r);
	};
};


template<typename T>
int m_partition(std::vector<T>& vec, int p, int r) 
{
	T x=vec[r]; 
	int i=p-1; 
	for (int j = p; j <= r-1; j++) {
		if (vec[j] <=x ) {
			i+=1;
			std::swap(vec[i], vec[j]); 
		};
	};
	std::swap(vec[i+1], vec[r]); 
	
	return int(i+1); 
};
	
	
	
template<typename T>
void quicksort(std::vector<T>& vec, int p, int r)
{
	if (p<r) {
		int q=m_partition( vec, p, r);
		quicksort(vec, p, q-1);
		quicksort(vec, q+1, r);
	}; 
}; 
		
	