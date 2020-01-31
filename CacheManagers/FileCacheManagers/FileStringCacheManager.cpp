//
// Created by yoav on 25/01/2020.
//

#include "FileStringCacheManager.h"

FileStringCacheManager::FileStringCacheManager() {
  converter = new StringToFileNameConverter();
}
CacheManager<string> *FileStringCacheManager::clone() {
  return new FileStringCacheManager();
}
