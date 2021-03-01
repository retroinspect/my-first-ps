// 통나무 건너뛰기
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

vector<int> input;
vector<int> optPermut;
vector<int> diffs; // pair of diff and hardest position (former one)
int N;


void initDiffs()
{
  assert(optPermut.size() == 3);
  int M = optPermut.size();

  for (int j=0; j<M; j++)
  {
    int num1 = optPermut[j];
    int num2 = (j == M-1) ? optPermut[0] : optPermut[j+1];
    int diff = abs(num1-num2);
    diffs.push_back(diff);
  }
}

// return pair of max value of diffs and index
pair<int, int> getTopPair()
{
  int tmp = -1;
  int tmpIdx = -1;
  for (int i=0; i<diffs.size(); i++)
  {
    if (tmp < diffs[i]) {
      tmp = diffs[i];
      tmpIdx = i;
    } 
  }
  return make_pair(tmp, tmpIdx);
}

// push first three element of input
void initOptPermut()
{
  assert(input.size() >= 5);
  optPermut.push_back(input[0]);
  optPermut.push_back(input[1]);
  optPermut.push_back(input[2]);
  assert(optPermut.size() == 3);
}

void replaceDiffs(int e, int posToInsert, int diff1, int diff2)
{
  diffs[posToInsert] = diff1;
  diffs.insert(diffs.begin() + posToInsert + 1, diff2);
  optPermut.insert(optPermut.begin() + posToInsert, e);
}

void logJumping()
{
  sort(input.begin(), input.end()); // 필요한지 잘 모르겠음
  
  initOptPermut();
  initDiffs();

  for(int i=3; i<N; i++)
  {
    int e = input[i]; // element to insert to optPermut
    int M = optPermut.size();
    assert(M == i);

    pair<int, int> top = getTopPair();
    int maxDiff = top.first;
    int hardestPos = top.second;
    int posToInsert = -1;

    assert(hardestPos >= 0 && hardestPos < M);
    assert(maxDiff >= 0);

    // 1. hardestPos 에 넣었을 때 maxDiff 가 작아지는 경우 - hardestPos에 넣기
    int num1 = optPermut[hardestPos];
    int num2 = (hardestPos == M-1) ? optPermut[0] : optPermut[hardestPos+1];
    int diff1 = e - num1;
    int diff2 = e - num2;
    assert(diff1 >= 0 && diff2 >= 0); // e is always larger than other elements

    if (diff1 <= maxDiff && diff2 <= maxDiff) {
      replaceDiffs(e, hardestPos, diff1, diff2);
      continue;
    }

    int minOfMaxDiff = max(diff1, diff2);
    int posToInsertCandidate = hardestPos;

    // 2. hardestPos 이외의 위치에 넣었을 때 maxDiff >= max(diff1, diff2) 인 경우 - 발견한 첫 번째 위치에 끝내기 (선택) vs 최소의 위치에 넣기
    for (int j=0; j<M; j++)
    {
      num1 = optPermut[j];
      num2 = (j == M-1) ? optPermut[0] : optPermut[j+1];
      diff1 = e - num1;
      diff2 = e - num2;
      assert(diff1 >= 0 && diff2 >= 0); // e is always larger than other elements
      int tmp = max(diff1, diff2);

      if (tmp <= maxDiff) {
        replaceDiffs(e, j, diff1, diff2);
        break;
      }

      if (tmp < minOfMaxDiff) {
        posToInsertCandidate = j;
        minOfMaxDiff = tmp;
      }
    }

  // 3. 모든 위치에 대해 maxDiff < max(diff1, diff2) 인 경우 - 가장 작은 diff의 위치에 넣기
    assert(maxDiff < minOfMaxDiff);
    num1 = optPermut[posToInsertCandidate];
    num2 = (posToInsertCandidate == M-1) ? optPermut[0] : optPermut[posToInsertCandidate+1];
    diff1 = e - num1;
    diff2 = e - num2;
    replaceDiffs(e, posToInsertCandidate, diff1, diff2);
  }

  assert(optPermut.size() == N);
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

    logJumping();
    answers.push_back(getTopPair().first);
    input.clear();
    optPermut.clear();
    diffs.clear();
  }

  for (vector<int>::iterator iter=answers.begin(); iter != answers.end(); iter++)
  {
    cout << *iter << endl;
  }

  return 0;
}