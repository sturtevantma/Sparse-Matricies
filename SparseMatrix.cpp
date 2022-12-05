#include "SparseMatrix.h"

SparseMatrix::SparseMatrix() {
  
}

void SparseMatrix::append_node(int x, int y, int val){
}

void SparseMatrix::remove_node(int x, int y){
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix& matrix2) {

}

SparseMatrix SparseMatrix::operator*(const SparseMatrix& matrix2) {

}

SparseMatrix SparseMatrix::operator*(const int scalar) {

}

SparseMatrix SparseMatrix::transpose() {

}
SparseMatrix SparseMatrix::left_multiply(SparseMatrix matrix2) {
    return right_multiply(*this);
}

SparseMatrix SparseMatrix::right_multiply(SparseMatrix matrix2) {
    // When multiplying m x n matrix and n x p matrix
    // If the columns of A do not match the rows of B
    if (this->N != matrix2.M) {
        throw std::invalid_argument("Matrix multiplication can only occur between M x N and N x P matrices.");
    }

    // Make a new Sparse Matrix sized m * p (Rows of first by columns of second)
    SparseMatrix multMatrix(this->M, matrix2.N);

    // Node from the left matrix
    SparseNode leftNode = *this->head;

    // Node from the matrix passed into the function
    SparseNode rightNode = *matrix2.head;

    // Node to add to new linked list representing the third matrix
    SparseNode multNode;
    SparseNode temp;

    // For every row in A
    for(int j = 1; j <= this->M; j++){
        // Compare every nonzero element k
        while(leftNode.y = j){
            while(rightNode.next_ != nullptr){
                // if there is a value at this coordinate in both matrices, multiply. Otherwise, continue.
                if (rightNode.x == j){
                    temp.val += leftNode.val * rightNode.val;
                }
            }
        }
        multMatrix.append_node(*temp);
    }
    
    return multMatrix;
}

SparseMatrix SparseMatrix::add(SparseMatrix matrix2) {

}