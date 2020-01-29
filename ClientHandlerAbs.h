//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__CLIENTHANDLERABS_H_
#define EX4__CLIENTHANDLERABS_H_

#include "Solver.h"
#include <string>
#include <cstring>
#include "CacheManager.h"
#include "ClientHandler.h"
#include "ClientInputToProblemConverter.h"

#define BUFFER_SIZE 1024

template<class T>
class ClientHandlerAbs : public server_side::ClientHandler {
 protected:
  CacheManager<T> *cache_manager;
  Solver<T, string> *solver;
  ClientInputToProblemConverter<T> *input_to_problem;
 public:
  ClientHandlerAbs(CacheManager<T> *cache_manager,
                   Solver<T, string> *solver,
                   ClientInputToProblemConverter<T> *input_to_problem)
      : cache_manager(cache_manager), solver(solver), input_to_problem(input_to_problem) {}

  void handleClient(int client_socket) override {
    // A buffer for reading data sent from the client.
    char buffer[BUFFER_SIZE];
    //need to init all the chars because for some reason it keeps the chars from prev client
    for (int i = 0; i < BUFFER_SIZE; i++) {
      buffer[i] = 0;
    }

    // Receive the amount of data sent by the simulator.
    int dataSize;

    // the total string from the client
    string clientInput = readFromClient(client_socket, buffer);

    printf("final message from client: %s\n", clientInput.c_str());

    T problem = input_to_problem->convertToProblem(clientInput);

    string solution = cache_manager->Solution(problem, solver);

    printf("the solution: %s \n", solution.c_str());
    send(client_socket, solution.c_str(), strlen(solution.c_str()), 0);

    close(client_socket);
  }

  virtual string readFromClient(int client_socket, char *buffer) = 0;
};

#endif //EX4__CLIENTHANDLERABS_H_
