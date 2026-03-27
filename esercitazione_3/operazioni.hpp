#include <cmath>
#include <concepts>
#include <iostream>
#include <numeric> // per calcolare l'MCD
template<typename I> 
requires std::integral<I>
class rational {
	I num_;
	I den_;
	void simplify() {  // come gestire la frazione
		if (den_==0 && num_==0) 
				return;  
		else if (den_==0 && num_!=0) 
				return; 
			
			
		if (den_!=0) { // caso in cui posso semplificare la frazione 
			I mcd= std::gcd(num_,den_); 
			if (mcd!=0) {
				num_=num_/mcd; 
				den_= den_/mcd;  
		};
	};
	}
	
public:
	bool Inf() const { return den_==0 && num_!=0; }
	bool NaN() const { return den_==0 && num_==0; }
	rational() : num_(0), den_(1) {} //inizializzo le variabili a 0 e 1 
	
	
	rational(const I& n, const I& d):
	num_(n), den_(d) {
		simplify(); // semplifica se possibile, cioè se siamo nei casi sopra specificati 
	}
	I num() const {return num_;}
	I den() const {return den_;}
	
	// definisco le operazioni 
	rational& operator+=(const rational& other) {
		if (NaN() || other.NaN()) {
			num_=0; 
			den_=0; 
			return *this; 
		};
		if (Inf() || other.Inf()) {
			num_=other.num_; 
			den_=0; 
			return *this;
		};
		num_=num_*other.den_+ other.num_*den_; 
		den_=den_*other.den_; 
		simplify(); 
		return *this;
	};
	rational operator+(const rational& other) const{
		rational ret=*this; 
		ret +=other; 
		return ret; 
	};
	rational& operator*=(const rational& other) {
		if (NaN() || other.NaN()) {
			num_=0; 
			den_=0; 
			return *this; 
		};
		if (Inf() || other.Inf()) {
			num_=other.num_; 
			den_=0; 
			return *this;
		}; 
		if ((num_==0 && other.Inf()) || (Inf() && other.num_==0)) {
			num_=0; 
			den_=0; 
			return *this;
			}; 
		num_*=other.num_; 
		den_*=other.den_;
		simplify(); 
		return *this; 
	}; 
	rational operator*(const rational& other) const {
		rational ret=*this; 
		ret *=other; 
		return ret; 
	};
	
	rational& operator-=(const rational& other){
		if (NaN() || other.NaN()) {
			num_=0; 
			den_=0; 
		return *this; 
		};
		if (Inf() && other.Inf()){
			num_=other.num_; 
			den_=0; 
			return *this; 
			};
		num_=num_*other.den_-den_*other.num_; 
		den_=den_*other.den_; 
		simplify(); 
		return *this; 
	};
	rational operator-(const rational& other) const {
		rational ret =*this; 
		ret -= other; 
		return ret; 
	}; 
	rational& operator/=(const rational& other) {
		if ((NaN() || other.NaN()) && ( Inf() && other.NaN())) {
			num_=0; 
			den_=0; 
		return *this; 
		};
		if (Inf() && other.Inf()){
			num_=0; 
			den_=0; 
			return *this; 
		}; 
		if ((num_==0 && other.Inf()) || (Inf() && other.num_==0)) {
			num_=0; 
			den_=0; 
			return *this;
			}; 
		if ((num_!=0 && other.Inf())) {
			num_=0; 
			den_= 1; 
			return *this; 
		};
		if ((num_!=0 && den_==0)) {
			num_=0; 
			den_=1;
			return *this; 
		}; 
	
		num_*=other.den_; 
		den_*=other.num_;
		simplify(); 
		return *this; 
	};
	 
	rational operator/(const rational& other) const {
		rational ret =*this; 
		ret /= other; 
		return ret;
	};
};
	
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r){
	if (r.NaN()){
		os << "NaN"; 
	} else if (r.Inf()) {
		os << "Inf"; 
	} else {
		os << r.num()<< "/" << r.den(); 
	};
	return os;
	
 };

		
		

