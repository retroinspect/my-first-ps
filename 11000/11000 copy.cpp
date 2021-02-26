#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

vector<pair<int, int>> input;
vector<int> room;
int N;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
  // return a.second < b.second; // 반례 안됨
  if (a.first < b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false; 
}

bool hasRoom(int i)
{
    for (int j=0; j<room.size(); j++)
    {
      pair<int, int> lastLesson = input[room[j]];
      if (lastLesson.second <= input[i].first) {
        room[j] = i;
        return true;
      }
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
  sort(input.begin(), input.end(), sortbysec); // sort by end time in ascending order

  room.push_back(0);
  for (int i=1; i<N; i++) {
    if (hasRoom(i)) continue;
    else room.push_back(i);
  }

  cout << room.size() << endl;
  return 0;
}
