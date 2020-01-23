//
// Created by yoav on 23/01/2020.
//

#ifndef EX4__SERVERSOCKET_H_
#define EX4__SERVERSOCKET_H_

#include <netinet/in.h>
#include <thread>


class ServerSocket{
 private:
  //socket of the server
  int server_socket;
  //address struct of the socket
  sockaddr_in server_address;

 public:
  ServerSocket(int port);
  virtual ~ServerSocket();
  void BindServer();

  int GetServerSocket() const;
  int GetServerPort() const;
  const sockaddr_in &GetServerAddress() const;
};

#endif //EX4__SERVERSOCKET_H_
