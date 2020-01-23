//
// Created by yoav on 23/01/2020.
//

#include <unistd.h>
#include "ServerSocket.h"
#include "ServerRunner.h"

ServerSocket::ServerSocket(int port_number) {
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  //check if socket allocated successfully
  if (server_socket == -1) {
    throw "Couldn't allocate socket.";
  }
  // Address family.
  server_address.sin_family = AF_INET;

  // Equivalent to 0.0.0.0
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Set port to listen on.
  server_address.sin_port = htons(port_number);
}

ServerSocket::~ServerSocket() {
  //TODO make sure we need both read and write
  //shut down for read and write
  shutdown(this->server_socket, SHUT_RD);
  shutdown(this->server_socket, SHUT_WR);
  // Close the socket.
  close(this->server_socket);
}

void ServerSocket::BindServer() {
  // Try to bind server.
  if (bind(server_socket, (struct sockaddr *) &(server_address), sizeof(server_address)) != -1) {
    // Run server in a new thread.
    ServerRunner *s = new ServerRunner();
    //TODO decide where to start the thread
    //std::thread(&ServerRunner::RunServer, s, this);
  } else {
    throw "Couldn't bind server.";
  }
}

int ServerSocket::GetServerSocket() const {
  return server_socket;
}
int ServerSocket::GetServerPort() const {
  return server_address.sin_port;
}



