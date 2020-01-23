//
// Created by amit on 23/01/2020.
//

#ifndef EX4__VERTEXADAPTER_H_
#define EX4__VERTEXADAPTER_H_

#include "Cost.h"
#include "Vertex.h"

class VertexAdapter {
  Vertex &_vertex;
  Cost &_cost;
  bool _traveled;

 public:
  VertexAdapter(const Vertex &vertex, const Cost &cost) : _vertex(vertex), _cost(cost), _traveled(false) {}


  /**
   * Get the cost to step in this vertex.
   * @return the cost of the vertex.
   */
  virtual const Cost& GetCost();

  /**
   * Travel the vertex.
   */
  virtual void travel();

  /**
   * Check if the vertex has already been traveled.
   * @return true if the vertex has been traveled, false otherwise.
   */
  virtual bool isTraveled();
};

#endif //EX4__VERTEXADAPTER_H_
