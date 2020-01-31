//
// Created by yoav on 25/01/2020.
//

#include "FileMatrixCacheManager.h"

FileMatrixCacheManager::FileMatrixCacheManager() {
  converter = new MatrixToFileNameConverter();
}
CacheManager<MatrixGraph> *FileMatrixCacheManager::clone() {
  return new FileMatrixCacheManager();
}
