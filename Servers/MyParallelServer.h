//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__MYPARALLELSERVER_H_
#define EX4__MYPARALLELSERVER_H_

#include "ServerAbs.h"
#include "../ServerRunners/ParallelServerRunner.h"

/**
 * this class implements a parallel server
 */
class MyParallelServer : public ServerAbs {
 public:
  /**
   * call a parallel server runner
   * @param c the client handler
   */
  void callRunner(server_side::ClientHandler *c) override;
};

#endif //EX4__MYPARALLELSERVER_H_
