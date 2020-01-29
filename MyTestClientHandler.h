//
// Created by yoav on 19/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_


#include "ClientInputToProblemConverter.h"
#include "ClientHandlerAbs.h"


class MyTestClientHandler : public ClientHandlerAbs<string> {
 public:
  MyTestClientHandler(CacheManager<string> *cache_manager,
                      Solver<string, string> *solver,
                      ClientInputToProblemConverter<string> *input_to_problem);
  string readFromClient(int client_socket, char* buffer) override;
};

#endif //EX4__MYTESTCLIENTHANDLER_H_
