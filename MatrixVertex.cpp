//
// Created by amit on 22/01/2020.
//

#include "MatrixVertex.h"


const Cost& MatrixVertex::GetCost() {
  return this->_cost;
}


bool MatrixVertex::operator==(const MatrixVertex &first, const MatrixVertex &second) {
  return first._index == second._index;
}


bool MatrixVertex::operator!=(const MatrixVertex &first, const MatrixVertex &second) {
  return !(first == second);
}


void MatrixVertex::travel() {
  this->_traveled = true;
}


bool MatrixVertex::isTraveled() {
  return this->_traveled;
}