//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
class MyTestClientHandler : public server_side::ClientHandler {
  Solver solver;
 public:
  void handleClient(int client_socket, int server_socket) override;
};

#endif //EX4__MYTESTCLIENTHANDLER_H_