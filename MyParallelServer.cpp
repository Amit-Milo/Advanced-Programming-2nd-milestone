//
// Created by yoav on 28/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::callRunner(server_side::ClientHandler *c) {
  //call the run server function
  printf("want to run server\n");
  ParallelServerRunner server_runner;
  server_runner.RunServer(server_socket, c);
}
