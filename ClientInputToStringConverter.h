//
// Created by yoav on 27/01/2020.
//

#ifndef EX4__CLIENTINPUTTOSTRINGCONVERTER_H_
#define EX4__CLIENTINPUTTOSTRINGCONVERTER_H_

#include <string>
using namespace std;

#include "ClientInputToProblemConverter.h"

class ClientInputToStringConverter : public ClientInputToProblemConverter<string>{
  string convertToProblem(string clientInput) override;

 public:
  ClientInputToProblemConverter<string> *clone() override;
};

#endif //EX4__CLIENTINPUTTOSTRINGCONVERTER_H_
