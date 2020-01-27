//
// Created by amit on 23/01/2020.
//

#include "MatrixVertexFactory.h"

using namespace std;


const MatrixVertex & MatrixVertexFactory::create(int index)  {
  auto it = this->instances->begin();
  auto end = this->instances->end();
  size_t size = this->instances->size();

  if (size > 0) {
    for (; it != end && this->getIndex(*it) != index; ++it);

    if (it != end) return static_cast<const MatrixVertex &>(*it);
  }

  this->instances->push_front(MatrixVertex(index));

  --it;
  return static_cast<const MatrixVertex &>(*it);
}