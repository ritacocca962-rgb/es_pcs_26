#pragma once
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <optional>

template<typename I>    // in questo file metto tutti gli algoritmi per ordinare 
bool is_sorted(const std::vector<I>& vec){   
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
template<typename I> 
void bubblesort(std::vector<I>& vec) // non metto const perche deve poter essere modificata
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
template<typename I> 
//std::optional<I>
void insertion(std::vector<I>& vec)
{
	
	for (size_t j=1; j < (vec.size()); j++){
		I val=vec[j]; 
		size_t i=j;
		while(i>0 && vec[i-1]>val) {
			vec[i]=vec[i-1];	
			--i;
		};
		vec[i]=val;
	};
};
//implemento la selection sort
template<typename I>
//std::optional<I>
void selection(std::vector<I>& vec)
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