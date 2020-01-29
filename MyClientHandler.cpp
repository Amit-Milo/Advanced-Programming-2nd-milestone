//
// Created by yoav on 28/01/2020.
//

#include "MyClientHandler.h"



string MyClientHandler::readFromClient(int client_socket, char *buffer) {
  string clientInput;
  int dataSize;
  while (true) {
    // Receive data from the simulator.
    dataSize = read(client_socket, buffer, BUFFER_SIZE);

    if (dataSize == 0)
      // If didn't read nothing, continue to next iteration.
      continue;
    else if (dataSize == -1) {
      //end the loop.
      break;
    }


    //find if the client sent "end". the "end" should appear right after the last \n:

    //get the last index with \n
    int lastNewLine = clientInput.rfind("\n");
    if (lastNewLine != -1) {
      //get the string that comes after the last \n
      string lastPart = clientInput.substr(lastNewLine + 1);
      //check if the last part starts with "end", so we need to stop.
      if (lastPart.length() >= 3) {
        if (strncmp(lastPart.c_str(), "end", 3) == 0) {
          break;
        }
      }
    }

    // Concat the given data with the reminder from previous iteration.
    clientInput += string(buffer);
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




