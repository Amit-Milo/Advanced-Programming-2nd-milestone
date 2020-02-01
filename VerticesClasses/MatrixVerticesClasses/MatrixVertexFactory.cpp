//
// Created by amit on 23/01/2020.
//

#include <stdlib.h>

#include "MatrixVertexFactory.h"


const MatrixVertex * MatrixVertexFactory::create(int index)  {

  return new MatrixVertex(index);
}