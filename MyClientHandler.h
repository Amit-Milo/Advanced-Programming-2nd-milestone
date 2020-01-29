//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__MYCLIENTHANDLER_H_
#define EX4__MYCLIENTHANDLER_H_

#include "ClientHandlerAbs.h"
#include "ClientInputToProblemConverter.h"

class MyClientHandler: public ClientHandlerAbs<string>{
 public:
  MyClientHandler(CacheManager<MatrixGraph> *cache_manager,
                  Solver<MatrixGraph, string> *solver,
                  ClientInputToProblemConverter<MatrixGraph> *input_to_problem);
  string readFromClient(int client_socket, char *buffer) override;
};
#endif //EX4__MYCLIENTHANDLER_H_
