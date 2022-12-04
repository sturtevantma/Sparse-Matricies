#include <iostream>
#include <string>
#include <SparseMatrix.h>

int main(int argc, int* argv[]) {
  // boolean variable for each flag
  bool multiply   = false;
  bool s_multiply = false;
  bool transpose  = false;
  bool add        = false;
  // Other variables
  std::string matrixA;
  std::string MatrixB;
  int scalar;
  // Loop through arguments (i={1, ..., length})
  if(argv[1] == "-M"){
    matrixA = argv[2];
    matrixB = argv[3];
    multiply = true;
  } else if (argv[1] == "-S") {
    matrixA = argv[2];
    scalar = std::stoi(argv[3]);
    s_multiply = true;
  } else if (argv[1] == "-T") {
    matrixA = argv[2];
    transpose = true;
  } else if (argv[1] == "-A") {
    matrixA = argv[2];
    matrixB = argv[3];
    add = true;
  } else {
    throw std::invalid_argument("Invalid Argument: Please see documentation on the github repo for instructions - https://github.com/sturtevantma/Sparse-Matricies");
  }

  // Execute Commands
  if(multiply) {
    SparseMatrix A(matrixA);
    SparseMatrix B(matrixB);
    SparseMatrix C = A * B;
    C.save();
  } else if(add) {
    SparseMatrix A(matrixA);
    SparseMatrix B(matrixB);
    SparseMatrix C = A + B;
    C.save();
  } else if(s_multiply) {
    SparseMatrix A(matrixA);
    SparseMatrix C = A * scalar;
    C.save();
  } else if(transpose) {
    SparseMatrix A(matrixA);
    SparseMatrix At = A.transpose();
    At.save();
  }
}