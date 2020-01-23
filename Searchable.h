//
// Created by amit on 22/01/2020.
//

#ifndef EX4__SEARCHABLE_H_
#define EX4__SEARCHABLE_H_

#include <list>

#include "Vertex.h"

class Searchable {
 public:
  /**
   * Get the neighbors of a given vertex.
   * @param v the vertex to look for the neighbors of.
   * @return a list of the neighbors vertexes of the given vertex.
   */
  virtual list<Vertex>* GetNeighbors(const Vertex &v) const = 0;


  /**
   * Get the start position in the searchable object.
   * @return the start vertex in the searchable object.
   */
  virtual const Vertex& GetStart() const = 0;


  /**
   * Get the end position in the searchable object.
   * @return the end vertex in the searchable object.
   */
  virtual const Vertex& GetEnd() const = 0;
};

#endif //EX4__SEARCHABLE_H_
