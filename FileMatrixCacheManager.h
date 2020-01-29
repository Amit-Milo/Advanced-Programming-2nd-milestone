//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__FILEMATRIXCACHEMANAGER_H_
#define EX4__FILEMATRIXCACHEMANAGER_H_


#include "FileCacheManager.h"
#include "MatrixToFileNameConverter.h"


class FileMatrixCacheManager : FileCacheManager<MatrixGraph> {
 public:
  FileMatrixCacheManager();
};

#endif //EX4__FILEMATRIXCACHEMANAGER_H_
