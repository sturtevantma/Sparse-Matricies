#include <string>

struct SparseNode {
  int x = 0; // The horizontal posistion of the node ( 0 is left column )
  int y = 0; // The vertical posistion of the node ( 0 is top row )
  int val = 0; // The value at (x,y)
  SparseNode* next_ = nullptr; // A pointer to the next node
};

class SparseMatrix {
private:
    int M = 0; // The number of rows
    int N = 0; // The number of columns

public:
    SparseNode* head = nullptr; // A pointer to the head node

    SparseMatrix(int M, int N); // Constructor for SparseMatrix
    SparseMatrix(SparseNode head, int M, int N);
    SparseMatrix(std::string fname);

    void append_node(SparseNode *n); // Adds a node into the appropriate position
    void remove_node(int x, int y); // Removes a node based on coords (x,y)

    SparseMatrix operator+(const SparseMatrix& matrix2); // Defines behavior for the addition operator
    SparseMatrix operator*(const SparseMatrix& matrix2); // Defines behavior for the multiplication operator on 2 SparseMatricies
    SparseMatrix operator*(const int scalar); // Defines behavior of scalar multiplication

    SparseMatrix transpose(); // Transposes the matrix such that for every element e_xy, e_xy = e_yx (swaps the rows and columns)
    SparseMatrix left_multiply(SparseMatrix matrix2); // Function for left multiplication (*note this function just returns right_multiply of matrix2 with this)
    SparseMatrix right_multiply(SparseMatrix matrix2); // Function for right multiplication
    SparseMatrix scalar_multiply(int scalar);
    SparseMatrix add(SparseMatrix matrix2); // Function for addition

    void read_file(std::string fname);
    void save_file(std::string fname);
};
