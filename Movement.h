//
// Created by amit on 22/01/2020.
//

#ifndef EX4__MOVEMENT_H_
#define EX4__MOVEMENT_H_

#include "VerticesClasses/MatrixVerticesClasses/MatrixVertex.h"
#include "Movement.h"

typedef enum {UP, LEFT, RIGHT, DOWN} movement;

movement NextStep(const MatrixVertex *first, const MatrixVertex *second, int rowsNumber) {
  int first_index = first->GetIndex();
  int second_index = second->GetIndex();

  int iF = first_index/ rowsNumber;
  int iS = second_index / rowsNumber;

  int jF = first_index % rowsNumber;
  int jS = second_index % rowsNumber;

  return static_cast<movement>((iS > iF) * 3 + ((jS > jF) + 1) * (jS != jF));
}

#endif //EX4__MOVEMENT_H_
