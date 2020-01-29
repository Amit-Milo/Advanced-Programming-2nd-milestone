//
// Created by amit on 23/01/2020.
//

#ifndef EX4__VERTEXFACTORY_H_
#define EX4__VERTEXFACTORY_H_

#include <stdlib.h>

#include "Vertex.h"

class VertexFactory {
 protected:
  Vertex** _instances;
  int _amount;

  int getIndex(const Vertex &v) {return v._index;}

  VertexFactory() {
    this->_instances = (Vertex**) malloc(0);
    this->_amount = 0;
  }

 public:
  virtual const Vertex* create(int index) = 0;
};

#endif //EX4__VERTEXFACTORY_H_
