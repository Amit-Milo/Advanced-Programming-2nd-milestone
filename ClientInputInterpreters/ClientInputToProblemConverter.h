//
// Created by yoav on 27/01/2020.
//

#ifndef EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_
#define EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_

#include <string>
using namespace std;
/**
 * this is an interface that has a function that its role is converting the client's input string into a problem
 * @tparam Problem the type of peroblem to solve
 */
template<class Problem>
class ClientInputToProblemConverter {
 public:
  /**
   * @param clientInput the whole data the client sent
   * @return the data converted to a problem
   */
  virtual Problem convertToProblem(string clientInput) = 0;

  /**
   * clone the converter
   * @return
   */
  virtual ClientInputToProblemConverter *clone() = 0;
};

#endif //EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_
