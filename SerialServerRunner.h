//
// Created by yoav on 23/01/2020.
//

#ifndef EX4__SERIALSERVERRUNNER_H_
#define EX4__SERIALSERVERRUNNER_H_

#include "ServerSocket.h"
#include "ClientHandler.h"
#include "ServerRunner.h"

class SerialServerRunner : public ServerRunner{
 public:
  void RunServer(ServerSocket *s, server_side::ClientHandler *client_handler);
};

#endif //EX4__SERIALSERVERRUNNER_H_