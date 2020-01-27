#include <iostream>

#include "BFS.h"
#include <stack>
#include "Vertex.h"
#include "GraphSearcher.h"
#include "MatrixGraphSearcher.h"
#include "MatrixGraph.h"
#include "Matrix.h"
#include "Point.h"
#include <list>
#include <queue>

int main() {
  queue<int> q;
  BFS b;
  MatrixGraphSearcher m = MatrixGraphSearcher(&b);

  int **arr = new int*[3];

  for (int i = 0; i < 3; i++)
    arr[i] = new int[3];

  for (int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      arr[i][j] = 1;

  Matrix<int> mat = Matrix<int>(arr, 3, 3);

  MatrixGraph graph = MatrixGraph(mat, Point(0, 0), Point(2, 2));


  list<Vertex> *l = m.search(graph);

  auto it = l->begin();

  while (it != l->end()) {
    cout << it->GetIndex() << endl;
    it++;
  }
  return 0;
}
