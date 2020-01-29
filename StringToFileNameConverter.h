//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__STRINGTOFILENAMECONVERTER_H_
#define EX4__STRINGTOFILENAMECONVERTER_H_

#include "ToFileNameConverter.h"
#include <string>

using namespace std;

class StringToFileNameConverter: public ToFileNameConverter<string>{
 public:
  string Convert(string objToConvert) override;
};

#endif //EX4__STRINGTOFILENAMECONVERTER_H_
