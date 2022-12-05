//
// Created by Nathan Fernandes on 11/29/22.
//

#include "SparceMatrix.h"

SparseMatrix::SparseMatrix(int M_, int N_) {
    this->M = M_;
    this->N = N_;


}

void SparseMatrix::append_node(SparseNode *n){
    SparseNode *temp = this->head;
    SparseNode *newTemp;
    if (temp == nullptr) {
        temp = new SparseNode();
        temp->x = n->x;
        temp->y = n->y;
        temp->val = n->val;
        temp->next_ = nullptr;
        head = temp;
    }
    else {
        while(temp->next_ != nullptr) {
            temp = temp->next_;
        }
        newTemp = new SparseNode();
        newTemp->x = n->x;
        newTemp->y = n->y;
        newTemp->val = n->val;
        newTemp->next_ = nullptr;
        temp->next_ = newTemp;
    }

}

void SparseMatrix::remove_node(int x, int y){
    SparseNode *temp;
    SparseNode *newTemp;

    if(head->x == x && head->y == y) {
        temp = head;
        head = head->next_;
        free(temp);
    }
    else {
        newTemp = head;
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
