//
// Created by amit on 23/01/2020.
//

#ifndef EX4__VERTEXFACTORY_H_
#define EX4__VERTEXFACTORY_H_

#include <stdlib.h>

#include "Vertex.h"

class VertexFactory {
 protected:
  VertexFactory() = default;

 public:
  virtual const Vertex* create(int index) = 0;
};

#endif //EX4__VERTEXFACTORY_H_
