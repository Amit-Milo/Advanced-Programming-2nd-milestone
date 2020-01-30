//
// Created by yoav on 28/01/2020.
//

#include "ParallelServerRunner.h"
void ParallelServerRunner::RunServer(ServerSocket *s, server_side::ClientHandler *client_handler) {
  printf("entered RunServer\n");
  //set the socket to be able to handle many clients queued
  if (listen(s->GetServerSocket(), 40) == -1)
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

  //save a vector of threads, to be able to command .join() on all of them at the end of the loop, so the
  //server closes only after it has finished handling all the client.
  std::vector<std::thread> threads;

  //save a vector of all the cloned client handlers to be able to delete it at the end.
  std::vector<server_side::ClientHandler *> client_handlers;

  //accept client
  printf("want to accept client\n");
  while (true) {
    //get another client
    client_socket =
        accept(s->GetServerSocket(), (struct sockaddr *) &s->GetServerAddress(), (socklen_t *) &s->GetServerAddress());
    //if time out, end the loop
    if (client_socket == -1) {
      break;
    }

    printf("connected to client!\n");

    server_side::ClientHandler *client_handler_copy = client_handler->clone();

    //handle the client in a new thread
    threads.emplace_back(std::thread(&server_side::ClientHandler::handleClient,
                                     client_handler_copy,
                                     client_socket));
    threads.back().detach();
    client_handlers.emplace_back(client_handler_copy);

    //printf("disconnected from client!\n");
  }

  //now to finish off the run, join the threads here
  for (std::thread &th : threads) {
    // if thread is joinable then join.
    if (th.joinable())
      th.join();
  }

  //and delete the client handler clones
  for (server_side::ClientHandler *c : client_handlers) {
    delete c;
  }

  //and close the time counting thread:
  if (t.joinable()) {
    t.join();
  }

  printf("out of the client loop, time out");
}
