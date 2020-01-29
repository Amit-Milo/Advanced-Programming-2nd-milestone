//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_CLIENTHANDLER_H_
#define EX4_SERVER_SIDE_CLIENTHANDLER_H_

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ServerSocket.h"

namespace server_side {

class ClientHandler {
 public:
  virtual void handleClient(int client_socket) = 0;
};

}
#endif //EX4_SERVER_SIDE_CLIENTHANDLER_H_
