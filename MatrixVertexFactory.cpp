//
// Created by amit on 23/01/2020.
//

#include <stdlib.h>

#include "MatrixVertexFactory.h"


const MatrixVertex * MatrixVertexFactory::create(int index)  {
  /*for (int i = 0; i < this->_amount; ++i) {
    if (this->getIndex(*this->_instances[i]) == index)
      return (MatrixVertex*) this->_instances[i];
  }
  this->_instances = (Vertex **) realloc(this->_instances, sizeof(MatrixVertex *) * (++this->_amount));

  this->_instances[this->_amount - 1] = new MatrixVertex(index);

  return (MatrixVertex*) this->_instances[this->_amount - 1];*/ //todo

  return new MatrixVertex(index);
}