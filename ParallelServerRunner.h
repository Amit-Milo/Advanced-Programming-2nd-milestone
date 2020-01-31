//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__PARALLELSERVERRUNNER_H_
#define EX4__PARALLELSERVERRUNNER_H_

#include "ServerSocket.h"
#include "ServerRunner.h"
#include "ClientHandler.h"
#include <vector>

/**
 * this is a server runner that runs a parallel server.
 */
class ParallelServerRunner : public ServerRunner {
 public:
  /**
   * run the input server as a parallel server
   * @param s the input server
   * @param client_handler teh clients handler of the server
   */
  void RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) override;
};

#endif //EX4__PARALLELSERVERRUNNER_H_
