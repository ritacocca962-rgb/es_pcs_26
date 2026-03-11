using namespace std;
#include <iostream>
#include <fstream> 
#include <sstream>
int main(int argc, const char*argv[]) {
	if (argc<2) {
		cerr << "Errore!";  
    }
	cout << "numero di parametri: " << argc << "\n"; 
	
	ifstream ifs(argv[1]); 
	if (ifs.is_open()) {
		for (int i=0; i<argc; i++) {
			cout << "file " << i << "=" << argv[i] << "\n"; 
		}
		
	} else {
		cerr << " impossibile leggere il file" ; 

	}
	return 0; 
}
	
	