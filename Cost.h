//
// Created by amit on 23/01/2020.
//

#ifndef EX4__COST_H_
#define EX4__COST_H_

#define INFINITY -1

class Cost {
  int _value;

 public:
  Cost(int value){
    this->_value = value;
  }

  int GetValue() const;

  friend bool operator==(const Cost &first, const Cost &second);

  friend bool operator!=(const Cost &first, const Cost &second);

  friend bool operator>(const Cost &first, const Cost &second);

  friend bool operator>=(const Cost &first, const Cost &second);

  friend bool operator<(const Cost &first, const Cost &second);

  friend bool operator<=(const Cost &first, const Cost &second);

  friend Cost operator+(const Cost &first, int second);

  friend Cost operator+(int first, const Cost &second);

  friend Cost operator+(const Cost &first, const Cost &second);
};

#endif //EX4__COST_H_
