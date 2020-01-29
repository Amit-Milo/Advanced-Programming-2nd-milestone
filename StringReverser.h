//
// Created by amit on 22/01/2020.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include <string>

#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
 public:
  /**
   * Solve a problem.
   * Reverse a given string.
   * @param p a problem to solve. A string to reverse.
   * @return A solution to the problem. The reversed string.
   */
  string solve(const string &p) const;
};

#endif //EX4__STRINGREVERSER_H_