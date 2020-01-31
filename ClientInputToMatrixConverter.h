//
// Created by yoav on 27/01/2020.
//

#ifndef EX4__CLIENTINPUTTOMATRIXCONVERTER_H_
#define EX4__CLIENTINPUTTOMATRIXCONVERTER_H_

#include "ClientInputToProblemConverter.h"
#include "MatrixGraph.h"
/**
 * this class converts the client input data into a MatrixGraph
 */
class ClientInputToMatrixConverter : public ClientInputToProblemConverter<MatrixGraph> {
 private:
  /**
   * @param s the client data
   * @return number of total lines in the client's data, excluding the last "end" line - just matrix and two points lines
   */
  int numberOfTotalLines(string s);
  /**
   * @param numberOfTotalLines number of lines in the whole client data
   * @return number of lines that represent the matrix = number of matrix rows
   */
  int numberOfMatrixRows(int numberOfTotalLines);
  /**
   * @param firstLine the first line of the matrix
   * @return number of columns in teh matrix
   */
  int numberOfMatrixColumns(string firstLine);
  /**
   * @param s the input data from client
   * @param rows the number of matrix rows
   * @return an array of matrix rows as strings
   */
  string *getMatrixLines(string s, int rows);
  /**
   * @param lines an array of matrix rows as strings
   * @param rows rows the number of matrix rows
   * @param columns rows the number of matrix columns
   * @return a 2-D array of the matrix
   */
  int **getMatrixTable(string *lines, int rows, int columns);
  /**
   * @param s the input data from client
   * @param matrixRows numbe of matrix rows = number of lines to jump beyond
   * @return start and end points of the graph
   */
  pair<Point, Point> getStartAndEndPoints(string s, int matrixRows);
 public:
  MatrixGraph convertToProblem(string clientInput) override;

  ClientInputToProblemConverter<MatrixGraph> *clone() override;
};

#endif //EX4__CLIENTINPUTTOMATRIXCONVERTER_H_
