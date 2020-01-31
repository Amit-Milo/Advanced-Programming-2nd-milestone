//
// Created by amit on 24/01/2020.
//

#ifndef EX4__MATRIXGRAPHSEARCHER_H_
#define EX4__MATRIXGRAPHSEARCHER_H_

#include <list>

#include "GraphSearcher.h"
#include "../../Searchables/Searchable.h"
#include "../Searcher.h"
#include "../../VerticesClasses/Vertex.h"

class MatrixGraphSearcher : public GraphSearcher {
  const GraphSearcher *_searcher;

 public:
  MatrixGraphSearcher(const GraphSearcher *searcher) : _searcher(searcher) { }


  /**
   * Search for the shortest path from start to end in a graph.
   * @param graph the graph to search in.
   * @return a list of vertexes which make a shortest path in the graph.
   */
  virtual list<pair<Vertex, Cost>> * search(Searchable& graph) const {
    this->_searcher->search(graph);
  };


  virtual MatrixGraphSearcher* clone() const{
    return new MatrixGraphSearcher(_searcher->clone());
  }



};

#endif //EX4__MATRIXGRAPHSEARCHER_H_
