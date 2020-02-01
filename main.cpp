#include <iostream>
#include "Servers/MySerialServer.h"
#include "Servers/MyParallelServer.h"
#include "ClientHandlers/MyTestClientHandler.h"
#include "CacheManagers/FileCacheManagers/FileStringCacheManager.h"
#include "Solvers/StringReverser.h"
#include "ClientInputInterpreters/ClientInputToStringConverter.h"
#include "ClientHandlers/MyClientHandler.h"
#include "CacheManagers/FileCacheManagers/FileMatrixCacheManager.h"
#include "Searchers/GraphSearchers/MatrixGraphSearcher.h"
#include "Searchers/GraphSearchers/BestFirstSearch.h"
#include "Solvers/MatrixShortestPathSolver.h"
#include "ClientInputInterpreters/ClientInputToMatrixConverter.h"

#include "Searchers/GraphSearchers/BFS.h"
#include "Searchers/GraphSearchers/DFS.h"
#include "Searchers/GraphSearchers/AStar.h"

int main(int argc, char *argv[]) {
  int port_number;
  if (argc <= 1) {
    port_number = 12345;
  } else {
    port_number = atoi(argv[1]);
  }
  MyParallelServer parallel_server;

  AStar a;
  MatrixGraphSearcher m(&a);
  MatrixShortestPathSolver msps(m);


  //init a client handler with a cache manager that has a problems solver.
  MyClientHandler *clientHandler =
      new MyClientHandler(new FileMatrixCacheManager(),
                          (&msps), new ClientInputToMatrixConverter());


  parallel_server.start(port_number, clientHandler);

  parallel_server.stop();

  delete clientHandler;

  return 0;

}
