//
// Created by amit on 30/01/2020.
//

#include <unordered_map>

#include "MatrixShortestPathSolver.h"
#include "Movement.h"

list<string> MatrixShortestPathSolver::solve(MatrixGraph graph) {
  unordered_map<movement, string> cast;
  cast.insert({UP, "UP"});
  cast.insert({LEFT, "LEFT"});
  cast.insert({RIGHT, "RIGHT"});
  cast.insert({DOWN, "DOWN"});

  auto vertices = this->_searcher.search(graph);

  auto it2 = vertices->begin();
  auto it1 = it2 ++;
  auto end = vertices->end();

  list<string> moves;

  for (; it2 != end; ++it1, ++it2) {
    auto first = static_cast<MatrixVertex*>(&*it1);
    auto second = static_cast<MatrixVertex*>(&*it2);
    moves.push_back(cast.at(NextStep(first, second, graph.GetRows())));
  }

  return moves;
}
