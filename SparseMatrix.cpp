
SparseMatrix() {
  
}

void append_node(int x, int y, int val){
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
    return right_multiply(*this);
}
SparseMatrix right_multiply(SparseMatrix matrix2) {
    // When multiplying m x n matrix and n x p matrix
    //If the columns of A do not match the rows of B
    if (!this->N == matrix2.M) {
        throw std::invalid_argument("Matrix multiplication can only occur between M x N and N x P matrices.");
    }
    // Make a new Sparse Matrix sized m * p (Rows of first by columns of second)
    SparseMatrix multMatrix(this->M, matrix2.N);

    //TO BE FIXED: Accessing nodes from the first matrix so that .val can be used for multiplication
    SparseNode leftNode = *this.head;

    //Node to add to new linked list representing the third matrix
    SparseNode multNode;
    SparseNode temp = *matrix2.head;
    
    // For every row in A compare every nonzero element (k) to it's corresponding elemeint in B.
    for (int i = 0; i < this->M; ++i){
        //If the node's y value is the same as the matrix's x value
        if (temp.y = this->M){
            // If B(k) is zero, throw out k. (k * 0)
            if (temp.val = 0){
                //CHECK: Make sure the throw is correct, might need to throw something specific.
                throw;
            }
            // Otherwise, multiply B(k) and k, and the new node value is the product at [m][p].
            else {
                multNode.x = this->M;
                multNode.y = temp.y;
                //PART OF THE FIX: The multiplication that occurs at the node values
                //CHECK: The values that are not zero need to be added together in the total new value, meaning it needs to be the sum, yes?
                multNode.val += temp.val * leftNode.val;
            }
        } 
    }
    //STILL NEED A WAY TO RETURN THE PRODUCT MATRIX
    //Thoughts / process started below
        //Set every index from the multiplication that was not zero to the value, otherwise all values are zero.
    for (int i = 0; i < this->M; ++i){
        for (int j = 0; j < matrix2.N; ++j){
            if (multNode.x == i && multNode.y == j){
                
            }
        }
    }
    return multMatrix;
}

SparseMatrix add(SparseMatrix matrix2) {

}