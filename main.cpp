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
#include <stack>
#include "DFS.h"
#include "AStar.h"
#include "BestFirstSearch.h"
#include "MatrixShortestPathSolver.h"

int main() {
  queue<int> q;
  BFS b;
  DFS d;
  AStar a;
  BestFirstSearch bf;
  MatrixGraphSearcher m = MatrixGraphSearcher(&bf);

  int **arr = new int*[3];

  for (int i = 0; i < 3; i++)
    arr[i] = new int[3];

  for (int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if (i == 0)
        arr[i][j] = 3;
      else if (i == 1)
        arr[i][j] = 2;
      else
        arr[i][j] = 1;

  Matrix<int> mat = Matrix<int>(arr, 3, 3);

  MatrixGraph graph = MatrixGraph(mat, Point(0, 0), Point(2, 2));

  MatrixShortestPathSolver msps = MatrixShortestPathSolver(m);
  list<string> l = msps.solve(graph);
  ///list<Vertex> *l = m.search(graph);

  auto it = l.begin();

  while (it != l.end()) {
    cout << *it << endl;
    it++;
  }
  return 0;
}
