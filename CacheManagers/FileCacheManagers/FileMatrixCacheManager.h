//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__FILEMATRIXCACHEMANAGER_H_
#define EX4__FILEMATRIXCACHEMANAGER_H_


#include "FileCacheManager.h"
#include "../../ProblemsToFileNamesConverters/MatrixToFileNameConverter.h"
#include "../../Searchables/MatrixGraph.h"

/**
 * handles a file cache memory for matrix graph.
 */
class FileMatrixCacheManager : public FileCacheManager<MatrixGraph>{
 public:
  FileMatrixCacheManager();
  CacheManager<MatrixGraph> *clone() override;
};

#endif //EX4__FILEMATRIXCACHEMANAGER_H_
