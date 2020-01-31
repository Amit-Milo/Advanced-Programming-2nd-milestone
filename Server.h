//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_SERVER_H_
#define EX4_SERVER_SIDE_SERVER_H_

#include "ClientHandler.h"
#include "CacheManager.h"

namespace server_side {

/**
 * this is an interface for a server that starts clients handling and closes when needed.
 */
class Server {
 public:
  /**
   * should open the server and wait for clients.
   * @param port the port number to open the server on.
   * @param c the client handler to operate.
   */
  virtual void start(int port, server_side::ClientHandler *c) = 0;
  /**
   * should close he server.
   */
  virtual void stop() = 0;
};

}
#endif //EX4_SERVER_SIDE_SERVER_H_
