// 좌표 압축
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

vector<int> input;
vector<int> save;

// 똑같이 NlogN이라도 개선할 수 있는 부분이 있다!!
int main()
{
  string tmpString;
  cin >> tmpString;

  int N = stoi(tmpString);

  for (int i=0; i<N; i++)
  {
    cin >> tmpString;
    int num = stoi(tmpString);
    input.push_back(num);
    save.push_back(num);
  }

  sort(input.begin(), input.end());
  input.erase(unique(input.begin(),input.end()), input.end());

  for (int i=0; i<N; i++)
  {
    int e = save[i];
    int idx = lower_bound(input.begin(), input.end(), e) - input.begin();
    cout << idx << " ";
  }
  cout << endl;
  return 0;
}