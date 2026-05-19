#include <iostream>
#include <vector>
#include <map>
#include "graph_visit.hpp"
#include "dijkstra.hpp"
#include "unidirected_graph.hpp"
#include "grafo_rapp.hpp"


int main(){
	unidirected_edge e1(1,2); 
	unidirected_edge e2(1,3); 
	unidirected_edge e3(1, 4);
	unidirected_edge e4(1,6); 
	unidirected_edge e5(2,4); 
	unidirected_edge e6(2,5); 
	unidirected_edge e7(2,7); 
	unidirected_edge e8(4, 7);
	unidirected_edge e9(5,7); 
	unidirected_edge e10(6,7);
	unidirected_edge e11(6,8);
	unidirected_edge e12(7,9); 
	unidirected_edge e13(8,9);
	
	unidirected_graph g1; 
	g1.add_edge(e1); 
	g1.add_edge(e2);
	g1.add_edge(e3); 
	g1.add_edge(e4);
	g1.add_edge(e5); 
	g1.add_edge(e6); 
	g1.add_edge(e7);
	g1.add_edge(e8); 
	g1.add_edge(e9);
	g1.add_edge(e10);
	g1.add_edge(e11); 
	g1.add_edge(e12);
	g1.add_edge(e13);
	
	//test per il BFS
	fifo<int> q; 
	unidirected_graph alberoBFS= graph_visit(g1, 1, q); //in input grafo, nodo sorgente e contenitore
	std::cout << "albero creato con " << alberoBFS.all_edges().size() << " archi (BFS)" << std::endl; 
	
	// test per il DFS
	lifo<int> s; 
	unidirected_graph alberoDFS = graph_visit(g1, 1, s);  //in input grafo, nodo sorgente e contenitore 
	std::cout << "albero creato con " << alberoDFS.all_edges().size() << " archi (DFS) " << std::endl; 
	
	// test per dijkstra
	std::cout << "calcolo le distanze minime dal nodo 1: " << std::endl; 
	std::map<int,double> distanze; 
	unidirected_graph alberoDijkstra= dijkstra(g1,1, distanze); 
	for (auto const& [nodo, dist]:distanze) {
		std::cout << "la distanza dal nodo 1 al nodo " << nodo << " " << "è" << " " << dist << std::endl; 
	}; 
	std::cout<< "albero creato con " <<alberoDijkstra.all_edges().size()<<" " << "archi (Dijkstra)" <<std::endl; 
	salvare_dot(alberoBFS, "bfs.dot"); 
	salvare_dot(alberoDFS, "dfs.dot"); 
	salvare_dot(alberoDijkstra, "dij.dot"); 
	return 0; 
}; 
	