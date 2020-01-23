cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(ex4 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h StringReverser.cpp StringReverser.h Searcher.h Searchable.h Vertex.h ConstMatrix.h Movement.h Point.cpp Point.h MatrixVertex.cpp MatrixVertex.h MatrixGraph.cpp MatrixGraph.h Cost.cpp Cost.h VertexAdapter.cpp VertexAdapter.h VertexFactory.h MatrixVertexFactory.cpp MatrixVertexFactory.h MatrixVertexCreator.cpp MatrixVertexCreator.h ServerRunner.cpp ServerRunner.h ServerSocket.cpp ServerSocket.h)