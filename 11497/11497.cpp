// 통나무 건너뛰기
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

vector<int> input;
int N;

int logJumping()
{
  sort(input.begin(), input.end());
  list<int> reorder;

  for (int i=0; i<N; i++)
  {
    int e = input[i];
    if (i%2 == 0) reorder.push_back(e);
    else reorder.push_front(e);
  }

  int maxDiff = -1;
  for (list<int>::iterator iter = reorder.begin(); iter != reorder.end(); iter++)
  {
    list<int>::iterator tmpIt = iter; tmpIt++;
    int num1 = *iter;
    int num2 = (tmpIt == reorder.end()) ? reorder.front() : *tmpIt;

    int tmp = abs(num1-num2);
    if (tmp > maxDiff) maxDiff = tmp;
  }

  return maxDiff;
}

int main()
{
  string tmpString;
  cin >> tmpString;
  int T = stoi(tmpString);
  vector<int> answers;
  for (int i=0; i<T; i++)
  {
    cin >> tmpString;
    N = stoi(tmpString);

    for (int j=0; j<N; j++)
    {
      cin >> tmpString;
      int num = stoi(tmpString);
      input.push_back(num);
    }

    int answer = logJumping();
    answers.push_back(answer);
    input.clear();
  }

  for (vector<int>::iterator iter=answers.begin(); iter != answers.end(); iter++)
  {
    cout << *iter << endl;
  }

  return 0;
}