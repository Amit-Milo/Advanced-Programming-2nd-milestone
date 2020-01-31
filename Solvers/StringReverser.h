//
// Created by amit on 22/01/2020.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include <string>

#include "Solver.h"

using namespace std;

/**
 * this is a solve that accepts a string type and returns a string that is the input string reversed.
 */
class StringReverser : public Solver<string, string> {
 public:
  /**
   * Solve a problem.
   * Reverse a given string.
   * @param p a problem to solve. A string to reverse.
   * @return A solution to the problem. The reversed string.
   */
  string solve(string p);

  Solver<string, string> *clone() override;
};

#endif //EX4__STRINGREVERSER_H_