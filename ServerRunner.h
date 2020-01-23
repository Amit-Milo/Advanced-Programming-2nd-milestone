//
// Created by yoav on 23/01/2020.
//

#ifndef EX4__SERVERRUNNER_H_
#define EX4__SERVERRUNNER_H_

#define TIME_OUT_SECONDS 120

#include "ServerSocket.h"
#include "ClientHandler.h"
class ServerRunner{
 public:
  void RunServer(ServerSocket* s, server_side::ClientHandler* client_handler);
};

#endif //EX4__SERVERRUNNER_H_
