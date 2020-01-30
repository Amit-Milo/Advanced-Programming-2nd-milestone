//
// Created by yoav on 23/01/2020.
//

#ifndef EX4__SERVERSOCKET_H_
#define EX4__SERVERSOCKET_H_

#include <netinet/in.h>
#include <thread>

/**
 * this is a class that holds a server socket's important data.
 */
class ServerSocket {
 private:
  //socket of the server
  int server_socket;
  //address struct of the socket
  sockaddr_in server_address;

 public:
  ServerSocket(int port);
  virtual ~ServerSocket();
  void BindServer();
  /**
   * a getter for the socket.
   */
  int GetServerSocket() const;
  /**
   * a getter for the port.
   */
  int GetServerPort() const;
  /**
   * a getter for the socket struct.
   */
  const sockaddr_in &GetServerAddress() const;
};

#endif //EX4__SERVERSOCKET_H_