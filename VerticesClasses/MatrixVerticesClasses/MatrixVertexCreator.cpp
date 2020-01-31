//
// Created by amit on 23/01/2020.
//

#include "MatrixVertexCreator.h"


const MatrixVertex& MatrixVertexCreator::create(int i, int j, int rowLength)  {
  return *(this->_factory.create(i * rowLength + j));
}


const MatrixVertex& MatrixVertexCreator::create(const Point &p, int rowLength) {
  return this->create(p.GetI(), p.GetJ(), rowLength);
}