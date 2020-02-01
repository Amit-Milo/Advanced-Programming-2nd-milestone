cmake_minimum_required(VERSION 3.15)

project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(ex4
        CacheManagers/CacheManager.h
        ClientHandlers/ClientHandler.h
        CacheManagers/FileCacheManagers/FileCacheManager.h
        CacheManagers/FileCacheManagers/FileMatrixCacheManager.cpp CacheManagers/FileCacheManagers/FileMatrixCacheManager.h
        CacheManagers/FileCacheManagers/FileStringCacheManager.cpp CacheManagers/FileCacheManagers/FileStringCacheManager.h
        main.cpp
        ClientInputInterpreters/ClientInputToMatrixConverter.cpp ClientInputInterpreters/ClientInputToMatrixConverter.h
        Servers/MySerialServer.cpp Servers/MySerialServer.h
        ClientHandlers/MyTestClientHandler.cpp ClientHandlers/MyTestClientHandler.h
        Servers/Server.h
        ServerRunners/SerialServerRunner.cpp ServerRunners/SerialServerRunner.h
        ServerSocket.cpp ServerSocket.h
        Solvers/Solver.h
        Solvers/StringReverser.cpp Solvers/StringReverser.h
        ProblemsToFileNamesConverters/StringToFileNameConverter.cpp ProblemsToFileNamesConverters/StringToFileNameConverter.h
        ProblemsToFileNamesConverters/ToFileNameConverter.h
        ClientInputInterpreters/ClientInputToProblemConverter.h ClientInputInterpreters/ClientInputToStringConverter.cpp
        ClientInputInterpreters/ClientInputToStringConverter.h
        ProblemsToFileNamesConverters/MatrixToFileNameConverter.cpp ProblemsToFileNamesConverters/MatrixToFileNameConverter.h
        ClientHandlers/MyClientHandler.cpp ClientHandlers/MyClientHandler.h
        ClientHandlers/ClientHandlerAbs.h
        Servers/MyParallelServer.cpp Servers/MyParallelServer.h
        Servers/ServerAbs.h
        ServerRunners/ParallelServerRunner.cpp ServerRunners/ParallelServerRunner.h
        ServerRunners/ServerRunner.h

        Searchers/Searcher.h Searchables/Searchable.h
        VerticesClasses/Vertex.h Movement.h Point.cpp Point.h VerticesClasses/MatrixVerticesClasses/MatrixVertex.cpp VerticesClasses/MatrixVerticesClasses/MatrixVertex.h Searchables/MatrixGraph.cpp Searchables/MatrixGraph.h
        Cost.cpp Cost.h VerticesClasses/VertexAdapter.cpp VerticesClasses/VertexAdapter.h VerticesClasses/VertexFactory.h VerticesClasses/MatrixVerticesClasses/MatrixVertexFactory.cpp VerticesClasses/MatrixVerticesClasses/MatrixVertexFactory.h
        VerticesClasses/MatrixVerticesClasses/MatrixVertexCreator.cpp VerticesClasses/MatrixVerticesClasses/MatrixVertexCreator.h Matrix.h Searchers/GraphSearchers/GraphSearcher.h Searchers/GraphSearchers/MatrixGraphSearcher.h
        VerticesClasses/Vertex.cpp Searchers/GraphSearchers/BFS.h Searchers/GraphSearchers/BFS.cpp Searchers/GraphSearchers/DFS.cpp Searchers/GraphSearchers/DFS.h Searchers/GraphSearchers/BestFirstSearch.h Searchers/GraphSearchers/AStar.cpp Searchers/GraphSearchers/AStar.h
        Solvers/MatrixShortestPathSolver.h Solvers/MatrixShortestPathSolver.cpp Searchers/GraphSearchers/BestFirstSearch.cpp)
