//
// Created by yoav on 19/01/2020.
//

#include "MySerialServer.h"
#include "ServerSocket.h"

void MySerialServer::start(int port, server_side::ClientHandler *c) {
  ServerSocket s(port);
  s.BindServer();
  //here have a loop in another thread that listens to clients and uses client handler.

}

//TODO
void MySerialServer::stop() {

}
