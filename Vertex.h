//
// Created by amit on 22/01/2020.
//

#ifndef EX4__VERTEX_H_
#define EX4__VERTEX_H_


class Vertex {
  friend VertexFactory;

 protected:
  int _index;

  /**
   * A constructor.
   * @param index the index of the vertex.
   */
  Vertex(int index) : _index(index) { }
};

#endif //EX4__VERTEX_H_
