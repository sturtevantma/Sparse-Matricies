#include <stdexcept>
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int M_, int N_) {
   this->M = M_;
   this->N = N_;
}

void SparseMatrix::append_node(SparseNode node2){

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
    // If the matricies are not the same size they cannot be added
    if(! (this->M == matrix2.M && this->N == matrix2.N) ) {
        throw std::invalid_argument("Matricies must be the same size to perform Matrix Addition");
    }
  
    // Output matrix
    SparseMatrix out_matrix(this->M, this->N);

    // Temporary nodes used for finding our values

    SparseNode e1 = *(this->head);
    SparseNode e2 = *(matrix2.head);

    // Loop through values in both matricies increment further back node, if either node reaches the end break;
    bool test = true;
    while(test) {
        if(e2.next_ == nullptr || e1.next_ == nullptr) {
           test = false;
        }

        // Add sum of both nodes into the output if they have same coordinates
        if(e1.x == e2.x && e1.y == e2.y) {

            int val = e1.val + e2.val;

            SparseNode out_node;
            out_node.x = e1.x;
            out_node.y = e1.y;
            out_node.val = val;
            out_matrix.append_node(out_node);

            e1 = *e1.next_;
            e2 = *e2.next_;

            continue;
        }

        // Else add in the furthest back node
        if(e1.y == e2.y) {
            if(e1.x < e2.x) {
                SparseNode out_node = e1;

                out_node.next_ = nullptr;
                out_matrix.append_node(out_node);
                e1 = *e1.next_;
                continue;
            } else {
                SparseNode out_node = e2;
                out_node.next_ = nullptr;
                out_matrix.append_node(out_node);
                e2 = *e2.next_;

                continue;
            }
        } else {
          if(e1.y < e2.y) {
            SparseNode out_node = e1;

            out_node.next_ = nullptr;
            out_matrix.append_node(out_node);
            e1 = *e1.next_;
            continue;
          } else {
            SparseNode out_node = e2;
            out_node.next_ = nullptr;
            out_matrix.append_node(out_node);
            e2 = *e2.next_;

            continue;
          }
        }

    }

    // Add remaining nodes to new matrix
    if(e1.next_ == nullptr) {
        while(e2.next_ != nullptr) {
          SparseNode out_node = e2;

          out_node.next_ = nullptr;
          out_matrix.append_node(out_node);
          e2 = *e2.next_;
        }
        SparseNode out_node = e2;
        out_node.next_ = nullptr;

        out_matrix.append_node(out_node);
    }

    if(e2.next_ == nullptr) {
        while(e1.next_ != nullptr) {
            SparseNode out_node = e1;

            out_node.next_ = nullptr;
            out_matrix.append_node(out_node);
            e1 = *e1.next_;
        }
        SparseNode out_node = e1;
        out_node.next_ = nullptr;

        out_matrix.append_node(out_node);
    }

    return out_matrix;
}
