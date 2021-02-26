#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <queue>

using namespace std;

struct cmp {
  bool operator() (pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) return false;
    if (a.second == b.second) return a.first > b.first;
    return true;
  }
};

vector<pair<int, int>> input;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> room; // end가 빠른 순, end가 같다면 start가 빠른 순으로 정렬되는 큐
int N;

bool sortByFirst(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
  // return a.second < b.second; // 반례 안됨
  if (a.first < b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false; 
}

bool hasRoom(int i)
{
  pair<int, int> lastLesson = room.top();
  if (lastLesson.second <= input[i].first) {
    room.pop();
    room.push(input[i]);
    return true;
  }
  return false;
}

int main()
{
  cin >> N;
  for (int i=0; i<N; i++) {
    int start, end;
    cin >> start; cin >> end;
    input.push_back(make_pair(start, end));
  }

  assert(input.size() == N);
  sort(input.begin(), input.end(), sortByFirst); // sort by end time in ascending order

  room.push(input[0]);
  for (int i=1; i<N; i++) {
    if (hasRoom(i)) continue;
    else room.push(input[i]);
  }

  cout << room.size() << endl;
  return 0;
}
