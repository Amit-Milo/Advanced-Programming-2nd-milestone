//
// Created by amit on 22/01/2020.
//

#ifndef EX4__POINT_H_
#define EX4__POINT_H_

class Point {
  int _i, _j;

 public:
  /**
   * A constructor.
   * @param i the row of the point.
   * @param j the column of the point.
   */
  Point(int i, int j) : _i(i), _j(j) { }

  /**
   * A getter for the i value.
   * @return i value.
   */
  int GetI() const;


  /**
   * A getter for the j value.
   * @return j value.
   */
  int GetJ() const;
};

#endif //EX4__POINT_H_
