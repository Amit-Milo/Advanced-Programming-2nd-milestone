//
// Created by amit on 24/01/2020.
//

#ifndef EX4_GRAPHSEARCHER_H_
#define EX4_GRAPHSEARCHER_H_

#include <list>

#include "Cost.h"
#include "Searchable.h"
#include "Searcher.h"
#include "Vertex.h"

using namespace std;

class GraphSearcher : public Searcher<list<pair<Vertex, Cost>>*> {
 public:
  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const = 0;
};

#endif //EX4_GRAPHSEARCHER_H_
