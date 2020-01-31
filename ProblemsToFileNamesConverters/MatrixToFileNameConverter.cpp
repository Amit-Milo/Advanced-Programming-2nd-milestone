//
// Created by yoav on 25/01/2020.
//

#include <iostream>
#include "MatrixToFileNameConverter.h"


string MatrixToFileNameConverter::Convert(MatrixGraph objToConvert) {
  return std::to_string(objToConvert.hash()) + ".txt";
}
