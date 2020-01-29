//
// Created by amit on 23/01/2020.
//

#ifndef EX4__VERTEXADAPTER_H_
#define EX4__VERTEXADAPTER_H_

#include "Cost.h"
#include "Vertex.h"

class VertexAdapter {
  const Vertex *_vertex;
  const Vertex *_parent;

  const Cost *_cost;
  bool _traveled;

  Cost *_pathLength;

 public:
  VertexAdapter(const Vertex &vertex, const Cost &cost) :_vertex(&vertex), _cost(new Cost(cost.GetValue())), _traveled(false),
  _parent(nullptr), _pathLength(new Cost(INFINITY)) {  }


  /*~VertexAdapter() {
    delete this->_pathLength;
  }*/


  /**
   * Get the cost to step in this vertex.
   * @return the cost of the vertex.
   */
   //todo
   const Cost* GetCost();


  /**
   * Get the vertex of the adapter.
   * @return the vertex member.
   */
   //todo
   const Vertex* GetVertex();

  /**
   * Travel the vertex.
   */
   //TODO
   void travel();

  /**
   * Check if the vertex has already been traveled.
   * @return true if the vertex has been traveled, false otherwise.
   */
   //TODO
   bool isTraveled();

  /**
   * Get the parent of the vertex.
   * @return the parent of the vertex.
   */
   //todo
   const Vertex* GetParent();

  /**
   * Set the parent of the vertex.
   * @param parent a pointer to the adapter of the parent to set.
   */
   //todo
   void SetParent(VertexAdapter &parent);

  /**
   * Get the length of the path from start to this vertex.
   * @return the length to this vertex.
   */
   //todo
   Cost GetPathLength();


   void SetPathLength();

  bool friend operator==(const Vertex &first, const VertexAdapter &second);

  bool friend operator==(const VertexAdapter &first, const Vertex &second);
};

#endif //EX4__VERTEXADAPTER_H_
