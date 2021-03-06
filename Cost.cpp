//
// Created by amit on 23/01/2020.
//

#include "Cost.h"

int Cost::GetValue() const {
  return this->_value;
}

bool operator==(const Cost &first, const Cost &second) {
  return first >= second && second >= first;
}


bool operator!=(const Cost &first, const Cost &second) {
  return !(first == second);
}


bool operator>=(const Cost &first, const Cost &second) {
  if (first.GetValue() == INFINITY) return true;

  if (second.GetValue() == INFINITY) return false; // Notice that first._value != INFINITY

  return first.GetValue() >= second.GetValue();
}


bool operator>(const Cost &first, const Cost &second) {
  return first >= second && first != second;
}


bool operator<=(const Cost &first, const Cost &second) {
  return second >= first;
}


bool operator<(const Cost &first, const Cost &second) {
  return first <= second && first != second;
}


Cost operator+(const Cost &first, int second) {
  return first + Cost(second);
}


Cost operator+(int &first, const Cost &second) {
  return second + first;
}

Cost operator+(const Cost &first, const Cost &second) {
  if (first.GetValue() == INFINITY || second.GetValue() == INFINITY) return Cost(INFINITY);
  return Cost(first.GetValue() + second.GetValue());
}
