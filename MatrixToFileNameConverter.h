//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__MATRIXTOFILENAMECONVERTER_H_
#define EX4__MATRIXTOFILENAMECONVERTER_H_

#include <string>
#include "ToFileNameConverter.h"

using namespace std;

class MatrixToFileNameConverter:public ToFileNameConverter<MatrixGraph>{
 public:
  string Convert(MatrixGraph objToConvert) override;
};

#endif //EX4__MATRIXTOFILENAMECONVERTER_H_
