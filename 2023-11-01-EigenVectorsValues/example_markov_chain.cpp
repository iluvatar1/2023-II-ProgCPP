#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <complex>

int main(int argc, char **argv) {
  //const int N = std::stoi(argv[1]);

  Eigen::Matrix3d A;
  A << 0.8, 0.2, 0.1,
    0.1, 0.7, 0.3,
    0.1, 0.1, 0.6;
  std::cout << A << "\n";
  Eigen::Vector3d x0;
  x0 << 0, 1, 0;
  std::cout << x0 << "\n" ;

  // Prob vector after three steps
  Eigen::Matrix3d B = A*A*A*A*A;
  Eigen::Vector3d x = B*B*B*B*B*B*B*x0;
  std::cout << x << "\n" ;
  
  //std::cout << "Here is a random matrix, A:" << std::endl 
  //          << A << std::endl << std::endl;

  Eigen::EigenSolver<Eigen::MatrixXd> es(A);
  std::cout << "The eigenvalues of A are:" << std::endl 
            << es.eigenvalues() << std::endl;
  std::cout << "The matrix of eigenvectors, V, is:" << std::endl 
            << es.eigenvectors() << std::endl << std::endl;

  //std::complex<double> lambda = es.eigenvalues()[0];
  //std::cout << "Consider the first eigenvalue, lambda = " << lambda << std::endl;
  //Eigen::VectorXcd v = es.eigenvectors().col(0);
  //std::cout << "If v is the corresponding eigenvector, then lambda * v = " << std::endl 
  //          << lambda * v << std::endl;
  //std::cout << "... and A * v = " << std::endl 
  //          << A.cast<std::complex<double> >() * v << std::endl << std::endl;

  //Eigen::MatrixXcd D = es.eigenvalues().asDiagonal();
  //Eigen::MatrixXcd V = es.eigenvectors();
  //std::cout << "Finally, V * D * V^(-1) = " << std::endl 
  //          << V * D * V.inverse() << std::endl;

  return 0;
}
