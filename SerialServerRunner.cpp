//
// Created by yoav on 23/01/2020.
//

#include <unistd.h>
#include "ServerSocket.h"
#include "SerialServerRunner.h"
#include <thread>

void SerialServerRunner::RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) {
  printf("entered RunServer\n");
  if (listen(s->GetServerSocket(), 1) == -1)
    // If can't listen, throw an error.
    throw "Couldn't listen.";

  int client_socket;

  //set socket timeout
  struct timeval tv;
  tv.tv_sec = TIME_OUT_SECONDS;
  tv.tv_usec = 0;
  setsockopt(s->GetServerSocket(), SOL_SOCKET, SO_RCVTIMEO, (char *) &tv, sizeof(tv));

  printf("want to start thread\n");
  //TODO make remove this.
  std::thread t(printSecond);
  t.detach();

  //accept client
  printf("want to accept client\n");
  while ((client_socket =
              accept(s->GetServerSocket(),
                     (struct sockaddr *) &s->GetServerAddress(),
                     (socklen_t *) &s->GetServerAddress())) != -1) {
    printf("connected to client!\n");

    client_handler->handleClient(client_socket);

    printf("disconnected from client!\n");
  }

  printf("out of the client loop, time out");

}

