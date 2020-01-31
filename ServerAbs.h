//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__SERVERABS_H_
#define EX4__SERVERABS_H_

#include "Server.h"


/**
 * this is an abstract class that implements the Server methods using a design pattern "template method" -
 * it starts and binds the server and the calls the input runner to run
 */
class ServerAbs : public server_side::Server {
 protected:
  ServerSocket *server_socket;
 public:
  void start(int port, server_side::ClientHandler *c) override {
    printf("entered start\n");
    //init the server
    server_socket = new ServerSocket(port);
    server_socket->BindServer();
    callRunner(c);
  }
  void stop() override {
    delete server_socket;
  }
  /**
   * call the running of the input server runner
   * @param c the server runner to run.
   */
  virtual void callRunner(server_side::ClientHandler *c) = 0;
};

#endif //EX4__SERVERABS_H_
