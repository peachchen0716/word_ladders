//
//  igraph.h
//  p5
//
//  Kyle C. Arthur C.
//

#include <vector>
#include <string>

using namespace std;

IGraph::IGraph(){}

~IGraph(){}

void IGraph::insert(string w){
  int pos = nodeList.size();
  GNode g = GNode(w);
  nodeList.push_back(g);
  indexMap[w] = pos;
}

void IGraph::bfs(string w){
   GNode g = nodeList[indexMap[w]];
   bfs(g);
}

void IGraph::bfs(GNode w){

}

bool IGraph::checkNeighbor(string w1, string w2){
  return true;
}

int IGraph::degree(GNode g){
  return g.neighbors.size();
}

int IGraph::eccentricity(GNode g){
  if (g.neighbors.size() == 0)  return 0;
  bfs(g);
  int res = 0;
  for (auto v : nodeList){
    res = max(res, v.d);
  }
  return res;
}
