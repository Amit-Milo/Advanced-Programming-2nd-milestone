//
// Created by amit on 29/01/2020.
//

#include "DFS.h"
list<pair<Vertex, Cost>> * DFS::search(Searchable &graph) const {
  // Stack of unvisited vertices.
  stack<Vertex> _structure;

  // Insert start vertex to the stack and visit it.
  _structure.push(*graph.GetStart());
  graph.Visit(*graph.GetStart());
  auto end = *graph.GetEnd();

  while (!_structure.empty()) {
    // Get a vertex.
    Vertex v = _structure.top();
    // If it's the end, we are done.
    if (v == end) {
      break;
    }
    _structure.pop();

    // Get its neighbors.
    auto neighbors = graph.GetNeighbors(v);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      // if we didn't already visited the vertex.
      if (!graph.IsVisited(*it)) {
        // Visit it.
        graph.Visit(*it);
        // Update parent and path length.
        graph.UpdateVertex(*it, v);

        if (graph.GetParent(*it) != nullptr)
          // If the cost to this vertex isn't infinity, push it to the stack.
          _structure.push(*it);;
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
