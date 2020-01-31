//
// Created by yoav on 23/01/2020.
//

#ifndef EX4__SERIALSERVERRUNNER_H_
#define EX4__SERIALSERVERRUNNER_H_

#include "../ServerSocket.h"
#include "../ClientHandlers/ClientHandler.h"
#include "ServerRunner.h"

/**
 * this is a server runner that runs a serial server.
 */
class SerialServerRunner : public ServerRunner{
 public:
  /**
   * run the input server as a serial server
   * @param s the input server
   * @param client_handler teh clients handler of the server
   */
  void RunServer(ServerSocket *s, server_side::ClientHandler *client_handler);
};

#endif //EX4__SERIALSERVERRUNNER_H_