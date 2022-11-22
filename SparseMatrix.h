#include "SparseNode.h"
#include <list>
class SparseMatrix {
  private:
    std::list<SparseNode> matrix; // The linked list of SparseNodes, see https://github.com/sturtevantma/Sparse-Matricies for info
    int M; // The number of rows
    int N; // The number of columns

  public:
    SparseMatrix(); // Constructor for SparseMatrix
    void append_node(int x, int y, int val); // Adds a node into the appropriate position
    void remove_node(int x, int y); // Removes a node based on coords (x,y)

    SparseMatrix operator+(const SparseMatrix& matrix2); // Defines behavior for the addition operator
    SparseMatrix operator*(const SparseMatrix& matrix2); // Defines behavior for the multiplication operator on 2 SparseMatricies
    SparseMatrix operator*(const int scalar); // Defines behavior of scalar multiplication

    SparseMatrix transpose(); // Transposes the matrix such that for every element e_xy, e_xy = e_yx (swaps the rows and columns)
    SparseMatrix left_multiply(SparseMatrix matrix2); // Function for left multiplication (*note this function just returns right_multiply of matrix2 with this)
    SparseMatrix right_multiply(SparseMatrix matrix2); // Function for right multiplication
    SparseMatrix add(SparseMatrix matrix2); // Function for addition
}