#include <iostream>
#include <string>
#include "SparseMatrix.h"

int main(int argc, char* argv[]) {
  // boolean variable for each flag
  bool multiply   = false;
  bool s_multiply = false;
  bool transpose  = false;
  bool add        = false;
  // Other variables
  std::string matrixA;
  std::string matrixB;
  int scalar;
  std::string s = argv[1];
  // Loop through arguments (i={1, ..., length})
  if(s == "-M"){
    matrixA = argv[2];
    matrixB = argv[3];
    multiply = true;
  } else if (s == "-S") {
    matrixA = argv[2];
    scalar = std::stoi(argv[3]);
    s_multiply = true;
  } else if (s == "-T") {
    matrixA = argv[2];
    transpose = true;
  } else if (s == "-A") {
    matrixA = argv[2];
    matrixB = argv[3];
    add = true;
  } else {
    throw std::invalid_argument("Invalid Argument: Please see documentation on the github repo for instructions - https://github.com/sturtevantma/Sparse-Matricies");
  }

  std::string fname_out = argv[argc-1];

  // Execute Commands
  if(multiply) {
    SparseMatrix A(matrixA);
    SparseMatrix B(matrixB);
    SparseMatrix C = A.right_multiply(B);
    C.save_file(fname_out);

  } else if(add) {
    SparseMatrix A(matrixA);
    SparseMatrix B(matrixB);
    SparseMatrix C = A.add(B);
    C.save_file(fname_out);

  } else if(s_multiply) {
    SparseMatrix A(matrixA);
    SparseMatrix C = A * scalar;
    C.save_file(fname_out);

  } else if(transpose) {
    SparseMatrix A(matrixA);
    SparseMatrix At = A.transpose();
    At.save_file(fname_out);
  }
  std::cout << '\n';
}