#include <iostream>
#include "unidirected_graph.hpp"
#include <algorithm>
int main(){
	unidirected_edge e1(14,4); 
	unidirected_edge e2(8,22); 
	unidirected_edge e3(31, 2);
	unidirected_edge e4(5,7); 
	
	unidirected_graph g1; 
	g1.add_edge(e1); 
	g1.add_edge(e2);
	g1.add_edge(e3); 
	g1.add_edge(e4);
	
	 std::cout << "archi nel grafo 1: " << "\n"; 
	for (const auto& e : g1.all_edges()){
		std::cout << e << " "; 
	}; 
	std::cout << std::endl;
	
    std::cout << "Nodi nel grafo 1: " << "\n";
    for (const auto& n : g1.all_nodes()) {
        std::cout << n << " ";  //n si riferisce ai nodi del grafo
    };
    std::cout << std::endl;

    
	std::cout << "Vicini del nodo 2: "; //testo la funzione dei vicini
    for (int nodo : g1.neighbours(2)) {
        std::cout << nodo << " ";
    }; 
    std::cout << std::endl;

   // test metodo edge_number e edge_at
    std::cout << "L'arco " << e1 << " ha indice: " << g1.edge_number(e1) << std::endl;
    std::cout << "L'arco in posizione 2 è: " << g1.edge_at(2) << std::endl;
	std::cout << std::endl; 
   //test operatore differenza 
    unidirected_graph g2;
    g2.add_edge(e1); 
	g2.add_edge(e1); 
	g2.add_edge(e2);
	g2.add_edge(e3); 
	
    unidirected_graph g_diff1 = g1 - g2; 
	
    std::cout << "Archi rimanenti nella differenza (g1-g2):" << std::endl;
    for (const auto& edge : g_diff1.all_edges()) {
        std::cout << edge << " ";
    };
    std::cout << std::endl;
    return 0;
}; 
	
		
