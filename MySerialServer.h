//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_MYSERIALSERVER_H_
#define EX4_SERVER_SIDE_MYSERIALSERVER_H_

#include "Server.h"

class MySerialServer :public server_side::Server{
  ServerSocket* server_socket;
 public:
  void start(int port, server_side::ClientHandler *c) override ;
  void stop() override;
};

#endif //EX4_SERVER_SIDE_MYSERIALSERVER_H_
