//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_

class Solver<class Problem, class Solution>{
 public:
  Solution solve(const Problem &p) const;
};

#endif //EX4__SOLVER_H_
