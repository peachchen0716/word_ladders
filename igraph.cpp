//
//  igraph.h
//  p5
//
//  Kyle C. Arthur C.
//

#include <iostream>
#include <queue>
#include "igraph.h"

using namespace std;

// Public
void IGraph::insert(const string w){
  int pos = nodeList.size();
  indexMap[w] = pos;

  wordList.push_back(w);
  color.push_back(false);
  d.push_back(numeric_limits<int>::max());
  pred.push_back(-1);

  //find corresponding edges
  vector<int> neighbors;
  for ( auto it = indexMap.begin(); it != indexMap.end(); ++it ){
    if (it->first == w)  continue;
    if (checkNeighbor(w, it->first)){
      int s = it->second;
      neighbors.push_back(s);
      nodeList[s].push_back(pos);
      numEdge++;
    }
  }
  nodeList.push_back(neighbors);
  numVertex++;
}

// Public
bool IGraph::contains(const string w){
  auto it = indexMap.find(w);
  return it != indexMap.end();
}

// Public
void IGraph::printNeighbor(const string w){
  for (auto i : nodeList[indexMap[w]]){
    cout << "\t\t" << wordList[i] << endl;
  }
}

// Public
void IGraph::getComponent(){
  int c = 0;
  int maxComponent = 0;
  int maxDegree = 0;
  for (int i=0; i<nodeList.size(); i++){
    int t = nodeList[i].size();
    maxDegree = max(maxDegree, t);
    //(color.size()==0) ||
    if ((!color[i])){
      //test
      //cout << "bfs on: " << wordList[i] << endl;
      //cout << "Num visited: " << temp << endl;
      maxComponent = max(bfs(i), maxComponent);
      c++;
    }
  }
  //set color back to default
  bfsReset();
  numComponent = c;
  largestComponent = maxComponent;
  largestDegree = maxDegree;
}

// Public
int IGraph::getDegree(const string w){
  int s = indexMap[w];
  return nodeList[s].size();
}

// Public
int IGraph::getEccentricity(const string w){
  bfs(w);
  int res = 0, index = 0;
  for (int i=0; i<nodeList.size(); i++){
    if (d[i] != numeric_limits<int>::max()){
      res = max(res, d[i]);
      if (res == d[i])
      index = i;
    }
  }
  //test
  //cout << "\tWord with longest distance: " << wordList[index] << endl;
  return res;
}

// Public
int IGraph::shortestPath(const string w1, const string w2){
  bfs(w1, w2);
  return d[indexMap[w2]];
}

// Public
void IGraph::printShortestPath(const string source, const string des){
  int path = shortestPath(source, des);
  if (path == numeric_limits<int>::max()){
    cout << "There is no path from " << source << " to " << des << endl;
  } else {
    cout << "\tThe path from " << source << " to " << des << " has "
    << path << " steps:" << endl;
    vector<int> path;
    int s1 = indexMap[source], s2 = indexMap[des];
    while (s2 != s1){
      path.push_back(s2);
      s2 = pred[s2];
    }
    path.push_back(s1);
    for (auto it = path.rbegin(); it != path.rend(); ++it){
      cout << "\t\t" << wordList[*it] << endl;
    }
  }
}

// Private
bool IGraph::checkNeighbor(const string w1, const string w2){
  if (w1.length()!=w2.length()) return false;
  int diff = 0;
  for (int i=0; i<w1.length(); i++){
    if (w1[i]!=w2[i]){
      if (++diff > 1) return false;
    }
  }
  return true;
}

// Private
void IGraph::bfs(const string w, const string target){
  bfsReset();
  //if no target given
  if (target == "")
  bfs(indexMap[w]);
  else
  bfs(indexMap[w], indexMap[target]);
}

// Private
// @return number of nodes visited during bfs
int IGraph::bfs(int s, int s2){

  d[s] = 0;
  queue<int> q;
  q.push(s);
  color[s] = true;

  int nodeVisted = 1;
  while (!q.empty()){
    int u = q.front();
    q.pop();
    for (auto v : nodeList[u]){
      if (color[v]==false){
        q.push(v);
        color[v] = true;
        d[v] = d[u]+1;
        pred[v] = u;
        nodeVisted++;
      }
      //if s2 exists, reach destination
      if ((s2!=-1) && v == s2){
        return nodeVisted;
      }
    }
  }
  return nodeVisted;
}

// Private
void IGraph::bfsReset(){
  for (int i=0; i<nodeList.size();i++){
    color[i] = false;
    d[i] = numeric_limits<int>::max();
    pred[i] = -1;
  }
}
