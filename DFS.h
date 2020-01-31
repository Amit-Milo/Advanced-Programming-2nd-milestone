//
// Created by amit on 29/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__DFS_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__DFS_H_

#include <stack>

#include "GraphSearcher.h"
#include "Vertex.h"

class DFS : public GraphSearcher{
/**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const;

  virtual GraphSearcher * clone() const {
    return new DFS;
  }
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__DFS_H_
