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
  int capacity; //bounds the size of the cache
  /**
   * saves the cache with O(1) time, each object keeps a =n iterator to itself in the LRU list
   */
  unordered_map<string, pair<T, list<string>::iterator>> cache;
  /**
   * keeps track of the LRU process. will always be the size of cache.
   */
  list<string> keysLRU;
 public:
  CacheManager(int _capacity) : capacity(_capacity), cache(), keysLRU() {}
  void insert(string key, T obj) {
    int keysLRU_size = (int) keysLRU.size();
    if (keysLRU_size > capacity) {
      throw "error in capacity limit, cache is too big";
    }
    ///add to the files
    ofstream objFile;
    objFile.open(key + " from " + obj.class_name, ios::binary | ofstream::trunc); //override what is already written
    if (!objFile.is_open()) {
      throw "problem opening file" + key + ", could not open file from memory";
    }
    objFile.write((char *) &obj, sizeof(obj));
    objFile.close();

    ///now the obj is in files properly. now handle the cache memory
    if (cache.count(key) == 1) { //value is already in the cache, just need to update the value
      moveToFrontOfCache(key);
      cache.at(key).first = obj;
    } else { //need to insert new value to the cache
      keysLRU_size = (int) keysLRU.size();
      if (keysLRU_size < capacity) {
        keysLRU.push_front(key);
        cache.insert({key, pair<T, list<string>::iterator>(obj, keysLRU.begin())});
      } else { //keysLRU.size=capacity
        //first remove the least recently used value
        string last = keysLRU.back();
        keysLRU.pop_back(); //remove from the back of the LRU list
        cache.erase(last); //remove from the cache

        //now insert the new value
        keysLRU.push_front(key);
        cache.insert({key, pair<T, list<string>::iterator>(obj, keysLRU.begin())});
      }
    }
  }
  T get(string key) {
    //first check if the key is in the cache, O(1)
    if (cache.count(key) == 1) {
      moveToFrontOfCache(key);
      return cache.at(key).first;
    }
    //else, get if from the files
    ifstream objFile;
    objFile.open(key + " from " + T::class_name, ios::binary);
    if (!objFile.is_open()) {
      throw "an error";
    }
    //read the obj from file
    T obj;
    objFile.read((char *) &obj, sizeof(obj));
    objFile.close();
    //insert to cache before returning
    insert(key, obj);
    return obj;
  }
  void foreach(const function<void(T &)> func) {
    for (auto &p: keysLRU) {
      func(cache.at(p).first);
    }
  }
  void moveToFrontOfCache(string key) {
    keysLRU.erase(cache.at(key).second);
    keysLRU.push_front(key);
    cache.at(key).second = prev(keysLRU.end());
  }
};

#endif //EX4__CACHEMANAGER_H_
