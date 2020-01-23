//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
//TODO notice that in part 2 there is only one type of client handler - with strings. should probably change later.
class MyTestClientHandler : public server_side::ClientHandler {
  Solver<string, string> *solver;
  CacheManager<string> *cache_manager;
 public:
  void handleClient(int client_socket, int server_socket) override;
};

#endif //EX4__MYTESTCLIENTHANDLER_H_
