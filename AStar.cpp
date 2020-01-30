//
// Created by amit on 29/01/2020.
//

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "AStar.h"

using namespace std;

list<pair<Vertex, Cost>> * AStar::search(Searchable &graph) const {
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

    if (head == end) {
      break;
    }

    graph.Visit(head);

    auto neighbors = graph.GetNeighbors(head);
    auto it = neighbors->begin();

    while (it != neighbors->end()) {
      Cost tentativeScore = graph.currentPathLength(head) + graph.GetCost(*it);
      Cost heuristic = tentativeScore + graph.distance(head, *it);

      if (tentativeScore < graph.currentPathLength(*it)){
        auto val = f_function.find(it->GetIndex());
        if (val != f_function.end())
          val->second = heuristic;
        else
          f_function.insert({it->GetIndex(), heuristic});
      }
      graph.UpdateVertex(*it, head);

      if (!graph.IsVisited(*it)) {
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
    vertices->push_front({*temp, graph.GetCost(*temp)});
    temp = graph.GetParent(*temp);
  }

  vertices->push_front({start, graph.GetCost(start)});

  return vertices;
}
