#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

vector<pair<int, int>> input;
int N;


// 반례
// 3
// 4 4
// 3 4
// 3 4

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
  // return a.second < b.second; // 반례 안됨
  if (a.second < b.second) return true;
  if (a.second == b.second) return a.first < b.first;
  return false; 
} 

int main()
{
  cin >> N;
  for (int i=0; i<N; i++) {
    unsigned int start, end;
    cin >> start; cin >> end;
    input.push_back(make_pair(start, end));
  }

  assert(input.size() == N);
  sort(input.begin(), input.end(), sortbysec); // sort by end time in ascending order

  // cout << "sorted input" << endl;
  // for (int i=0; i<N; i++) cout << input[i].first << " " << input[i].second << endl;

  // cout << endl;

  int cnt = 1; // choose first schedule
  unsigned int end = input[0].second;
  for (int i=1; i<N; i++) {
    if (end <= input[i].first) {
      cnt++;
      end = input[i].second;
    }
  }

  cout << cnt << endl;
  return 0;
}
