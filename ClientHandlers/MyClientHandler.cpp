//
// Created by yoav on 28/01/2020.
//

#include <iostream>
#include "MyClientHandler.h"

string MyClientHandler::readFromClient(int client_socket) {
  // A buffer for reading data sent from the client.
  char buffer[BUFFER_SIZE];
  //need to init all the chars because for some reason it keeps the chars from prev client
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 0;
  }

  string clientInput;
  int dataSize;
  while (true) {

    for (int i = 0; i < BUFFER_SIZE; i++) {
      buffer[i] = 0;
    }
    // Receive data from the simulator.
    dataSize = read(client_socket, buffer, BUFFER_SIZE);

    if (dataSize == 0) {
      // If didn't read nothing, continue to next iteration.
      continue;
    } else if (dataSize == -1) {
      //end the loop.
      break;
    }


    // Concat the given data with the reminder from previous iteration.
    clientInput += string(buffer);

    //find if the client sent "end". the "end" should appear right after the last \n:

    if (clientInput.length() > 3) {
      ////////check if file does not end with \n
      if (strcmp(clientInput.substr(clientInput.length() - 3).c_str(), "end") == 0) {
        break;
      }

      ////////check if file does end with \n
      if (strcmp(clientInput.substr(clientInput.length() - 4).c_str(), "end\n") == 0) {
        break;
      }
    }
  }
  return clientInput;
}

MyClientHandler::MyClientHandler(CacheManager<MatrixGraph> *cache_manager,
                                 Solver<MatrixGraph, string> *solver,
                                 ClientInputToProblemConverter<MatrixGraph> *input_to_problem) : ClientHandlerAbs(
    cache_manager,
    solver,
    input_to_problem) {

}




