//
// Created by yoav on 27/01/2020.
//

#ifndef EX4__CLIENTINPUTTOMATRIXCONVERTER_H_
#define EX4__CLIENTINPUTTOMATRIXCONVERTER_H_

#include "ClientInputToProblemConverter.h"


class ClientInputToMatrixConverter: public ClientInputToProblemConverter<MatrixGraph>{
 private:
  int numberOfTotalLines(string s);//exculding the "end" line - just the matrix and the two points
  int numberOfMatrixRows(int numberOfTotalLines);
  int numberOfMatrixColumns(string firstLine);
  string* getMatrixLines(string s, int rows);
  int** getMatrixTable(string* lines, int rows, int columns);
  pair<Point,Point> getStartAndEndPoints(string s, int matrixRows);
 public:
  MatrixGraph convertToProblem(string clientInput) override;
};

#endif //EX4__CLIENTINPUTTOMATRIXCONVERTER_H_
