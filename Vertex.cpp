//
// Created by amit on 26/01/2020.
//

#include "Vertex.h"


bool operator==(const Vertex &first, const Vertex &second) {
  return first._index == second._index;
}


bool operator!=(const Vertex &first, const Vertex &second) {
  return !(first == second);
}