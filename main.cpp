#include <iostream>
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "FileStringCacheManager.h"
#include "StringReverser.h"
#include "ClientInputToStringConverter.h"
#include "MyClientHandler.h"
#include "FileMatrixCacheManager.h"
#include "MatrixGraphSearcher.h"
#include "BestFirstSearch.h"
#include "MatrixShortestPathSolver.h"
#include "ClientInputToMatrixConverter.h"

//TODO remove couts and printfs
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

int main(int argc, char *argv[]) {
  int port_number;
  if (argc <= 1) {
    port_number = 12345;
  } else {
    port_number = atoi(argv[1]);
  }
  //MySerialServer serialServer;
  MyParallelServer parallel_server;

  BestFirstSearch bf;
  BFS b;
  DFS d;
  AStar a;
  MatrixGraphSearcher m(&a);
  MatrixShortestPathSolver msps(m);


  //init a client handler with a cache manager that has a problems solver.
  MyClientHandler *clientHandler =
      new MyClientHandler(new FileMatrixCacheManager(),
                          (&msps), new ClientInputToMatrixConverter());

  //reinterpret_cast<Solver<struct MatrixGraph, std::__cxx11::string> *>

  parallel_server.start(port_number, clientHandler);

  parallel_server.stop();

  delete clientHandler;

  return 0;
  /*///queue<int> q;
  ///BFS b;
  ///DFS d;
  ///AStar a;
  BestFirstSearch bf;
  MatrixGraphSearcher m = MatrixGraphSearcher(&bf);

  int r = 20, c = 20;

  int **arr = new int*[r];

  for (int i = 0; i < r; i++)
    arr[i] = new int[c];

  for (int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      if (i == 0)
        arr[i][j] = 3;
      else if (i == 1)
        arr[i][j] = 5;
      else
        arr[i][j] = 1;

      arr[1][0] = -1;

  Matrix<int> mat = Matrix<int>(arr, r, c);

  MatrixGraph graph = MatrixGraph(mat, Point(0, 0), Point(r - 1, c - 1));

  MatrixShortestPathSolver msps = MatrixShortestPathSolver(m);
  string s = msps.solve(graph);
  ///list<Vertex> *l = m.search(graph);
  cout << s <<endl;

  return 0;*/
}
