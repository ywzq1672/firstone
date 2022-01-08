#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;
// [[Rcpp::export]]
arma::mat fun1(arma::mat A)
{
  int n=A.n_rows,m=A.n_cols;
  arma::mat B(n,m);
  int t=n-1;
  for(int i=0;i<n;i++,t--) {
    for(int j=0;j<m;j++) {
      B(j,t) = A(i,j);
    }
  }
  return B;
}
// [[Rcpp::export]]
arma::mat fun2(arma::mat A)
{
  int n=A.n_rows;

  int t;
  for(int i=0; i<n/2; i++ )
  {
    for(int j=i; j<n-i-1; j++ )
    {
      t = A(i,j);
      A(i,j) = A(n-1-j,i);
      A(n-1-j,i) = A(n-i-1,n-j-1);
      A(n-i-1,n-j-1) = A(j,n-1-i);
      A(j,n-1-i) = t;
    }
  }
  return A;
}

