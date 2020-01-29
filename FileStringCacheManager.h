//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__FILESTRINGCACHEMANAGER_H_
#define EX4__FILESTRINGCACHEMANAGER_H_

#include <string>
#include "FileCacheManager.h"
#include "StringToFileNameConverter.h"

using namespace std;

class FileStringCacheManager : public FileCacheManager<string> {
 public:
  FileStringCacheManager();
};

#endif //EX4__FILESTRINGCACHEMANAGER_H_
