//
// Created by yoav on 25/01/2020.
//

#include <iostream>
#include "StringToFileNameConverter.h"
string StringToFileNameConverter::Convert(string objToConvert) {
  string result = to_string(std::hash<std::string>{}(objToConvert)).append(".txt");
  cout << "the file name of: " << objToConvert << " is: " << result << endl;
  return result;
}
