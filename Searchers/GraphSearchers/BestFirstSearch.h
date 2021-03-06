//
// Created by amit on 30/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_

#include <list>

#include "GraphSearcher.h"
#include "../../Searchables/Searchable.h"
#include "../../VerticesClasses/Vertex.h"

class BestFirstSearch : public GraphSearcher {
 public:
  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const;

  virtual GraphSearcher * clone() const {
    return new BestFirstSearch;
  }
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__BESTFIRSTSEARCH_H_
