// 회장 뽑기
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_INPUT_NUM = 51;
const int INF = 100;
int N; // number of members
int dist[MAX_INPUT_NUM][MAX_INPUT_NUM];
int score[MAX_INPUT_NUM];


void optimizeDist()
{
  for (int i=1; i<=N; i++)
  {
    for (int j=1; j<=N; j++)
    {
      for (int k=1; k<=N; k++)
      {
        if (i==j || j==k || i==k) continue;
        int cand = dist[i][k] + dist[k][j];
        if (cand >= INF) continue;
        else if (dist[i][j] == INF || dist[i][j] > cand)
        {
          dist[i][j] = cand;
          dist[j][i] = cand;
        }
      }
    }
  }
}

void calculateScore()
{
  int max;
  for (int i=1; i<=N; i++)
  {
    max = 0;
    for (int j=1; j<=N; j++)
    {
      if (dist[i][j] > max) max = dist[i][j];
    }
    score[i] = max;
  }
}

void printVector(vector<int>::iterator begin, vector<int>::iterator end)
{
  
  for (vector<int>::iterator iter = begin; iter != end; iter++)
  {
    cout << *iter << " ";
  }
  cout << endl;
}

void printDist()
{
  cout << "dist table" << endl;
  for (int i=1; i<=N; i++)
  {
    for (int j=1; j<=N; j++)
      cout << dist[i][j] << " ";
    cout << endl;
  }
}

int main() {
  string tmpString;
  string person1;
  string person2;
  int p1 = 0;
  int p2 = 0;

  cin >> tmpString;
  N = stoi(tmpString);

  // init dist table
  score[0] = INF;
  for (int i=1; i<=N; i++)
  {
    score[i] = INF;
    for (int j=1; j<=N; j++) {
      if (i==j) {
        dist[i][j] = 0;
        break;
      }
      dist[i][j] = INF;
      dist[j][i] = INF;
    }
  }

  while(true)
  {
    cin >> person1;
    cin >> person2;

    p1 = stoi(person1);
    p2 = stoi(person2);

    if (p1 == -1 && p2 == -1) break;

    dist[p1][p2] = 1;
    dist[p2][p1] = 1;
  }

  // printDist();
  optimizeDist();
  // printDist();
  calculateScore();

  vector<int> v(score, score + N + 1);
  
  // cout << "v" << endl;
  // printVector(v.begin(), v.end());


  sort(v.begin(), v.end());
  int lowestScore = *(v.begin());

  // cout << "lowestScore " << lowestScore << endl;
  // cout << "scores" << endl;
  // for (int i=1; i<=N; i++)
  // {
  //   cout << score[i] << " ";
  // }
  // cout << endl;


  vector<int> cands;
  for (int i=1; i<=N; i++)
  {
    if (score[i] == lowestScore) {
      cands.push_back(i);
    }
  }

  cout << lowestScore << " " << cands.size() << endl;
  for (vector<int>::iterator iter=cands.begin(); iter!= cands.end(); iter++)
  {
    cout << *iter << " ";
  }
  cout << endl;
}