//
// Created by amit on 23/01/2020.
//

#ifndef EX4__MATRIXGRAPH_H_
#define EX4__MATRIXGRAPH_H_

#include <list>
#include <string>

#include "Matrix.h"
#include "Cost.h"
#include "MatrixVertex.h"
#include "MatrixVertexCreator.h"
#include "Point.h"
#include "Searchable.h"
#include "Vertex.h"
#include "VertexAdapter.h"

class MatrixGraph : public Searchable {
  Matrix<VertexAdapter> _mat;

  MatrixVertex _start, _end;

  MatrixVertexCreator _creator;

 public:
  /**
   * A constructor.
   * @param mat the matrix representing the graph.
   * @param start the
   * @param end
   */
  MatrixGraph(const Matrix<int> &mat, const Point &start, const Point &end);


  /**
   * Get the neighbors of a given vertex.
   * @param v the vertex to look for the neighbors of.
   * @return a list of the neighbors vertexes of the given vertex.
   */
  virtual list<Vertex>* GetNeighbors(const Vertex &v);


  /**
   * Get the start position in the graph.
   * @return the start vertex in the graph.
   */
  virtual const MatrixVertex* GetStart() const;


  /**
   * Get the end position in the graph.
   * @return the end vertex in the graph.
   */
  virtual const MatrixVertex* GetEnd() const;


  /**
   * Visit a vertex.
   * @param v the vertex to visit.
   */
  virtual void Visit(const Vertex &v) const;


  /**
   * Check if a vertex is visited.
   * @param v the vertex to check.
   * @return true if the vertex was already visited, false otherwise.
   */
  virtual bool IsVisited(const Vertex &v) const;


  /**
   * Update a vertex (parent, path length)
   * @param v the vertex to update.
   * @param p the potential parent to set.
   */
  virtual void UpdateVertex(const Vertex &v, const Vertex &p) const;


  /**
   * Get the parent of a vertex.
   * @param v the vertex.
   * @return the parent.
   */
  virtual const Vertex* GetParent(const Vertex &v) const;

  size_t hash();
};

#endif //EX4__MATRIXGRAPH_H_
