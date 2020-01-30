//
// Created by yoav on 28/01/2020.
//

#ifndef EX4__CLIENTHANDLERABS_H_
#define EX4__CLIENTHANDLERABS_H_

#include "Solver.h"
#include <string>
#include <cstring>
#include <iostream>
#include "CacheManager.h"
#include "ClientHandler.h"
#include "ClientInputToProblemConverter.h"

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

    printf("final message from client: %s\n", clientInput.c_str());

    T problem = input_to_problem->convertToProblem(clientInput);

    string solution;
    cout << "checking for solution: client number is " << client_socket << endl;
    if (cache_manager->IsAlreadySolved(problem)) {
      cout << "was already solved: client number is " << client_socket << endl;
      solution = cache_manager->Solution(problem);
    } else {
      cout << "was not already solved: client number is " << client_socket << endl;
      solution = solver->solve(problem);
      cout << "solution for client " << client_socket << " , is: " << solution << endl;
      cache_manager->Save(problem, solution);
    }

    printf("the solution: %s \n", solution.c_str());
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
