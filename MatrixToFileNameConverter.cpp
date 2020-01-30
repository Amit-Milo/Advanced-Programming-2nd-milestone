//
// Created by yoav on 25/01/2020.
//

#include <iostream>
#include "MatrixToFileNameConverter.h"

//TODO maybe fix it if it does not work
string MatrixToFileNameConverter::Convert(MatrixGraph objToConvert) {
  return std::to_string(objToConvert.hash());
}
