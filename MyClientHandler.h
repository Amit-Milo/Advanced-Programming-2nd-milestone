//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__MYCLIENTHANDLER_H_
#define EX4__MYCLIENTHANDLER_H_

#include "ClientHandlerAbs.h"
#include "ClientInputToProblemConverter.h"
#include "MatrixGraph.h"

/**
 * this client handler has a protocol of stopping the client data reading when reached a "end" string
 */
class MyClientHandler : public ClientHandlerAbs<MatrixGraph> {
 public:
  MyClientHandler(CacheManager<MatrixGraph> *cache_manager,
                  Solver<MatrixGraph, string> *solver,
                  ClientInputToProblemConverter<MatrixGraph> *input_to_problem);
  /**
   * read from the client until we get an "end" string.
   * @param client_socket the client to read from
   * @param buffer the buffer to read to
   * @return the data from the client
   */
  string readFromClient(int client_socket, char *buffer) override;

  ClientHandler *clone() override {
    return new MyClientHandler(this->cache_manager->clone(),
                                          this->solver->clone(), this->input_to_problem->clone());
  }
};
#endif //EX4__MYCLIENTHANDLER_H_
