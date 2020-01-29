cmake_minimum_required(VERSION 3.15)
project(advancedProgrammingMilestone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(advancedProgrammingMilestone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h StringReverser.cpp StringReverser.h Searcher.h Searchable.h Vertex.h Movement.h Point.cpp Point.h MatrixVertex.cpp MatrixVertex.h MatrixGraph.cpp MatrixGraph.h Cost.cpp Cost.h VertexAdapter.cpp VertexAdapter.h VertexFactory.h MatrixVertexFactory.cpp MatrixVertexFactory.h MatrixVertexCreator.cpp MatrixVertexCreator.h Matrix.h GraphSearcher.h MatrixGraphSearcher.h Vertex.cpp BFS.h BFS.cpp DFS.cpp DFS.h)