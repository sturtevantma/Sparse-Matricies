//
// Created by Nathan Fernandes on 11/29/22.
//

#include "SparceMatrix.h"

SparseMatrix::SparseMatrix(int M_, int N_) {
    this->M = M_;
    this->N = N_;


}

void SparseMatrix::append_node(SparseNode *n, int X, int Y){
    SparseNode *temp = this->head;
    while(temp->next_ != nullptr) {
        temp = temp->next_;
    }
    n = new SparseNode();
    n->x = X;
    n->y = Y;
    n->val = temp->val;
    temp->next_ = n;

}

void SparseMatrix::remove_node(int x, int y){
    SparseNode *temp;

    if(head->x == x && head->y == y) {
        temp = head;
        head = head->next_;
        free(temp);
    }
    else {
        SparseNode *newTemp;
        while(newTemp->next_ != nullptr) {
            if (newTemp->next_->x == x && newTemp->next_->y == y) {
                temp = newTemp->next_;
                newTemp->next_ = newTemp->next_->next_;
                free(temp);
                break;
            }
            else {
                newTemp = newTemp->next_;
            }
        }
    }


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
