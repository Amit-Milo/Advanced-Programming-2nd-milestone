//
// Created by amit on 23/01/2020.
//

#include "MatrixVertexFactory.h"


const MatrixVertex & MatrixVertexFactory::create(int index) {
  std::list<MatrixVertex>::iterator<MatrixVertex> it;

  auto end = this->instances.end();

  for (it = this->instances.begin(); it != end && (*it)._index != index; ++it);

  if (it != end) return *it;

  // TODO local object will die?
  this->instances.push_back(MatrixVertex(index));

  --it;
  return *it;
}