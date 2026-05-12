#pragma once
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "unidirected_edges.hpp"

class unidirected_graph {
private:
	std::set<unidirected_edge> edges; 
public: 
	unidirected_graph() = default; //costruttore di default 
	unidirected_graph(const unidirected_graph& other) = default; //costruttore di copia
	
	//metodo add_edges
	void add_edge(const unidirected_edge& a_edge) {
		edges.insert(a_edge); 
	}; 
	
	
// metodo neighours
	std::vector<int> neighbours(int v) const { 
		std::vector<int> vicini; 
		for (const auto& a_edge : edges) {
			if (a_edge.from() == v) {
				vicini.push_back(a_edge.to()); 
			} else if (a_edge.to() == v) {
				vicini.push_back(a_edge.from()); 
			}; 
		}; 
		return vicini; 
}; 
	
// metodo all_edge
	std::vector<unidirected_edge> all_edges() const {
		return std::vector<unidirected_edge>(edges.begin(), edges.end()); 
}; 

//metodo all_nodes
	std::vector<int> all_nodes() const {
		std::set<int> nodi; 
		for (const auto& a_edge : edges) {
			nodi.insert(a_edge.from()); 
			nodi.insert(a_edge.to()); 
		}; 
		return std::vector<int>(nodi.begin(), nodi.end()); 
};

//metodo edge_number 
	int edge_number(const unidirected_edge& a_edge) const {
		int i=0; 
		for (const auto& e : edges) {
			if (e == a_edge) {
				return i; 
			}; 
			i++;
		}; 
		return -1; 
	}; 
		
//metodo edge_at 	
	unidirected_edge edge_at(size_t j) const {
		if (j >= edges.size()){
			return unidirected_edge(-1,-1); 
		};
		size_t j_vettore=0; 
		for (const auto& a_edge: edges) {
			if (j_vettore==j){
				return a_edge; 
			};
			j_vettore++; 
		}; 
		return unidirected_edge(-1,-1); 
	}; 
	
//implemento l'operatore -
	unidirected_graph operator-(const unidirected_graph& other) const{
		unidirected_graph differenza_graph; 
		for (const auto& a_edge : edges){
			if ( other.edges.find(a_edge) == other.edges.end()){
			//se non è nell'altro grafo lo tolgo
				differenza_graph.add_edge(a_edge); 
			};
		};
		return differenza_graph; 
	};
}; 
	


