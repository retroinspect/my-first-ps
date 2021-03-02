#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int things[102][2];
int s[102][100002];

int solution() {
  for (int i=0; i<=N; i++) {
    s[i][0] = 0;
  }

  for (int j=0; j<=K; j++) {
    s[0][j] = 0;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=K; j++) {
      int w = things[i][0];
      int v = things[i][1];
      if (w <= j) { // 챙길 수 있는 물건
        s[i][j] = max({s[i-1][j-w] + v, s[i-1][j]});
      }
      else s[i][j] = s[i-1][j];
    }
  }

  return s[N][K];
}

int main() {
  cin >> N >> K;

  for (int i=1; i<=N; i++) {
    cin >> things[i][0] >> things[i][1];
  }

  int ans = solution();
  cout << ans << endl;
  return 0;
}