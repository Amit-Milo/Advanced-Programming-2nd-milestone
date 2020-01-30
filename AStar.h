//
// Created by amit on 29/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__ASTAR_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__ASTAR_H_

#include <list>

#include "Cost.h"
#include "GraphSearcher.h"
#include "Vertex.h"

class AStar : public GraphSearcher{
 public:
  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const;
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__ASTAR_H_
