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
#include "Solver.h"

using namespace std;
template<class T>
class CacheManager {
 public:
  virtual void Save(T obj, Solver<T,string> *solver)=0;
  virtual bool IsAlreadySolved(T obj)=0;
  virtual string Solution(T problem, Solver<T,string> *solver)=0;
};

#endif //EX4__CACHEMANAGER_H_