//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__MATRIXTOFILENAMECONVERTER_H_
#define EX4__MATRIXTOFILENAMECONVERTER_H_

#include <string>
#include "ToFileNameConverter.h"
#include "MatrixGraph.h"

using namespace std;

/**
 * this class handles converting of a matrix graph to a file name.
 */
class MatrixToFileNameConverter : public ToFileNameConverter<MatrixGraph> {
 public:
  string Convert(MatrixGraph objToConvert) override;
};

#endif //EX4__MATRIXTOFILENAMECONVERTER_H_
