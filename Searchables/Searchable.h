//
// Created by amit on 22/01/2020.
//

#ifndef EX4__SEARCHABLE_H_
#define EX4__SEARCHABLE_H_

#include <list>

#include "../Cost.h"
#include "../VerticesClasses/Vertex.h"

using namespace std;

class Searchable {
 public:
  /**
   * Get the neighbors of a given vertex.
   * @param v the vertex to look for the neighbors of.
   * @return a list of the neighbors vertexes of the given vertex.
   */
  virtual list<Vertex>* GetNeighbors(const Vertex &v) = 0;


  /**
   * Get the start position in the searchable object.
   * @return the start vertex in the searchable object.
   */
  virtual const Vertex* GetStart() const = 0;


  /**
   * Get the end position in the searchable object.
   * @return the end vertex in the searchable object.
   */
  virtual const Vertex* GetEnd() const = 0;


  /**
   * Visit a vertex.
   * @param v the vertex to visit.
   */
  virtual void Visit(const Vertex &v) const = 0;


  /**
   * Check if a vertex is visited.
   * @param v the vertex to check.
   * @return true if the vertex was already visited, false otherwise.
   */
  virtual bool IsVisited(const Vertex &v) const = 0;


  /**
   * Update a vertex (parent, path length)
   * @param v the vertex to update.
   * @param p the potential parent to set.
   */
  virtual void UpdateVertex(const Vertex &v, const Vertex &p) const = 0;


  /**
   * Get the parent of a vertex.
   * @param v the vertex.
   * @return the parent.
   */
  virtual const Vertex* GetParent(const Vertex &v) const = 0;


  virtual Cost distance(const Vertex &src, const Vertex &dst) const = 0;


  virtual Cost currentPathLength(const Vertex &v) const = 0;

  virtual Cost GetCost(const Vertex &v) const = 0;
};

#endif //EX4__SEARCHABLE_H_
