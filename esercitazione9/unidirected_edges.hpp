#pragma once
#include <iostream>
#include <algorithm>

class unidirected_edge {
private: 
	int from_; 
	int to_; 
public: // definizione di arco
	unidirected_edge(int v1, int v2) { // il nodo più piccolo deve stare nella prima posizione 
		from_ = std::min(v1, v2);
		to_ = std::max (v1,v2); 
	}; 
	int from() const {
		return from_; 
	}; 
	int to() const {
		return to_; 
	}; 
	
	//implementiamo gli operatori 
	bool operator<(const unidirected_edge& other) const {
		if (from_ != other.from_ ) {
			return from_ < other.from_; 
		};
		return to_ < other.to_; 
	}; 
	bool operator==(const unidirected_edge& other) const {
		return ( from_ == other.from_ )  && ( to_ == other.to_ );
	}; 
};
	
	// operatore di output aggiungere inline
inline std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge){
	os << "(" << edge.from() << "," << edge.to()<< ")";  // from_ e to_ sono privati, uso quelli pubblici
return os; 
}; 
