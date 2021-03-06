//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__CLIENTHANDLERABS_H_
#define EX4__CLIENTHANDLERABS_H_

#include "../Solvers/Solver.h"
#include <string>
#include <cstring>
#include <iostream>
#include "../CacheManagers/CacheManager.h"
#include "ClientHandler.h"
#include "../ClientInputInterpreters/ClientInputToProblemConverter.h"

#define BUFFER_SIZE 1024

using namespace std;
/**
 * this is an abstract class that implements the client handler interface's method using
 * the design pattern "template method" - it sets the skeleton of the client data reading,
 * but lets its child classes set the data protocol.
 * @tparam T the type of problem to solve
 */
template<class T>
class ClientHandlerAbs : public server_side::ClientHandler {
 protected:
  CacheManager<T> *cache_manager;
  Solver<T, string> *solver;
  ClientInputToProblemConverter<T> *input_to_problem;
 public:
  /**
   * a simple constructor.
   * @param cache_manager the cache manager that handles the memory files.
   * @param solver the object that solves the problem the client sent.
   * @param input_to_problem converts the input data to a problem using the given protocol
   */
  ClientHandlerAbs(CacheManager<T> *cache_manager,
                   Solver<T, string> *solver,
                   ClientInputToProblemConverter<T> *input_to_problem)
      : cache_manager(cache_manager), solver(solver), input_to_problem(input_to_problem) {}

  void handleClient(int client_socket) override {


    // Receive the amount of data sent by the simulator.
    int dataSize;

    // the total string from the client
    string clientInput = readFromClient(client_socket);


    T problem = input_to_problem->convertToProblem(clientInput);

    string solution;
    if (cache_manager->IsAlreadySolved(problem)) {
      solution = cache_manager->Solution(problem);
    } else {
      solution = solver->solve(problem);
      cache_manager->Save(problem, solution);
    }

    send(client_socket, solution.c_str(), strlen(solution.c_str()), 0);

    close(client_socket);
  }

  /**
   * reads the data from the client according to the data protocol
   * @param client_socket the client to read from
   * @param buffer a buffer to read data to
   * @return the whole data from teh client
   */
  virtual string readFromClient(int client_socket) = 0;

};

#endif //EX4__CLIENTHANDLERABS_H_
