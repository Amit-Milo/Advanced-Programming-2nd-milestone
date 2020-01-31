//
// Created by amit on 22/01/2020.
//

#include <algorithm>

#include "MatrixGraph.h"

Matrix<VertexAdapter> CostsToVertexes(const Matrix<int> &mat, MatrixVertexCreator &creator) {
  VertexAdapter **tempMat = new VertexAdapter *[mat.GetRows()];

  for (int i = 0; i < mat.GetRows(); ++i)
    tempMat[i] = (VertexAdapter *) malloc(sizeof(VertexAdapter) * mat.GetColumns());

  for (int i = 0; i < mat.GetRows(); ++i)
    for (int j = 0; j < mat.GetColumns(); ++j)
      tempMat[i][j] = VertexAdapter(creator.create(i, j, mat.GetRows()), Cost(*mat.Get(i, j)));

  Matrix<VertexAdapter> _mat = Matrix<VertexAdapter>(tempMat, mat.GetRows(), mat.GetColumns());

  return _mat;
}

MatrixGraph::MatrixGraph(const Matrix<int> &mat, const Point &start, const Point &end)
    : _creator(MatrixVertexCreator()),
      _start(this->_creator.create(start, mat.GetRows())), _end(this->_creator.create(end, mat.GetRows())),
      _mat(CostsToVertexes(mat, this->_creator)), hash_val(this->_hash()) {
  auto startVertex = this->_mat.Get(0, 0);
  startVertex->SetPathLength(*startVertex->GetCost());
  _opened_nodes_counter = 0;
}

const MatrixVertex *MatrixGraph::GetStart() const {
  return &this->_start;
}

const MatrixVertex *MatrixGraph::GetEnd() const {
  return &this->_end;
}

list<Vertex> *MatrixGraph::GetNeighbors(const Vertex &v) {
  auto neighbors = new list<Vertex>;

  int i = v.GetIndex() / this->_mat.GetRows();
  int j = v.GetIndex() % this->_mat.GetRows();

  // Add cell left to current.
  if (i > 0) neighbors->push_front(this->_creator.create(i - 1, j, this->_mat.GetRows()));

  // Add cell right to current.
  if (i < this->_mat.GetRows() - 1) neighbors->push_front(this->_creator.create(i + 1, j, this->_mat.GetRows()));

  // Add cell above current.
  if (j > 0) neighbors->push_front(this->_creator.create(i, j - 1, this->_mat.GetRows()));

  // Add cell below current.
  if (j < this->_mat.GetRows() - 1) neighbors->push_front(this->_creator.create(i, j + 1, this->_mat.GetRows()));

  return neighbors;
}

void MatrixGraph::Visit(const Vertex &v) const {
  int index = v.GetIndex();
  int i = index / this->_mat.GetRows();
  int j = index % this->_mat.GetRows();

  this->_mat.Get(i, j)->travel();
}

bool MatrixGraph::IsVisited(const Vertex &v) const {
  int index = v.GetIndex();
  int i = index / this->_mat.GetRows();
  int j = index % this->_mat.GetRows();

  auto temp = this->_mat.Get(i, j);
  return temp->isTraveled();
}

void MatrixGraph::UpdateVertex(const Vertex &v, const Vertex &p) const {
  int vIndex = v.GetIndex();
  int vi = vIndex / this->_mat.GetRows();
  int vj = vIndex % this->_mat.GetRows();

  int pIndex = p.GetIndex();
  int pi = pIndex / this->_mat.GetRows();
  int pj = pIndex % this->_mat.GetRows();

  auto vAdapter = this->_mat.Get(vi, vj);
  auto pAdapter = this->_mat.Get(pi, pj);

  if (vAdapter->GetPathLength() > pAdapter->GetPathLength() + *vAdapter->GetCost()) {
    vAdapter->SetParent(*pAdapter);
  }
}

const Vertex *MatrixGraph::GetParent(const Vertex &v) const {
  int index = v.GetIndex();
  int i = index / this->_mat.GetRows();
  int j = index % this->_mat.GetRows();

  return this->_mat.Get(i, j)->GetParent();
}

Cost MatrixGraph::distance(const Vertex &src, const Vertex &dst) const {
  int srcIndex = src.GetIndex();
  int srcI = srcIndex / this->_mat.GetRows();
  int srcJ = srcIndex % this->_mat.GetRows();

  int dstIndex = dst.GetIndex();
  int dstI = dstIndex / this->_mat.GetRows();
  int dstJ = dstIndex % this->_mat.GetRows();

  return Cost(abs(dstI - srcI) + abs(dstJ - srcJ));
}

Cost MatrixGraph::currentPathLength(const Vertex &v) const {
  int index = v.GetIndex();
  int i = index / this->_mat.GetRows();
  int j = index % this->_mat.GetRows();

  return this->_mat.Get(i, j)->GetPathLength();
}

Cost MatrixGraph::GetCost(const Vertex &v) const {
  int index = v.GetIndex();
  int i = index / this->_mat.GetRows();
  int j = index % this->_mat.GetRows();

  return *this->_mat.Get(i, j)->GetCost();
}

int MatrixGraph::GetRows() const {
  return this->_mat.GetRows();
}

size_t MatrixGraph::hash() {
  return this->hash_val;
}

std::size_t MatrixGraph::_hash() {
  size_t result = 0;
  result += _start.hash();
  result += _end.hash();
  result += _mat.hash();
  return result;
}
