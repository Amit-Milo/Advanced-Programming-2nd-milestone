//
// Created by yoav on 27/01/2020.
//

#include "ClientInputToMatrixConverter.h"

#include <iostream>

MatrixGraph ClientInputToMatrixConverter::convertToProblem(string clientInput) {
  int totalLines = numberOfTotalLines(clientInput);
  int rows = numberOfMatrixRows(totalLines);
  int columns = numberOfMatrixColumns(clientInput);
  string *matrixLines = getMatrixLines(clientInput, rows);
  int **matrixTable = getMatrixTable(matrixLines, rows, columns);
  //now we have rows, columns;
  Matrix<int> matrix(matrixTable, rows, columns);
  /*
  cout << "test whole matrix with * between numbers:" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << matrixTable[i][j] << "*";
    }
    cout << "\n";
  }*/
  Point start = getStartAndEndPoints(clientInput, rows).first;
  Point end = getStartAndEndPoints(clientInput, rows).second;
  /*
  cout<<"test start point:"<<start.GetI()<<","<<start.GetJ()<<endl;
  cout<<"test end point:"<<end.GetI()<<","<<end.GetJ()<<endl;*/
  //get the final result:
  MatrixGraph result(matrix, start, end);
  //now delete the pointers:
  delete[] matrixLines;
  for (int i = 0; i < rows; i++) {
    delete[] matrixTable[i];
  }
  delete[] matrixTable;
  //and finally, return the result;
  return MatrixGraph(matrix, start, end);
}

int ClientInputToMatrixConverter::numberOfTotalLines(string s) {
  int countEnters = 0;
  if (s.substr(s.length() - 4) == "end\n") {
    countEnters--;
  }
  //count how many \n are in the input string
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '\n')
      countEnters++;
  return countEnters;
}

int ClientInputToMatrixConverter::numberOfMatrixRows(int numberOfTotalLines) {
  return numberOfTotalLines - 2;
}

int ClientInputToMatrixConverter::numberOfMatrixColumns(string firstLine) {
  int sIndex = 0;
  int columns = 1; //count number of ',' and add 1
  while (firstLine[sIndex] != '\n') {
    if (firstLine[sIndex] == ',')
      columns++;
    sIndex++;
  }
  return columns;
}

string *ClientInputToMatrixConverter::getMatrixLines(string s, int rows) {
  string *lines = new string[rows];
  int i = 0;
  int rowsCount = 0;
  while (rowsCount < rows) {
    int lineEnd = s.find("\n", i);
    lines[rowsCount] = s.substr(i, lineEnd - i);
    //cout << "line:" << lines[rowsCount] << endl;
    i = lineEnd + 1;
    rowsCount++;
  }
  return lines;
}

int **ClientInputToMatrixConverter::getMatrixTable(string *lines, int rows, int columns) {
  int **matrixTable = new int *[rows];
  for (int i = 0; i < rows; ++i) {
    matrixTable[i] = new int[columns];
  }

  int j = 0;
  int curr = 0;
  //now create the matrix
  for (int i = 0; i < rows; i++) {

    while (j < columns) {
      int nextStop = lines[i].find(',', curr);
      if (nextStop == -1) {
        //cout << "test last in line, i,j,n: " << i << "," << j << "," << lines[i].substr(curr, rows - curr - 1).c_str()<< endl;
        matrixTable[i][j] = stoi(lines[i].substr(curr, rows - curr - 1)); //assign the value
      } else {
        //cout << "test middle of line, i,j,n: " << i << "," << j << "," << lines[i].substr(curr, nextStop - curr).c_str()<< endl;
        matrixTable[i][j] = stoi(lines[i].substr(curr, nextStop - curr)); //assign the value
      }

      curr = nextStop + 1;
      j++;
    }
    j = 0;

  }
  return matrixTable;
}

pair<Point, Point> ClientInputToMatrixConverter::getStartAndEndPoints(string s, int matrixRows) {
  int startX, startY, endX, endY;
  int i = 0;
  for (int c = 0; c < matrixRows; c++) {
    i = s.find("\n", i) + 1;
  }
  //now i is at the beginning of the start point line
  int nextStop = s.find(',', i);
  startX = atoi(s.substr(i, nextStop - i).c_str());
  i = nextStop + 1;
  nextStop = s.find('\n', i);
  startY = atoi(s.substr(i, nextStop - i).c_str());
  i = nextStop + 1;
  nextStop = s.find(',', i);
  endX = atoi(s.substr(i, nextStop - i).c_str());
  i = nextStop + 1;
  nextStop = s.find('\n', i);
  endY = atoi(s.substr(i, nextStop - i).c_str());

  Point start(startX, startY);
  Point end(endX, endY);
  return pair<Point, Point>(start, end);
}
ClientInputToProblemConverter<MatrixGraph> *ClientInputToMatrixConverter::clone() {
  return new ClientInputToMatrixConverter();
}

