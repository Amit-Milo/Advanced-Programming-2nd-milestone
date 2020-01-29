//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__PARALLELSERVERRUNNER_H_
#define EX4__PARALLELSERVERRUNNER_H_

#include "ServerSocket.h"
#include "ServerRunner.h"
#include "ClientHandler.h"
#include <vector>

class ParallelServerRunner : public ServerRunner {
 public:
  void RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) override;
};

#endif //EX4__PARALLELSERVERRUNNER_H_
