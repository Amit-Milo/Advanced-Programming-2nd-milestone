//
// Created by amit on 27/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__BFS_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__BFS_H_

#include <queue>

#include "GraphSearcher.h"
#include "Vertex.h"

class BFS : public GraphSearcher {
  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const;

  virtual GraphSearcher * clone() const {
    return new BFS;
  }
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__BFS_H_
