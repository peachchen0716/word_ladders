//
//  igraph.h
//  p5
//
//  Kyle C. Arthur C.
//
#ifndef igraph_h
#define igraph_h

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class IGraph{
public:
  int numVertex, numEdge;
  int numComponent, largestComponent, largestDegree;

  IGraph() :
  numVertex(0),numEdge(0),
  numComponent(0),largestComponent(0),largestDegree(0){};

  ~IGraph(){};

  void insert(const string);
  bool contains(const string);
  void printNeighbor(const string);
  //calculate number of components
  void getComponent();
  int getDegree(const string);
  int getEccentricity(const string);

  //stop searching as soon as it find the path
  int shortestPath(const string, const string);
  void printShortestPath(const string, const string);
private:
  //adjacency list
  vector<vector<int> > nodeList;
  //map string into its index in the nodeList
  unordered_map<string, int> indexMap;
  //keep track of all words
  vector<string> wordList;
  vector<bool> color;
  vector<int> d;
  vector<int> pred;

  //check whether string has one different char than this
  bool checkNeighbor(const string, const string);
  void bfs(const string w, const string target = "");
  //return number of nodes visited during bfs
  int bfs(int s1, int s2 = -1);
  void bfsReset();
};

#endif /* igraph_h */
