//
//wordladder.cpp
//
//Kyle C. Arthur C.
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "igraph.h"

using namespace std;
void command(string, IGraph);
int L;

int main(){
  //read in file
  string fileName;
  cout << "Enter file name with the words: ";
  cin >> fileName;
  ifstream in;
  in.open(fileName);
  if (in.fail()) {
    cerr << "Error: Cannot open " << fileName << endl;
    return -1;
  }
  //insert into graph
  IGraph g;
  int numWord = 0;
  string word;
  while (in >> word){
    g.insert(word);
    numWord++;
  }
  L = word.length();
  //print summary
  cout << "\n\tNumber of vertices: " << g.numVertex << endl;
  cout << "\tNumber of edges: " << g.numEdge << endl;
  g.getComponent();
  cout << "\tNumber of components: " << g.numComponent << endl;
  cout << "\tLargest component: " << g.largestComponent << endl;
  cout << "\tLargest degree: " << g.largestDegree << endl;

  //command
  string option = "";
  while (option != "q"){
    cout << "\nCommand (d/i/q)? ";
    cin >> option;
    command(option, g);
  }
  cout << "\nThank you for playing!" << endl;
  return 0;
}

void command(string option, IGraph g){
  if (option == "i")
  {
    string w;
    //need to change
    cout << "\nEnter source word (" << L << " letters): ";
    cin >> w;
    //change word to lower case
    transform(w.begin(), w.end(), w.begin(),(int (*)(int))tolower);
    //check whether the word is contained in graph
    if (!g.contains(w)){
      cout << w << " not found in the graph." << endl;
      return;
    }
    cout << "\n\tDegree of " << w << ": " << g.getDegree(w) << endl;
    cout << "\tNeighborhood of " << w << endl;
    g.printNeighbor(w);
    cout << "\tEccentricity of " << w << ": " << g.getEccentricity(w) << endl;
  }
  else if (option == "d")
  {
    string source, des;
    cout << "\nEnter source word: ";
    cin >> source;
    cout << "\nEnter destination word: ";
    cin >> des;
    //check whether words are contained in graph
    if (!g.contains(source)){
      cout << source << " not found in the graph." << endl;
      return;
    }
    if (!g.contains(des)){
      cout << des << " not found in the graph." << endl;
      return;
    }
    //change word to lower case
    transform(source.begin(), source.end(), source.begin(),(int (*)(int))tolower);
    transform(des.begin(), des.end(), des.begin(),(int (*)(int))tolower);
    g.printShortestPath(source, des);
  }
  else if (option != "q")    cout << "\nPlease enter d/i/q" << endl;
}
