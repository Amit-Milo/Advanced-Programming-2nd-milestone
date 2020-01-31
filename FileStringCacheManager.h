//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__FILESTRINGCACHEMANAGER_H_
#define EX4__FILESTRINGCACHEMANAGER_H_

#include <string>
#include "FileCacheManager.h"
#include "StringToFileNameConverter.h"

using namespace std;

/**
 * handles a file cache memory for strings.
 */
class FileStringCacheManager : public FileCacheManager<string> {
 public:
  FileStringCacheManager();
  CacheManager<string> *clone() override;
};

#endif //EX4__FILESTRINGCACHEMANAGER_H_
