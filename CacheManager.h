//
// Created by yoav on 20/01/2020.
//

#ifndef EX4__CACHEMANAGER_H_
#define EX4__CACHEMANAGER_H_

#include <string>
#include <unordered_map>
#include <list>
#include <set>
#include <functional>
#include <fstream>

using namespace std;
//TODO this is Yoav's cache manager
template<class T>
class CacheManager {
 public:
  virtual void insert(string key, T obj) = 0;
  virtual T get(string key) = 0;
  virtual void foreach(const function<void(T &)> func) = 0;
  virtual void moveToFrontOfCache(string key) = 0;
};

#endif //EX4__CACHEMANAGER_H_
