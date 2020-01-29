//
// Created by yoav on 25/01/2020.
//

#include <iostream>
#include "MatrixToFileNameConverter.h"

//TODO maybe fix it if it does not work
string MatrixToFileNameConverter::Convert(MatrixGraph objToConvert) {
  string result = to_string(std::hash<MatrixGraph>{}(objToConvert)).append(".txt");
  cout << "the file name of: " << objToConvert << " is: " << result << endl;
  return result;
}
