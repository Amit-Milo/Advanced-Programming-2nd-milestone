//
// Created by amit on 29/01/2020.
//

#include "DFS.h"
list<Vertex> *DFS::search(Searchable &graph) const {
  stack<Vertex> _structure;

  auto vertices = new list<Vertex>;

  _structure.push(*graph.GetStart());
  graph.Visit(*graph.GetStart());

  while (!_structure.empty()) {
    Vertex v = _structure.top();
    _structure.pop();

    auto neighbors = graph.GetNeighbors(v);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      if (!graph.IsVisited(*it)) {
        graph.Visit(*it);
        graph.UpdateVertex(*it, v);
        _structure.push(*it);
      }

      it++;
    }
  }

  const Vertex *temp = graph.GetEnd();
  const Vertex *start = graph.GetStart();

  while (*temp != *start) {
    vertices->push_front(*temp);
    temp = graph.GetParent(*temp);
  }

  vertices->push_front(*start);

  return vertices;
}
