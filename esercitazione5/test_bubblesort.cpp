#include "sorts.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "randfiller.h"
#include <cstdlib> // necessario per rand()

int main() {
	randfiller rf; //chiamo la funzione rf per riempire il vettore
	for (int i=0; i<100; i++) {   // creo un ciclo for da 0 a 100 poichè voglio 100 vettori
		int dim = rand()%1000; 
		std::vector<int> vec(dim); 
		rf.fill(vec, -1000,1000); 
		bubblesort(vec);  // applico il bubblesort implementato in sorts.hpp ai vettori generati in modo casuali
		if (!is_sorted(vec)) {  // vedo se è effettivamente ordinato
			return EXIT_FAILURE; 
		};
	};
	std::vector<std::string> vecs = {"casa", "primavera", "famiglia", "tavolo", "computer", "bicchiere", "acqua", "scuola", "studio", "ciao", "frutta"};
	bubblesort(vecs); 
	if (!is_sorted(vecs)) {
		return EXIT_FAILURE; 
	};
    return EXIT_SUCCESS; 	
};
		
		
		
		