//
// Created by amit on 22/01/2020.
//

#ifndef EX4__SEARCHER_H_
#define EX4__SEARCHER_H_

#include "../Searchables/Searchable.h"

template <class Solution>
class Searcher {
 public:
  /**
   * Search for the shortest path from start to end in a searchable object.
   * @param searchable the searchable object.
   * @return a solution of the shortest path from start to end.
   */
  virtual Solution search(Searchable& searchable) const = 0;
};

#endif //EX4__SEARCHER_H_
