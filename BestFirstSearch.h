//
// Created by amit on 30/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_

#include <list>

#include "GraphSearcher.h"
#include "Searchable.h"
#include "Vertex.h"

class BestFirstSearch : public GraphSearcher {
 public:
  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<Vertex>* search(Searchable& graph) const;
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_
