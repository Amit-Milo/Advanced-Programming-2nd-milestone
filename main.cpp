#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

int main(int argc, char *argv[]) {
  int port_number;
  if (argc<=1){
    port_number=5600;
  } else{
    port_number = atoi(argv[1]);
  }
  MySerialServer serialServer;
  MyTestClientHandler* clientHandler = new MyTestClientHandler;
  Solver<string,string>* solver;
  CacheManager<string>* cache_manager;


  serialServer.start(port_number,clientHandler);

  serialServer.stop();


}
