//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__MYPARALLELSERVER_H_
#define EX4__MYPARALLELSERVER_H_

#include "ServerAbs.h"
#include "ParallelServerRunner.h"

class MyParallelServer: public ServerAbs{
 public:
  void callRunner(server_side::ClientHandler *c) override;
};

#endif //EX4__MYPARALLELSERVER_H_
