//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_


template <class Problem, class Solution>
class Solver{
 public:
  /**
   * Solve a problem.
   * @param p a problem to solve.
   * @return A solution to the problem.
   */
  virtual Solution solve(Problem p) = 0;
};

#endif //EX4__SOLVER_H_
