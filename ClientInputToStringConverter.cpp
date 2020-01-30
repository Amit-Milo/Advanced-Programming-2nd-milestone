//
// Created by yoav on 27/01/2020.
//

#include "ClientInputToStringConverter.h"
string ClientInputToStringConverter::convertToProblem(string clientInput) {
  return clientInput;
}
ClientInputToProblemConverter<string> *ClientInputToStringConverter::clone() {
  return new ClientInputToStringConverter();
}
