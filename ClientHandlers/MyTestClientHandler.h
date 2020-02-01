//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "../ClientInputInterpreters/ClientInputToProblemConverter.h"
#include "ClientHandlerAbs.h"

/**
 * this client handler has a protocol of stopping only then client disconnected.
 */
class MyTestClientHandler : public ClientHandlerAbs<string> {
 public:
  MyTestClientHandler(CacheManager<string> *cache_manager,
                      Solver<string, string> *solver,
                      ClientInputToProblemConverter<string> *input_to_problem);
  /**
   * read from the client until he disconnects.
   * @param client_socket the client to read from
   * @param buffer the buffer to read to
   * @return the data from the client
   */
  string readFromClient(int client_socket) override;

  ClientHandler *clone() override {
    return new MyTestClientHandler(this->cache_manager->clone(),
                                   this->solver->clone(), this->input_to_problem->clone());
  }
};

#endif //EX4__MYTESTCLIENTHANDLER_H_
