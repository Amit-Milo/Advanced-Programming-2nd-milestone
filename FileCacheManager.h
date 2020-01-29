//
// Created by yoav on 24/01/2020.
//

#ifndef EX4__FILECACHEMANAGER_H_
#define EX4__FILECACHEMANAGER_H_



#include "CacheManager.h"
#include "ToFileNameConverter.h"
#include "Solver.h"
#include <fstream>
#include <iostream>

template<class T>
class FileCacheManager : public CacheManager<T> {
 protected:
  //use this to first check in O(1) time if the solution was already calculated during this run.
  unordered_map<T, string> files_names;
  ToFileNameConverter<T> *converter;
 public:
  FileCacheManager() {}

  virtual ~FileCacheManager() {
    delete converter;
  }

  void Save(T obj, Solver<T,string> *solver) override {
    cout << "saving obj to file" << endl;
    string new_file_name = converter->Convert(obj);
    ofstream solution_file;
    solution_file.open(new_file_name.c_str());
    if (solution_file.is_open()) {
      string solution = solver->solve(obj);
      cout << "solved the problem, solution: " << solution << endl;
      solution_file << solution;
    } else {
      throw "could not open file";
    }
    solution_file.close();
  }

  bool IsAlreadySolved(T obj) override {
    cout << "checking if already solved... first check the map" << endl;
    //first check if it is in the current run's map
    if (files_names.count(obj)) {
      return true;
    }
    cout << "not in map. check the files" << endl;
    //now check if the file exists but just from the previous runs
    ifstream saved_file(converter->Convert(obj));
    if (saved_file.is_open()) {
      return true;
    }
    cout << "not in files. need to calculate" << endl;
    //else, we know that the file does not exist. so we should return false, as it was not solved yet.
    return false;
  }

  string Solution(T problem, Solver<T,string> *solver) override {
    cout << "want to return solution" << endl;
    if (IsAlreadySolved(problem)) {
      cout << "already have a solution" << endl;
      return WholeFileContent(converter->Convert(problem));
    }
    //else, calculate the solution
    cout << "need to calculate the solution" << endl;
    files_names.insert({problem, converter->Convert(problem)});
    Save(problem, solver);
    return WholeFileContent(files_names[problem]);
  }

  string WholeFileContent(string file_name) {
    ifstream file;
    file.open(file_name);
    if (!file.is_open()) {
      throw "could not open the file";
    }
    //concat the whole file content line by line
    std::string line;
    std::string file_contents;
    while (std::getline(file, line)) {
      file_contents += line;
      file_contents.push_back('\n');
    }
    return line;
  }
};

#endif //EX4__FILECACHEMANAGER_H_

