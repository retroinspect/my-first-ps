#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <queue>

using namespace std;

struct schedule {
  int start;
  int end;

  schedule(int _start, int _end) : start(_start), end(_end) {};
};

bool operator<(schedule a, schedule b) {
  if (a.start < b.start) return true;
  if (a.start == b.start) return a.end < b.end;
  return false;
}

std::ostream& dump(std::ostream &o, const schedule& s)
{
    return o << s.start << " " << s.end << endl;
}

priority_queue<schedule, vector<schedule>, greater<schedule>> input;

int N;

int main()
{
  cin >> N;
  for (int i=0; i<N; i++) {
    int start, end;
    cin >> start; cin >> end;
    schedule s(start, end);
    input.push(s);
  }

  assert(input.size() == N);

  while (!input.empty()) {
    cout << input.top();
    input.pop();
  }

  return 0;
}
