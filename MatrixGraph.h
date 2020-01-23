//
// Created by amit on 23/01/2020.
//

#ifndef EX4__MATRIXGRAPH_H_
#define EX4__MATRIXGRAPH_H_

#include "ConstMatrix.h"
#include "MatrixVertex.h"
#include "MatrixVertexCreator.h"
#include "Point.h"
#include "Searchable.h"
#include "Vertex.h"
#include "VertexAdapter.h"

class MatrixGraph : public Searchable {
  ConstMatrix<VertexAdapter> _mat;

  MatrixVertex _start, _end;

  MatrixVertexCreator _creator

 public:
  /**
   * A constructor.
   * @param mat the matrix representing the graph.
   * @param start the
   * @param end
   */
   // TODO implement
  MatrixGraph(const ConstMatrix<int> &mat, const Point &start, const Point &end);


  /**
   * Get the neighbors of a given vertex.
   * @param v the vertex to look for the neighbors of.
   * @return a list of the neighbors vertexes of the given vertex.
   */
  virtual list<MatrixVertex>* GetNeighbors(const Vertex &v) const;


  /**
   * Get the start position in the graph.
   * @return the start vertex in the graph.
   */
  virtual const MatrixVertex& GetStart() const;


  /**
   * Get the end position in the graph.
   * @return the end vertex in the graph.
   */
  virtual const MatrixVertex& GetEnd() const;
};


#endif //EX4__MATRIXGRAPH_H_
