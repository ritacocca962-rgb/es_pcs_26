#pragma once
#include <map>
#include <vector>
#include <set>
#include "unidirected_graph.hpp"
unidirected_graph dijkstra(const unidirected_graph& grafo, int n_sorg, std::map<int, double>& distanze) { 
	std::map<int, bool> n_assegnati; // mi segno quali sono i nodi già raggiunti
	std::set<int> visitati; 
	std::vector<int> nodi = grafo.all_nodes(); 
	std::map<int,int> predecessori; 
	
	//inizializzo i nodi 
	distanze[n_sorg]=0.0; //all'inizio sono alla carica sorgente 
	n_assegnati[n_sorg]= 1; 
	
	for (size_t i=0; i < nodi.size(); ++i) { //devo trovare il nodo con distanza minima e che non ho ancora visitato 
		int u=-1; 
		for (int n: nodi) {
			if (visitati.find(n)== visitati.end() && n_assegnati[n]) {
				if ( u==-1 || distanze[n] < distanze[u]) {
					u=n; 
				}; 
			}; 
		}; 
		if (u==-1) break; //se non trovo nodi raggiungibili esco dal for, significa che ho controllato tutti i nodi possibili, può anche darsi che sia disconnesso e quindi non ho trovato nulla 
		
		visitati.insert(u); 
		
		for (int v :grafo.neighbours(u)) {
			double peso =1.0; //associo il peso pari a 1
			double distanza2= distanze[u]+ peso;  //calcolo la distanza per ogni vicino

			//se v non è stato ancora assegnato o la distanza è minore lo salvo in n_assegnati  
			if (!n_assegnati[v] ||distanza2 < distanze[v]){
				distanze[v]= distanza2; 
				n_assegnati[v]= 1; 
				predecessori[v]=u; 
			}; 
		}; 
	}; 
	unidirected_graph alberoDijkstra; 
	for (auto const& [nodo, padre] : predecessori) {
		unidirected_edge e(padre, nodo); 
		alberoDijkstra.add_edge(e); 
	}; 
	return alberoDijkstra; 
}; 
	
		

