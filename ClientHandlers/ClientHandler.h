//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_CLIENTHANDLER_H_
#define EX4_SERVER_SIDE_CLIENTHANDLER_H_

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../ServerSocket.h"

namespace server_side {

/**
 * this is an interface that has the method that a client handler should run
 */
class ClientHandler {
 public:
  /**
   * handle the given client by this client handler's functionality
   * @param client_socket the client to handle
   */
  virtual void handleClient(int client_socket) = 0;

  /**
   * clone the client handler
   * @return a pointer to a cloned client handler.
   */
  virtual ClientHandler *clone() = 0;
};

}
#endif //EX4_SERVER_SIDE_CLIENTHANDLER_H_
