//
// Created by amit on 27/01/2020.
//

#include "BFS.h"

list<Vertex>* BFS::search(Searchable &graph) const {
  queue<Vertex> _structure;

  auto vertices = new list<Vertex>;

  _structure.push(*graph.GetStart());
  graph.Visit(*graph.GetStart());

  while (!_structure.empty()) {
    const Vertex &v = _structure.front();
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