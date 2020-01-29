//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_MYSERIALSERVER_H_
#define EX4_SERVER_SIDE_MYSERIALSERVER_H_

#include "ServerAbs.h"
#include "SerialServerRunner.h"

class MySerialServer :public ServerAbs{
 public:
  void callRunner(server_side::ClientHandler *c) override;
};

#endif //EX4_SERVER_SIDE_MYSERIALSERVER_H_
