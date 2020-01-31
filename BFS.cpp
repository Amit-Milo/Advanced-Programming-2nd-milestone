//
// Created by amit on 27/01/2020.
//

#include "BFS.h"

list<pair<Vertex, Cost>> * BFS::search(Searchable &graph) const {
  // A queue of the verices.
  queue<Vertex> _structure;

  // Insert start vertex to the queue.
  _structure.push(*graph.GetStart());

  // Visit start vertex.
  graph.Visit(*graph.GetStart());

  while (!_structure.empty()) {
    // Get a vertex.
    const Vertex &v = _structure.front();
    _structure.pop();

    // Get its neighbors
    auto neighbors = graph.GetNeighbors(v);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      // If the neighbor was not visited.
      if (!graph.IsVisited(*it)) {
        // Visit it.
        graph.Visit(*it);
        // Update parent and path length.
        graph.UpdateVertex(*it, v);
        if (graph.GetParent(*it) != nullptr)
          // If cost to this vertex is not infinity add it to the queue.
          _structure.push(*it);
      }

      it++;
    }
  }

  const Vertex *temp = graph.GetEnd();
  const Vertex *start = graph.GetStart();

  // Create a list of the path's vertices.
  auto vertices = new list<pair<Vertex, Cost>>;

  while (*temp != *start) {
    // Add the vertex to the list.
    vertices->push_front({*temp, graph.GetCost(*temp)});
    // Get its parent.
    temp = graph.GetParent(*temp);
  }

  // Add start vertex to the list.
  vertices->push_front({*start, graph.GetCost(*start)});

  return vertices;
}