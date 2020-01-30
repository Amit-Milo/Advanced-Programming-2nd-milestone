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
}
