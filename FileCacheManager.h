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

/**
 * this class handles a file cache manager - saving the data to files
 * @tparam T the data type to save to files
 */
template<class T>
class FileCacheManager : public CacheManager<T> {
 protected:
  ToFileNameConverter<T> *converter;
 public:
  FileCacheManager() {}

  virtual ~FileCacheManager() {
    delete converter;
  }

  void Save(T obj, Solver<T, string> *solver) override {
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
    cout << "checking the files if already solved...." << endl;
    //check if the file already exists
    ifstream saved_file(converter->Convert(obj));
    if (saved_file.is_open()) {
      return true;
    }
    cout << "not in files. need to calculate" << endl;
    //else, we know that the file does not exist. so we should return false, as it was not solved yet.
    return false;
  }

  string Solution(T problem, Solver<T, string> *solver) override {
    cout << "want to return solution" << endl;
    if (IsAlreadySolved(problem)) {
      cout << "already have a solution" << endl;
      return WholeFileContent(converter->Convert(problem));
    }
    //else, calculate the solution
    cout << "need to calculate the solution" << endl;
    Save(problem, solver);
    return WholeFileContent(converter->Convert(problem));
  }

  /**
   * @param file_name the file to read
   * @return the whole file content
   */
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

