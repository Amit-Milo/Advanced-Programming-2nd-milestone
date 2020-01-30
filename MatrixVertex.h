//
// Created by amit on 22/01/2020.
//

#ifndef EX4__MATRIXVERTEX_H_
#define EX4__MATRIXVERTEX_H_

#include "Cost.h"
#include "Vertex.h"


class MatrixVertex : public Vertex{
  friend class MatrixVertexFactory;

  /**
  *  A private constructor.
  * @param index the index of the matrix vertex.
  */
  MatrixVertex(int index) : Vertex(index){ }

};

#endif //EX4__MATRIXVERTEX_H_
