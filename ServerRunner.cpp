//
// Created by yoav on 23/01/2020.
//

#include "ServerRunner.h"

//TODO
void ServerRunner::RunServer(ServerSocket* s) {

}






//TODO figure it out
void OpenDataServerCommand::run_server(Container *container) {
  container->AddThread();

  // A buffer for reading data sent from the simulator.
  char *buffer = (char *) malloc(sizeof(char) * this->maxSize);

  if (buffer == NULL) {
    // Check if allocation succeed.
    container->ReleaseThread();
    throw "Allocation problem.";
  }

  // Receive the amount of data sent by the simulator.
  int dataSize;

  // A vector of values of vars.
  float *values = (float *) malloc(sizeof(float) * this->simVarsAmount);

  if (values == NULL) {
    // Check if allocation succeed.
    container->ReleaseThread();
    throw "Allocation problem.";
  }

  // A reminder from the last time the simulator sent a message.
  char *reminder = (char *) malloc(sizeof(char) * this->maxSize);

  if (reminder == NULL) {
    // Check if allocation succeed.
    container->ReleaseThread();
    throw "Allocation problem.";
  }

  // A concat of reminder and buffer;
  char *result;

  // The next index to assign value to next time.
  int firstValue = 0;

  // Rename some vars.
  int server_socket = container->GetSockets().server_socket;
  sockaddr_in server_address = container->GetSockets().server_address;


  if (listen(server_socket, 1) == -1)
    // If can't listen, throw an error.
    throw "Couldn't listen.";

  // Accept the client.
  int client_socket = accept(server_socket, (struct sockaddr *) &server_address, (socklen_t *) &server_address);

  if (client_socket == -1)
    // If can't accept a client, throw an error.
    throw "Couldn't accept a client.";

  // We succeeded communicating with the simulator.
  container->GetSockets().serverConnected = true;

  while (container->ProgramRuns()) {
    // Receive data from the simulator.
    dataSize = read(client_socket, buffer, maxSize);

    if (dataSize < 1)
      // If didn't read nothing, continue to next iteration.
      continue;

    // Concat the given data with the reminder from previous iteration.
    result = strcat(reminder, buffer);

    pair<int, int> stats = splitValues(result, ",", values);

    // Get next index to read from.
    int lastEnd = stats.first;

    // Get the amount of vars read.
    int valuesLength = stats.second;

    if (lastEnd != string::npos)
      // Move to the next index to read from.
      reminder = result + lastEnd + 1;
    else
      *reminder = '\0';

    for (int i = firstValue; i - firstValue < valuesLength; ++i) {
      // Write each variable to the map.
      this->container->GetMaps()->WriteSimulatorVar(this->container->GetMaps()->GetNames()[i], values[i]);
      this->container->GetMaps()->WriteWrappedVar(this->container->GetMaps()->GetNames()[i], values[i]);
    }

    if (lastEnd == string::npos)
      // Check if we reached to the end of a message sent by the simulator.
      firstValue = 0;
    else
      // Else, increment the next index of value by the amount of values read.
      firstValue += valuesLength;
  }

  // Free the dynamically allocated arrays.
  free(reminder);
  free(values);
  free(buffer);

  container->ReleaseThread();
}


