//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__SERVERRUNNER_H_
#define EX4__SERVERRUNNER_H_

//TODO change to 120
#define TIME_OUT_SECONDS 15

#include "ServerSocket.h"
#include "ClientHandler.h"

/**
 * this is an interface that handles running the server
 */
class ServerRunner {
 protected:
  ServerSocket *server_socket;
 public:
  /**
   * run the input server according to your type
   * @param s the input server
   * @param client_handler teh clients handler of the server
   */
  virtual void RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) = 0;

  /**
   * print that a second has passed each second - for debugging
   */
  static void printSecond() {
    printf("entered thread\n");
    int seconds = 1;
    int waitTime = 1;
    while (true) {
      sleep(waitTime);
      printf("a second passed, %d\n", seconds);
      seconds += waitTime;
    }
  }
};

#endif //EX4__SERVERRUNNER_H_
