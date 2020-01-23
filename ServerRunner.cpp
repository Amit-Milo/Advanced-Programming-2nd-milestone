//
// Created by yoav on 23/01/2020.
//

#include <unistd.h>
#include "ServerRunner.h"

//TODO DONE?
void ServerRunner::RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) {
  if (listen(s->GetServerSocket(), 1) == -1)
    // If can't listen, throw an error.
    throw "Couldn't listen.";

  int client_socket;

  //set socket timeout
  struct timeval tv;
  tv.tv_sec = TIME_OUT_SECONDS;
  setsockopt(s->GetServerSocket(), SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv));
  //accept client
  while ((client_socket = accept(s->GetServerSocket(),
                                 (struct sockaddr *) &s->GetServerAddress(),
                                 (socklen_t *) &s->GetServerAddress())) != -1) {
    client_handler->handleClient(s,client_socket);
  }
}





