//
// Created by yoav on 19/01/2020.
//

#include "MySerialServer.h"
#include "ServerSocket.h"
#include "ServerRunner.h"

void MySerialServer::start(int port, server_side::ClientHandler *c) {
  //init the server
  server_socket =  new ServerSocket(port);
  server_socket->BindServer();
  //call the run server function
  ServerRunner server_runner;
  server_runner.RunServer(server_socket, c);
}

//TODO - DONE?
void MySerialServer::stop() {
  delete server_socket;
}
