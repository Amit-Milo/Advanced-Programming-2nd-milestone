//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__MYTESYCLIENTHANDLER_H_
#define EX4__MYTESYCLIENTHANDLER_H_

#include "ClientHandler.h"
class MyTestClientHandler : public server_side::ClientHandler {
 public:
  void handleClient(int client_socket, int server_socket) override;
};

#endif //EX4__MYTESYCLIENTHANDLER_H_
