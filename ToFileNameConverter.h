//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__TOFILENAMECONVERTER_H_
#define EX4__TOFILENAMECONVERTER_H_

#include <string>

using namespace std;
template<class T>
class ToFileNameConverter{
 public:
  virtual string Convert(T objToConvert)=0;
};

#endif //EX4__TOFILENAMECONVERTER_H_
