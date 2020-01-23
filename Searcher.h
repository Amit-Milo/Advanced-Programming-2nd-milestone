//
// Created by amit on 22/01/2020.
//

#ifndef EX4__SEARCHER_H_
#define EX4__SEARCHER_H_

#include "Movement.h"
#include "Searchable.h"

class Searcher {
 public:
  /**
   * Search for the shortest path from start to end in a searchable object.
   * @param searchable the searchable object.
   * @return a list of movements to make in the searchable object in order to get the shortest path.
   */
  virtual list<Movement> search(Searchable& searchable) const = 0;
};

#endif //EX4__SEARCHER_H_
