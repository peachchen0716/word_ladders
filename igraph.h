//
//  igraph.h
//  p5
//
//  Kyle C. Arthur C.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class IGraph{

public:
  IGraph (){};
  ~IGraph (){};

  vector<GNode> nodeList;
  unordered_map<string, int> indexMap;
  void insert(string){};
  void bfs(string){};

private:
  class GNode{
  public:
    GNode(string w) :
      word(w),
      color(false),
      d(numeric_limits<int>::max()),
      pre(NULL)
      {};

    string word;
    bool color;
    int d;
    GNode pre;
    vector<GNode> neighbors;
  }
  //check whether string has one different char than this
  bool checkNeighbor(string){};
  void bfs(GNode){};
  int degree(GNode){};
}
