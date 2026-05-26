
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <cmath>
double condA(const Eigen::MatrixXd& A) {
	Eigen::JacobiSVD<Eigen::MatrixXd> svd(A); 
	Eigen::VectorXd singularValuesA= svd.singularValues(); 
	return singularValuesA.maxCoeff()/singularValuesA.minCoeff(); 
}; 

int main(int argc, char **argv) 
{
  const double tol = 1.0e-15;
  unsigned int n = 3;
  
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

  if (std::abs(B.determinant()) < tol)
    return -1;
  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
  Eigen::VectorXd b= A*x_ex; 
  Eigen::VectorXd x = Eigen::VectorXd::Zero(n); 
  Eigen::VectorXd res= b- A*x; 
  double res0= res.norm(); 
  Eigen::VectorXd p= res; 
  
  const unsigned int it_max = 10000;
  unsigned int it = 0;
  const double res_tol = 1.0e-12;
  double alpha = 0.0; 
  double betha = 0.0; 

  std::cout.precision(2);
  std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

  while ( it < it_max && (res.norm()/res0) > res_tol){ //il ciclo viene eseguito dinche la norma di r non è più piccola di una tolleranza scelta da noi 
		alpha = (p.transpose()*res).value()/(p.transpose()*A*p).value(); //mi restituisce uno scalare
		x = x + alpha*p;  
		Eigen::VectorXd next_res = res -alpha * A * p; 
	    betha = (p.transpose()*A*next_res).value()/ (p.transpose()*A*p).value(); 
		p= next_res + betha * p; 
		res = next_res; 
		 
		it++; 
  }; 
		
	double err_rel = (x_ex.norm() == 0.0) ?  (x-x_ex).norm() :
												(x-x_ex).norm()/x_ex.norm(); // per trovare l'errore relativo, la norma di x_ex è pari a x_ex se la nroma è 0, a.m. è fratto x_ex
 
	std::cout.precision(4);
	std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< std::endl;
	std::cout<< std::scientific<< it<< "/"<< it_max<< std::endl;
	std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< std::endl;
	std::cout<< std::scientific<< res.norm() / res0<< "/"<< res_tol<< std::endl;
	std::cout<< std::scientific<< "err_rel"<< std::endl;
	std::cout<< std::scientific<< err_rel<< std::endl;
	std::cout<< std::scientific<< "soluzione"<< std::endl;
	std::cout<< std::scientific<< x << std::endl;
	std::cout<< std::scientific<< "direzione di discesa: " << p << std::endl; 
	std::cout<< std::scientific<< "valore alpha: "<< alpha << std::endl; 
	std::cout<< std::scientific<< "valore betha: "<< betha << std::endl; 
  

  return 0;
}; 