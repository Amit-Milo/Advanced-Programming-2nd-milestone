//
// Created by amit on 22/01/2020.
//

#ifndef EX4__VERTEX_H_
#define EX4__VERTEX_H_

#include <string>

class Vertex {
  friend class VertexFactory;

  int _index;

 protected:
  /**
   * A constructor.
   * @param index the index of the vertex.
   */
  Vertex(int index) : _index(index) { }

 public:
  int GetIndex() const {
    return this->_index;
  }

  /**
   * Define comparison between two matrix vertexes. Comparison is declared by comparison of the indexes.
   * @param first the first vertex.
   * @param second the second vertex.
   * @return true if the indexes of the vertexes are equal, false otherwise.
   */
  friend bool operator==(const Vertex &first, const Vertex &second);

  /**
   * Define inequality between two matrix vertexes.
   * @param first the first vertex.
   * @param second the second vertex.
   * @return true if the vertexes are unequal, false otherwise.
   */
  friend bool operator!=(const Vertex &first, const Vertex &second);


  size_t hash() const;
};

#endif //EX4__VERTEX_H_
