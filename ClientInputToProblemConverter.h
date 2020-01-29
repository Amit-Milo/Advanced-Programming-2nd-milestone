//
// Created by yoav on 27/01/2020.
//

#ifndef EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_
#define EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_

#include <string>
using namespace std;

template<class Problem>
class ClientInputToProblemConverter{
 public:
  virtual Problem convertToProblem(string clientInput)=0;
};

#endif //EX4__CLIENTINPUTTOPROBLEMCONVERTER_H_
