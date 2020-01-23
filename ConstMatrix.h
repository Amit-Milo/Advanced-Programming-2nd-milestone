//
// Created by amit on 22/01/2020.
//

#ifndef EX4__CONSTMATRIX_H_
#define EX4__CONSTMATRIX_H_

<template class T>
class ConstMatrix<T> final {
  T **_mat;
  int _rows, _columns;


 public:
  ConstMatrix(T **mat, T rows, T columns);

  ~ConstMatrix();

  const T& Get(int i, int j) const;

  int GetRows() const;
  int GetColumns() const;
};


ConstMatrix::ConstMatrix(T **mat, int rows, int columns) {
  this->_mat = new T[rows][columns];
  this->_rows = rows;
  this->_columns = columns;

  for (int i = 0; i  < this->_rows; ++i) {
    for (int j = 0; j < this->_columns; ++j) {
      this->_mat[i][j] = mat[i][j];
    }
  }
}


ConstMatrix::~ConstMatrix() {
  delete this->_mat;
}


const T& ConstMatrix::Get(int i, int j) const {
  if (i > this->_rows || i < 0 || j > this->_columns || j < 0)
    throw -1; // TODO maybe replace with custom error.

  return this->_mat[i][j];
}


int ConstMatrix::GetRows() const {
  return this->_rows;
}


int ConstMatrix::GetColumns() const {
  return this->columns;
}

#endif //EX4__CONSTMATRIX_H_
