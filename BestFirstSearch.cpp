//
// Created by amit on 30/01/2020.
//

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "BestFirstSearch.h"
list<pair<Vertex, Cost>> * BestFirstSearch::search(Searchable &graph) const {
  vector<Vertex> heap;
  unordered_map<int, Cost> f_function;


  make_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
    return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
  });

  auto start = *graph.GetStart();
  auto end = *graph.GetEnd();

  f_function.insert({start.GetIndex(), graph.currentPathLength(start)});
  heap.push_back(start);
  push_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
    return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
  });

  while (heap.size() > 0) {
    auto head = heap.front();

    pop_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
      return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
    });
    heap.pop_back();

    graph.Visit(head);

    auto neighbors = graph.GetNeighbors(head);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      Cost tentativeScore = graph.currentPathLength(head) + graph.GetCost(*it);

      if (tentativeScore.GetValue() != -1)
        int x = 1;

      if (graph.IsVisited(*it) && tentativeScore < graph.currentPathLength(*it)) {
        f_function.find(it->GetIndex())->second = graph.GetCost(*it);
        heap.push_back(*it);
        push_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
          return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
        });
      }
      else if(tentativeScore < graph.currentPathLength(*it)) {
        f_function.insert({it->GetIndex(), graph.GetCost(*it)});
        heap.push_back(*it);
        push_heap(heap.begin(), heap.end(), [f_function](const Vertex &first, const Vertex &second) {
          return f_function.at(first.GetIndex()) > f_function.at(second.GetIndex());
        });
      }
      graph.UpdateVertex(*it, head);

      ++it;
    }
  }


  auto vertices = new list<pair<Vertex, Cost>>;

  const Vertex *temp = graph.GetEnd();

  Cost c = NULL;
  while (*temp != start) {
    c = graph.currentPathLength(*temp);
    vertices->push_front({*temp,graph.GetCost(*temp)});
    temp = graph.GetParent(*temp);
  }

  vertices->push_front({start, graph.GetCost(start)});

  return vertices;
}