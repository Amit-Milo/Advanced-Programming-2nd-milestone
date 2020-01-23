//
// Created by amit on 22/01/2020.
//

#include <algorithm>

#include "MatrixGraph.h"


MatrixVertex& MatrixGraph::GetStart() const {
  return this->_start;
}


MatrixVertex& MatrixGraph::GetEnd() const {
  return this->_end;
}


list<MatrixVertex>* MatrixGraph::GetNeighbors(const Vertex &v) const {
  list<MatrixVertex> neighbors = new list<MatrixVertex>;

  int i = v.GetI();
  int j = v.GetJ();

  // Add cell left to current.
  if (i > 0) neighbors.pushfront(this->_creator.create(i - 1, j, this->_mat.GetRows()));

  // Add cell right to current.
  if (i < this->_mat.GetRows() - 1) neighbors.pushfront(this->_creator.create(i + 1, j, this->_mat.GetRows()));

  // Add cell above current.
  if (j > 0) neighbors.pushfront(this->_creator.create(i, j - 1, this->_mat.GetRows()));

  // Add cell below current.
  if (j < this->_mat.GetRows() - 1) neighbors.pushfront(this->_creator.create(i, j + 1, this->_mat.GetRows()));

  return neighbors;
}