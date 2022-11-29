//
// Created by Nathan Fernandes on 11/29/22.
//

#include "SparceMatrix.h"

SparseMatrix::SparseMatrix(int M_, int N_) {
    this->M = M_;
    this->N = N_;

}

void SparseMatrix::append_node(int x, int y, int val, SparseNode *n){
    SparseNode *temp = this->head;
    while(temp->next_ != nullptr) {
        temp = temp->next_;
    }
    temp->next_ = n;

}

void remove_node(int x, int y){
}

SparseMatrix operator+(const SparseMatrix& matrix2) {

}

SparseMatrix operator*(const SparseMatrix& matrix2) {

}

SparseMatrix operator*(const int scalar) {

}

SparseMatrix transpose() {

}
SparseMatrix left_multiply(SparseMatrix matrix2) {

}
SparseMatrix right_multiply(SparseMatrix matrix2) {

}

SparseMatrix add(SparseMatrix matrix2) {

}
