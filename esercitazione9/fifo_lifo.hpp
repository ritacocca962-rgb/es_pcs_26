#include <queue>
#include <stack>
// per la coda del BFS
template <typename T>
class fifo {
	std::queue<T> coda; 
public: 
	void put(const T& val) {
		coda.push(val);  //aumento la coda di uno 
	}; 
	T get() {
		T val = coda.front(); //mi prendo il primo elemento del vettore e lo elimino 
		coda.pop(); 
	return val; 
	}; 
	bool empty() const{
	return coda.empty(); 
	}; 
}; 

//coda (DFS) 
template <typename T>
class lifo {
	std::stack<T> stack; 
public: 
	void put(const T& val) {
		stack.push(val); 
	}; 
	T get() {
		T val = stack.top(); //rimuovo l'ultimo elemento 
		stack.pop(); 
		return val; 
	}; 
	
	bool empty() const{
		return stack.empty(); 
	}; 
}; 