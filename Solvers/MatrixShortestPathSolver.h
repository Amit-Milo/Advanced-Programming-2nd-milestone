//
// Created by amit on 30/01/2020.
//

#ifndef ADVANCEDPROGRAMMINGMILESTONE2__MATRIXSHORTESTPATHSOLVER_H_
#define ADVANCEDPROGRAMMINGMILESTONE2__MATRIXSHORTESTPATHSOLVER_H_

#include <list>
#include <string>
#include <utility>

#include "../Searchables/MatrixGraph.h"
#include "../Searchers/GraphSearchers/MatrixGraphSearcher.h"
#include "Solver.h"

class MatrixShortestPathSolver : public Solver<MatrixGraph, string> {
  MatrixGraphSearcher _searcher;

 public:
  MatrixShortestPathSolver(MatrixGraphSearcher searcher) : _searcher(std::move(searcher)) {}

  /**
   * Solve a problem.
   * @param p a problem to solve.
   * @return A solution to the problem.
   */
  virtual string solve(MatrixGraph graph);

  Solver<MatrixGraph, string> *clone() override {
    return new MatrixShortestPathSolver(*_searcher.clone());
  }
};

#endif //ADVANCEDPROGRAMMINGMILESTONE2__MATRIXSHORTESTPATHSOLVER_H_