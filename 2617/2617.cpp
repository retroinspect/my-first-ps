// 구슬 찾기
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int MAX_INPUT_NUM = 101;
int N; // number of vertices
int M; // number of edges
int threshold;
bool graph[MAX_INPUT_NUM][MAX_INPUT_NUM];
bool visited[MAX_INPUT_NUM];

int desc[MAX_INPUT_NUM];
int asc[MAX_INPUT_NUM];

void initVisited()
{
  for (int i=1; i<=N; i++)
    visited[i] = false;
}

void visit(int node)
{
  visited[node] = true;
}

bool isVisited(int node)
{
  return visited[node];
}

vector<int> getChildren(int node)
{
  vector<int> children;
  for (int i = 1; i <= N; i++)
  {
    if (graph[node][i]) children.push_back(i);
  }

  return children;
}

vector<int> getParents(int node)
{
  vector<int> parents;
  for (int i = 1; i <= N; i++)
  {
    if (graph[i][node]) parents.push_back(i);
  }
  return parents;
}

int getNumOfDesc(int node)
{
  int numOfDesc = 0;
  vector<int> children = getChildren(node);
  vector<int>::iterator iter;
  for (iter=children.begin();iter!=children.end();iter++)
  {
    int child = *iter;
    if (!isVisited(child)) {
      numOfDesc += getNumOfDesc(child) + 1;
      visit(child);
    }
  }
  return numOfDesc;
}

int getNumOfAsc(int node)
{
  int numOfAsc = 0;
  vector<int> parents = getParents(node);
  vector<int>::iterator iter;
  for (iter=parents.begin();iter!=parents.end();iter++)
  {    
    int parent = *iter;
    if (!isVisited(parent)) {
      numOfAsc += getNumOfAsc(parent) + 1;
      visit(parent);
    }
  }
  return numOfAsc;
}

int getNumOfNeverMid() {
  int numOfNeverMid = 0;
  for(int i=1; i<=N; i++)
  {
    desc[i] = getNumOfDesc(i);
    initVisited();
    asc[i] = getNumOfAsc(i);
    initVisited();
    if (desc[i] > threshold || asc[i] > threshold) numOfNeverMid++;
  }
  return numOfNeverMid;
}


int main() {
  string tmpString;
  string heavy;
  string light;

  cin >> tmpString;
  N = stoi(tmpString);
  assert(N >= 1 && N <= 99);

  threshold = (N-1)/2;

  cin >> tmpString;
  M = stoi(tmpString);
  assert(M >= 1 && M <= N*(N-1)/2);

  for (int i=1; i<=N; i++)
  {
    for (int j=1; j<=N; j++)
      graph[i][j] = false; // initialize DAG graph
  }

  for (int i = 0; i < M; i++)
  {
    cin >> heavy;
    cin >> light;
    graph[stoi(light)][stoi(heavy)] = true; // make edge from light to heavy
  }

  int numOfNeverMid = getNumOfNeverMid();
  cout << numOfNeverMid << endl;

  // cout << "(i, desc, asc)" << endl;
  // for (int i=1; i<=N ; i++)
  // {
  //   cout << "(" << i << "," << desc[i] << "," << asc[i] << ")" << endl;
  // }
}