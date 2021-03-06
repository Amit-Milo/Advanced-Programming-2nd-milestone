//
// Created by amit on 23/01/2020.
//

#ifndef EX4__MATRIX_H_
#define EX4__MATRIX_H_

template <class T>
class Matrix {
  T **_mat;
  int _rows, _columns;


 public:
  Matrix(T **mat, int rows, int columns) {
    this->_mat = new T*[rows];

    for (int i = 0; i < rows; ++i) {
      this->_mat[i] = (T *)malloc(sizeof(T) * columns);
    }

    this->_rows = rows;
    this->_columns = columns;

    for (int i = 0; i  < this->_rows; ++i) {
      for (int j = 0; j < this->_columns; ++j) {
        this->_mat[i][j] = mat[i][j];
      }
    }
  }


  T* Get(int i, int j) const {
    if (i > this->_rows || i < 0 || j > this->_columns || j < 0)
      throw -1;

    return &(this->_mat[i][j]);
  }


  int GetRows() const {
    return this->_rows;
  }
  int GetColumns() const {
    return this->_columns;
  }

  std::size_t hash() {
    std::size_t result = 0;
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _columns; j++) {
        result += std::hash<T>{}(_mat[i][j]);
      }
    }
    result *= 10;
    result += std::hash<int>{}(_rows);
    result += std::hash<int>{}(_columns);
    return result;
  }
};

#endif //EX4__MATRIX_H_
