#include "SparseMatrix.h"
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>

SparseMatrix::SparseMatrix(int M_, int N_) {
    this->M = M_;
    this->N = N_;
    this->head = nullptr;
}

SparseMatrix::SparseMatrix(SparseNode head, int M_, int N_){
    this->head = &head;
    this->M = M_;
    this->N = N_;
}

SparseMatrix::SparseMatrix(std::string fname){
    read_file(fname);
}

void SparseMatrix::read_file(std::string fname){
    std::ifstream inFile(fname);
    std::string line;

    inFile >> line;
    this->M = std::stoi(line);
    inFile >> line;
    this->N = std::stoi(line);
    this->head = nullptr;

    for(int y = 1; y <= this->M; y++) {
        for(int x = 1; x <= this->N; x++) {
                SparseNode *node = (SparseNode*)malloc(sizeof(SparseNode));
                node->x = x;
                node->y = y;
                inFile >> line;
                node->val = std::stoi(line);
                node->next_ = nullptr;
                if(node->val) {
                    this->append_node(node);
                }
        }
    }
}

void SparseMatrix::save_file(std::string fname){
    std::ofstream out(fname);
    out << this->M << ' ' << this->N << '\n';
    
    SparseNode *node = this->head;
    for(int y = 1; y <= this->M; y++) {
        for(int x = 1; x <= this->N; x++) {
            if(node->x == x && node->y == y) {
                out << node->val << ' ';
                if(node->next_ != nullptr) {
                    node = node->next_;
                }
            } else {
                out << "0 ";
            }
        }
        out << '\n';
    }
}

void SparseMatrix::append_node(SparseNode *n){
    if (this->head == nullptr) {
        this->head = n;
    }
    else {
        SparseNode *temp = this->head;
        while(temp->next_ != 0) {
            temp = temp->next_;
        }
        temp->next_ = n;
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

int SparseMatrix::index(int x, int y) {
    SparseNode *node = this->head;
    while(node->next_ != nullptr) {
        if(node->x == x && node->y == y) {
            return node->val;
        }
        node = node->next_;
    }
    if(node->x == x && node->y == y) {
        return node->val;
    }
    return 0;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix& matrix2) {
    return this->add(matrix2);
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix& matrix2) {
    return this->right_multiply(matrix2);
}

SparseMatrix SparseMatrix::operator*(const int scalar) {
    return this->scalar_multiply(scalar);
}

SparseMatrix SparseMatrix::transpose() {
    return *this;
}

SparseMatrix SparseMatrix::left_multiply(SparseMatrix matrix2) {
    return matrix2.right_multiply(*this);
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

    for(int y = 1; y <= this->M; y++) {
        for(int x = 1; x <= matrix2.N; x++) {
            int sum = 0;
            for(int i = 1; i <= this->N; i++) {
                sum += this->index(i,y) * matrix2.index(x,i);
            }
            if(sum) {
                SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
                out_node->x = x;
                out_node->y = y;
                out_node->val = sum;
                out_node->next_ = nullptr;
                multMatrix.append_node(out_node);
            }
        }
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

            SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
            out_node->x = e1.x;
            out_node->y = e1.y;
            out_node->val = val;
            out_node->next_ = nullptr;
            out_matrix.append_node(out_node);

            if(test) {
                e1 = *e1.next_;
                e2 = *e2.next_;
            }

            continue;
        }

        // Else add in the furthest back node
        if(e1.y == e2.y) {
            if(e1.x < e2.x) {
                SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
                out_node->x = e1.x;
                out_node->y = e1.y;
                out_node->val = e1.val;
                out_node->next_ = nullptr;
                out_matrix.append_node(out_node);

                if(test)
                    e1 = *e1.next_;
                continue;
            } else {
                SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
                out_node->x = e2.x;
                out_node->y = e2.y;
                out_node->val = e2.val;
                out_node->next_ = nullptr;
                out_matrix.append_node(out_node);

                if(test)
                    e2 = *e2.next_;

                continue;
            }
        } else {
          if(e1.y < e2.y) {
            SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
            out_node->x = e1.x;
            out_node->y = e1.y;
            out_node->val = e1.val;
            out_node->next_ = nullptr;
            out_matrix.append_node(out_node);

            if(test)
                e1 = *e1.next_;
            continue;
          } else {
            SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
            out_node->x = e2.x;
            out_node->y = e2.y;
            out_node->val = e2.val;
            out_node->next_ = nullptr;
            out_matrix.append_node(out_node);
            
            if(test)
                e2 = *e2.next_;

            continue;
          }
        }

    }

    if(e1.next_ == e2.next_) {
        return out_matrix;
    } 
    // Add remaining nodes to new matrix
    if(e1.next_ == nullptr) {
        while(e2.next_ != nullptr) {
          SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
          out_node->x = e2.x;
          out_node->y = e2.y;
          out_node->val = e2.val;
          out_node->next_ = nullptr;
          out_matrix.append_node(out_node);
          e2 = *e2.next_;
        }
          SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
          out_node->x = e2.x;
          out_node->y = e2.y;
          out_node->val = e2.val;
          out_node->next_ = nullptr;
          out_matrix.append_node(out_node);
    }

    if(e2.next_ == nullptr) {
        while(e1.next_ != nullptr) {
            SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
            out_node->x = e1.x;
            out_node->y = e1.y;
            out_node->val = e1.val;
            out_node->next_ = nullptr;
            out_matrix.append_node(out_node);
            e1 = *e1.next_;
        }
            SparseNode *out_node = (SparseNode*)malloc(sizeof(SparseNode));
            out_node->x = e1.x;
            out_node->y = e1.y;
            out_node->val = e1.val;
            out_node->next_ = nullptr;
            out_matrix.append_node(out_node);
    }

    return out_matrix;
}

SparseMatrix SparseMatrix::scalar_multiply(int scalar) {
    SparseMatrix *multiplied = new SparseMatrix(this->N, this->M);
    SparseNode *element = this->head;

    while(element->next_ != nullptr) {
        SparseNode *tNode = (SparseNode*)malloc(sizeof(SparseNode));
        tNode->x = element->x;
        tNode->y = element->y;
        tNode->val = element->val * scalar;
        tNode->next_ = nullptr;
        multiplied->append_node(tNode); 
        element= element->next_;
    }
    SparseNode *tNode= (SparseNode*)malloc(sizeof(SparseNode));
    tNode->x = element->x;
    tNode->y = element->y;
    tNode->val = element->val * scalar;
    tNode->next_ = nullptr;
    multiplied->append_node(tNode);

    return *multiplied;
}
