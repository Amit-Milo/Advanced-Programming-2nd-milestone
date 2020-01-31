//
// Created by amit on 23/01/2020.
//

#ifndef EX4__MATRIXVERTEXFACTORY_H_
#define EX4__MATRIXVERTEXFACTORY_H_

#include "MatrixVertex.h"
#include "../VertexFactory.h"

class MatrixVertexFactory : public VertexFactory{
 public:
  MatrixVertexFactory() : VertexFactory() {}
  virtual const MatrixVertex* create(int index);
};



#endif //EX4__MATRIXVERTEXFACTORY_H_
