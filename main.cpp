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

int main(int argc, char *argv[]) {
  int port_number;
  if (argc <= 1) {
    port_number = 5600;
  } else {
    port_number = atoi(argv[1]);
  }
  //MySerialServer serialServer;
  MyParallelServer parallel_server;

  BestFirstSearch bf;
  BFS b;
  MatrixGraphSearcher m(&bf);
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

  int **arr = new int*[3];

  for (int i = 0; i < 3; i++)
    arr[i] = new int[3];

  for (int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if (i == 0)
        arr[i][j] = 3;
      else if (i == 1)
        arr[i][j] = 2;
      else
        arr[i][j] = 1;

  Matrix<int> mat = Matrix<int>(arr, 3, 3);

  MatrixGraph graph = MatrixGraph(mat, Point(0, 0), Point(2, 2));

  MatrixShortestPathSolver msps = MatrixShortestPathSolver(m);
  string s = msps.solve(graph);
  ///list<Vertex> *l = m.search(graph);
  cout << s <<endl;

  return 0;*/
}
