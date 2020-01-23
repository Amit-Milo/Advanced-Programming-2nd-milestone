//
// Created by yoav on 19/01/2020.
//

#include <cstring>
#include "MyTestClientHandler.h"


//TODO this is the implementation to part 2 only!!!!

void MyTestClientHandler::handleClient(ServerSocket *server_socket, int client_socket) {
  // A buffer for reading data sent from the client.
  char buffer[BUFFER_SIZE];

  // Receive the amount of data sent by the simulator.
  int dataSize;

  // the total string from the client
  char *result;


  //TODO maybe change the stop condition to be more ordered
  while (true) {
    // Receive data from the simulator.
    dataSize = read(server_socket->GetServerSocket(), buffer, BUFFER_SIZE);

    if (dataSize < 1)
      // If didn't read nothing, continue to next iteration.
      continue;

    // Concat the given data with the reminder from previous iteration.
    result = strcat(result, buffer);

    //find if the client sent "end". the "end" should appear right after the last \n:

    //get the last index with \n
    int lastNewLine = string(result).rfind("\n");
    //get the string that comes after the last \n
    char *lastPart = result + lastNewLine + 1;
    //check if the last part starts with "end", so we need to stop.
    if (lastNewLine != -1 && strlen(lastPart) >= 3) {
      if (strncmp(lastPart, "end", 3) == 0) {
        break;
      }
    }
  }

  close(client_socket);

}