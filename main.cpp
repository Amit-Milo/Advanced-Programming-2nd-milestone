#include <iostream>
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "FileStringCacheManager.h"
#include "StringReverser.h"
#include "ClientInputToStringConverter.h"
#include "MyClientHandler.h"
#include "FileMatrixCacheManager.h"

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


  //init a client handler with a cache manager that has a problems solver.
  //TODO for running, doesnt compile on purpose. should have the solve that uses a searcher.
  x =;
  MyClientHandler *clientHandler =
      new MyClientHandler(new FileMatrixCacheManager(),);

  parallel_server.start(port_number, clientHandler);

  parallel_server.stop();

  return 0;
}
