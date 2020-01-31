//
// Created by yoav on 19/01/2020.
//

#include "MySerialServer.h"
#include "ServerSocket.h"

void MySerialServer::callRunner(server_side::ClientHandler *c) {
  //call the run server function
  printf("want to run server\n");
  SerialServerRunner server_runner;
  server_runner.RunServer(server_socket, c);
}
