#include <iostream>
#include <string>
#include <vector>
#include <utility> // pair 사용할 수 있게 하는 라이브러리
#include <cassert>
#include <cmath>

using namespace std;

const int MAX_INPUT_NUM = 102;
pair<int, int> coordinate[MAX_INPUT_NUM];
int costs[MAX_INPUT_NUM][MAX_INPUT_NUM];

int N = 0;

const int INF = 10000;
const int threshold = 20;


int dist(pair<int, int> v1, pair<int, int> v2)
{
  int x1 = v1.first;
  int y1 = v1.second;
  int x2 = v2.first;
  int y2 = v2.second;

  return abs(x1-x2) + abs(y1-y2);
}

int beer(pair<int, int> v1, pair<int, int> v2)
{
  return dist(v1, v2)/50;
}

void optimizeCosts()
{
  for (int i=0; i<N; i++)
  {
    for (int j=0; j<N; j++)
    {
      for (int k=0; k<N; k++)
      {
        if (costs[i][j] > costs[i][k] + costs[k][j]) {
          costs[i][j] = costs[i][k] + costs[k][j];
          if (costs[i][j] > threshold) costs[i][j] = INF;
        }
      }
    }
  }
}


void initCosts()
{  
  for (int i=0; i<N; i++)
  {
    pair<int, int> v1 = coordinate[i];
    for (int j=0; j<N; j++)
    {
      if (i==j) {
        costs[i][j] = 0;
        continue;
      }

      pair<int, int> v2 = coordinate[j];
      int beerCost = beer(v1, v2);
      if (beerCost > threshold) costs[j][j] = INF;
      else costs[i][j] = beerCost;
    }
  }
}

void getInput()
{
  string tmpString;
  cin << tmpString;
  N = stoi(tmpString);

  
}