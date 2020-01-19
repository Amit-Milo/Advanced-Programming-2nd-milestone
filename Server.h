//
// Created by yoav on 19/01/2020.
//

#ifndef EX4_SERVER_SIDE_SERVER_H_
#define EX4_SERVER_SIDE_SERVER_H_


class Server{
 public:
  /**
   * should open the server and wait for clients.
   * @param port the port number to open the server on.
   */
  virtual void open(int port)=0;
  /**
   * should close he server.
   */
  virtual void stop()=0;
};


#endif //EX4_SERVER_SIDE_SERVER_H_
