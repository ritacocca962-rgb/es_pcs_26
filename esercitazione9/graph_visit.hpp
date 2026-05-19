#include <set>
#include <map>
#include "unidirected_graph.hpp"
#include "fifo_lifo.hpp"


template <typename contenitore>
unidirected_graph graph_visit(const unidirected_graph& graph, int n_sorg, contenitore& c){
	unidirected_graph albero; //grafo contenente l'albero risultante dalla visita 
	std::set<int> n_visitati; //inizializzo unn sei di interi che contiene i nodi visitati 
	c.put(n_sorg); 
	
	n_visitati.insert(n_sorg); //il primo nodo visitato corrisponde al nodo sorgente 
	
	while(!c.empty()){ //in base al contenitore faccio la visita in profondità o in ampiezza
		int u= c.get(); 
		for (const auto& w: graph.neighbours(u)){
			if (n_visitati.find(w)==n_visitati.end()) { //verifico se il nodo vicino è già stato visitato, così posso aggiungerlo 
				n_visitati.insert(w); 
				albero.add_edge(unidirected_edge(u,w)); //sto aggiungendo elementi all'albero (così me lo costruisco) 
				c.put(w); 
			}; 
		}; 
	}; 
	return albero;
}; 

// versione DFS per visitare il grafo 
void recursive_dfs_impl(const unidirected_graph& graph , int u, std::set<int>& n_visitati, unidirected_graph& albero){
		n_visitati.insert(u); 
		for (int w: graph.neighbours(u)){
			if (n_visitati.find(w)==n_visitati.end()){
				albero.add_edge(unidirected_edge(u,w)); 
				recursive_dfs_impl(graph, w, n_visitati, albero); 
			};
		}; 
}; 

unidirected_graph recursive_dfs(const unidirected_graph& graph, int n_sorg){
	unidirected_graph albero; 
	std::set<int> n_visitati; 
	recursive_dfs_impl(graph, n_sorg, n_visitati, albero); 
	return albero; 
}; 
	
			
		 
	