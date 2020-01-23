//
// Created by amit on 23/01/2020.
//

#include "VertexAdapter.h"


const Cost& VertexAdapter::GetCost() {
  return this->_cost;
}


void VertexAdapter::travel() {
  this->_traveled = true;
}


bool VertexAdapter::isTraveled() {
  return this->_traveled;
}