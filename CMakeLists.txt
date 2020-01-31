cmake_minimum_required(VERSION 3.15)

project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(ex4
        CacheManager.h
        ClientHandler.h
        FileCacheManager.h
        FileMatrixCacheManager.cpp FileMatrixCacheManager.h
        FileStringCacheManager.cpp FileStringCacheManager.h
        main.cpp
        ClientInputToMatrixConverter.cpp ClientInputToMatrixConverter.h
        MySerialServer.cpp MySerialServer.h
        MyTestClientHandler.cpp MyTestClientHandler.h
        Server.h
        SerialServerRunner.cpp SerialServerRunner.h
        ServerSocket.cpp ServerSocket.h
        Solver.h
        StringReverser.cpp StringReverser.h
        StringToFileNameConverter.cpp StringToFileNameConverter.h
        ToFileNameConverter.h
        ClientInputToProblemConverter.h ClientInputToStringConverter.cpp
        ClientInputToStringConverter.h
        MatrixToFileNameConverter.cpp MatrixToFileNameConverter.h
        MyClientHandler.cpp MyClientHandler.h
        ClientHandlerAbs.h
        MyParallelServer.cpp MyParallelServer.h
        ServerAbs.h
        ParallelServerRunner.cpp ParallelServerRunner.h
        ServerRunner.h

        Searcher.h Searchable.h
        Vertex.h Movement.h Point.cpp Point.h MatrixVertex.cpp MatrixVertex.h MatrixGraph.cpp MatrixGraph.h
        Cost.cpp Cost.h VertexAdapter.cpp VertexAdapter.h VertexFactory.h MatrixVertexFactory.cpp MatrixVertexFactory.h
        MatrixVertexCreator.cpp MatrixVertexCreator.h Matrix.h GraphSearcher.h MatrixGraphSearcher.h
        Vertex.cpp BFS.h BFS.cpp DFS.cpp DFS.h BestFirstSearch.h AStar.cpp AStar.h
        MatrixShortestPathSolver.h MatrixShortestPathSolver.cpp BestFirstSearch.cpp)
