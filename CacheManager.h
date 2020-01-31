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
/**
 * this is an interface that has the methods that a cache manager should handle.
 * @tparam T the type of data to handle
 */
template<class T>
class CacheManager {
 public:
  /**
   * save the solution for the input object to memory using the solver.
   * @param obj the object to save to memory
   * @param solution the solution to write
   */
  virtual void Save(T obj, string solution) = 0;
  /**
   * @param obj the object to check if we already have a solution to.
   * @return whether there is a solution already or not.
   */
  virtual bool IsAlreadySolved(T obj) = 0;
  /**
   * calculate the solution to a given problem
   * @param problem the problem to solve
   * @param solver the solver of the problem
   * @return the solution to the problem
   */
  virtual string Solution(T problem) = 0;

  /**
   * clone the cache manager
   */
  virtual CacheManager *clone() = 0;
};

#endif //EX4__CACHEMANAGER_H_