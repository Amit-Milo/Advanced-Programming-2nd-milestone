//
// Created by amit on 22/01/2020.
//

#ifndef EX4__MATRIXVERTEX_H_
#define EX4__MATRIXVERTEX_H_

#include "Cost.h"
#include "Vertex.h"

class MatrixVertex : public Vertex{
  friend NextStep;

  /**
   * A private constructor.
   * @param index the index of the matrix vertex.
   */
  MatrixVertex(int index) : _index(index){ }


 public:
  /**
   * Define comparison between two matrix vertexes. Comparison is declared by comparison of the indexes.
   * @param first the first vertex.
   * @param second the second vertex.
   * @return true if the indexes of the vertexes are equal, false otherwise.
   */
  friend bool operator==(const MatrixVertex &first, const MatrixVertex &second);

  /**
   * Define inequality between two matrix vertexes.
   * @param first the first vertex.
   * @param second the second vertex.
   * @return true if the vertexes are unequal, false otherwise.
   */
  friend bool operator!=(const MatrixVertex &first, const MatrixVertex &second);
};

#endif //EX4__MATRIXVERTEX_H_
