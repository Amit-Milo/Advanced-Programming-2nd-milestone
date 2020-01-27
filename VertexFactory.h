//
// Created by amit on 23/01/2020.
//

#ifndef EX4__VERTEXFACTORY_H_
#define EX4__VERTEXFACTORY_H_

#include <list>

#include "Vertex.h"

using namespace std;

class VertexFactory {
 protected:
  list<Vertex>* instances;

  int getIndex(const Vertex &v) {return v._index;}

 public:
  VertexFactory() : instances(new list<Vertex>) {}
  virtual const Vertex& create(int index) = 0;
};

#endif //EX4__VERTEXFACTORY_H_
