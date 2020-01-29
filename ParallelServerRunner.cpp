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

    //handle the client in a new thread
    threads.emplace_back(std::thread(&server_side::ClientHandler::handleClient,
                                     client_handler,
                                     client_socket));
    threads.back().detach();

    //printf("disconnected from client!\n");
  }

  //now to finish off the run, join the threads here
  for (std::thread &th : threads) {
    // if thread is joinable then join.
    if (th.joinable())
      th.join();
  }

  //and close the time counting thread:
  if (t.joinable()) {
    t.join();
  }

  printf("out of the client loop, time out");
}
