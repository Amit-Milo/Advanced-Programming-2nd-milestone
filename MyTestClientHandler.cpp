//
// Created by yoav on 19/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileStringCacheManager.h"

MyTestClientHandler::MyTestClientHandler(CacheManager<string> *cache_manager,
                                         Solver<string, string> *solver,
                                         ClientInputToProblemConverter<string> *input_to_problem) : ClientHandlerAbs(
    cache_manager,
    solver,
    input_to_problem) {}

string MyTestClientHandler::readFromClient(int client_socket) {
  cout << "starting to read for client:" << client_socket << endl;
  // A buffer for reading data sent from the client.
  char buffer[BUFFER_SIZE];
  //need to init all the chars because for some reason it keeps the chars from prev client
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 0;
  }

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

    // Concat the given data with the reminder from previous iteration.
    clientInput += string(buffer);
  }
  return clientInput;
}


