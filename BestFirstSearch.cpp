//
// Created by amit on 30/01/2020.
//

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "BestFirstSearch.h"
list<pair<Vertex, Cost>> * BestFirstSearch::search(Searchable &graph) const {
  // Heap of the untraveled vertices.
  vector<Vertex> heap;
  // A function to reorder the heap.
  unordered_map<int, Cost> f_function;


  // Make a heap.
  make_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
    return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
  });

  // Get start and end vertices.
  auto start = *graph.GetStart();
  auto end = *graph.GetEnd();

  // Insert start to the heap and set it's f_function value.
  f_function.insert({start.GetIndex(), graph.currentPathLength(start)});
  heap.push_back(start);
  push_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
    return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
  });

  // Visit start.
  graph.Visit(start);

  while (heap.size() > 0) {
    // Get minimum distance vertex.
    auto head = heap.front();

    // Pop it.
    pop_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
      return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
    });
    heap.pop_back();

    // If it's the end, we are done.
    if (head == end) {
      break;
    }

    // Get the neighbors of the vertex.
    auto neighbors = graph.GetNeighbors(head);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      // Update distance and parent of the neighbor, if fits.
      graph.UpdateVertex(*it, head);

      // Update f_function.
      auto val = f_function.find(it->GetIndex());
      if (val != f_function.end())
        val->second = graph.currentPathLength(*it);
      else
        f_function.insert({it->GetIndex(), graph.currentPathLength(*it)});

      // If vertex was not already visited.
      if (!graph.IsVisited(*it)) {
        // Visit it.
        graph.Visit(*it);

        // Insert to the heap.
        heap.push_back(*it);
        push_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
          return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
        });
      }

      ++it;
    }
  }


  auto vertices = new list<pair<Vertex, Cost>>;

  const Vertex *temp = graph.GetEnd();

  while (*temp != start) {
    vertices->push_front({*temp,graph.GetCost(*temp)});
    temp = graph.GetParent(*temp);
  }

  vertices->push_front({start, graph.GetCost(start)});

  return vertices;
}