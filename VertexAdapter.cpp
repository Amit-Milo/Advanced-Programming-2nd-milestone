//
// Created by amit on 23/01/2020.
//

#include "VertexAdapter.h"


const Cost* VertexAdapter::GetCost() {
  return this->_cost;
}

/*
const Vertex *VertexAdapter::GetVertex() {
  return this->_vertex;
}
*/
const Vertex *VertexAdapter::GetVertex() const {
  return this->_vertex;
}

void VertexAdapter::travel() {
  this->_traveled = true;
}


bool VertexAdapter::isTraveled() {
  return this->_traveled;
}


const Vertex *VertexAdapter::GetParent()  const{
  return this->_parent;
}


void VertexAdapter::SetParent(VertexAdapter &parent) {
  this->_parent = parent.GetVertex();

  delete this->_pathLength;

  this->_pathLength = new Cost(this->GetCost()->GetValue() + parent.GetPathLength().GetValue());
}


Cost VertexAdapter::GetPathLength() {
  return *this->_pathLength;
}


bool operator==(const Vertex &first, const VertexAdapter &second) {
  return first == *(second._vertex);
}


bool operator==(const VertexAdapter &first, const Vertex &second) {
  return second == first;
}



