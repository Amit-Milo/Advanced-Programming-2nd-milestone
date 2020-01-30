//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_

/**
 * this is an interface for a solver that gets a problem and returns a solution
 * @tparam Problem the type of the problem
 * @tparam Solution the type of the solution
 */
template<class Problem, class Solution>
class Solver {
 public:
  /**
   * Solve a problem.
   * @param p a problem to solve.
   * @return A solution to the problem.
   */
  virtual Solution solve(const Problem &p) const = 0;
};

#endif //EX4__SOLVER_H_