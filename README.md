# Representing Sparse-Matricies Using Linked Lists

Group members:
Nathan Fernandes,
Matthew Sturtevant,
Michael Newton,
Dean Geraci

# Summary and Repo Address

Implementing a linked list into a program which creates nodes from data in a sparse matrix. Each node contains the coordinates, value,
and a pointer to the next value in the list. With this linked list, we are able to implement matrix addition, multiplication,
scalar multiplication, and transposing a matrix with more memory efficiency than if arrays were used.

Repo Address: https://github.com/sturtevantma/Sparse-Matricies

# Documentation

### SparseNode
Is a struct that contains the x & y coordinates of a node, the value at the x & y coordinates, and also a pointer that points to the next node.

`SparseNode::x`  
The horizontal posistion of the node ( 0 is left column )

`SparseNode::y`  
The vertical posistion of the node ( 0 is top row )

`SparseNode::value`  
The value at (x,y)

`SparseNode::next_`  
A pointer to the next node

### SparseMatrix
A linked list of SparseNodes with functions for basic matrix operations.

`SparseNode::head`  
A pointer to the head node

`SparseMatrix::SparseMatrix()`  
Constructor for SparseMatrix

`SparseMatrix::append_node()`  
Adds a node into the appropriate position

`SparseMatrix::remove_node()`  
Removes a node based on coords (x,y)

`SparseMatrix::operator+()`  
Defines behavior for the addition operator

`SparseMatrix::operator*()`  
Defines behavior for the multiplication operator on 2 SparseMatricies

`SparseMatrix::operator*()`  
Defines behavior of scalar multiplication

`SparseMatrix::transpose()`  
Transposes the matrix such that for every element e_xy, e_xy = e_yx (swaps the rows and columns)

`SparseMatrix::left_multiply()`  
Function for left multiplication (*note this function just returns right_multiply of matrix2 with this)

`SparseMatrix::right_multiply()`  
Function for right multiplication

`SparseMatrix::add()`  
Function for addition
