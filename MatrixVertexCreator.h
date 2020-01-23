//
// Created by amit on 23/01/2020.
//

#ifndef EX4__MATRIXVERTEXCREATOR_H_
#define EX4__MATRIXVERTEXCREATOR_H_

#include "MatrixVertex.h"
#include "MatrixVertexFactory.h"
#include "Point.h"

class MatrixVertexCreator {
  MatrixVertexFactory _factory;

 public:
  /**
   * A constructor.
   */
  MatrixVertexCreator() : _factory(MatrixVertexFactory()) { }


  /**
   * Create a Matrix vertex.
   * @param i row of the vertex.
   * @param j column of the vertex.
   * @param rowLength the length of a row.
   * @return the matrix vertex created by the given arguments.
   */
  const MatrixVertex & create(int i, int j, int rowLength);


  /**
   * Create a Matrix vertex.
   * @param p the point of the vertex.
   * @param rowLength the length of a row.
   * @return the matrix vertex created by the given arguments.
   */
  const MatrixVertex & create(const Point &p, int rowLength);
};

#endif //EX4__MATRIXVERTEXCREATOR_H_
