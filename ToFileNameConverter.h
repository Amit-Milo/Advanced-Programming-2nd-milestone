//
// Created by yoav on 25/01/2020.
//

#ifndef EX4__TOFILENAMECONVERTER_H_
#define EX4__TOFILENAMECONVERTER_H_

#include <string>

using namespace std;
/**
 * this is an interface that has a method that its role is to convert a given object to a file name
 * @tparam T the type of the given object ot convert
 */
template<class T>
class ToFileNameConverter {
 public:
  /**
   * convert the input object to a file name so we can save and find the object in files, using hash
   * @param objToConvert the object to convert
   * @return the file name that represents the object
   */
  virtual string Convert(T objToConvert) = 0;
};

#endif //EX4__TOFILENAMECONVERTER_H_
