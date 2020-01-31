//
// Created by amit on 22/01/2020.
//

#include "StringReverser.h"


string StringReverser::solve(string p) {
  string result;

  int length = p.length();
  int lastIndex = length - 1;

  for (int i = 0; i < length; ++i) {
    // Copy next char from the corresponding place from the end.
    result+=(p[lastIndex - i]);
  }

  return result;
}
Solver<string, string> *StringReverser::clone() {
  return new StringReverser();
}
