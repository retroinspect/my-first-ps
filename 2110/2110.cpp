#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수
const int MAXN = 200000;
int point[MAXN];
int N, C;

bool canReachAll(int minDist) // O(N)
{
	int lastIptimePoint = point[0];
	int mountedIptime = 1;
	for (int i=1; i<N && mountedIptime < C; i++) {
		int curIptimePoint = point[i];
		int dist = curIptimePoint - lastIptimePoint;
		if (dist >= minDist) {
			mountedIptime++;
			lastIptimePoint = curIptimePoint;
		}
	}
	return mountedIptime == C;
}

int getMaxDist()
{
	int start = 1; // 무조건 되는 값의 최댓값
	int end = ceil(double(point[N-1] - point[0])/double(C-1)) + 1; // 절대 안되는 값의 최솟값
	
	// 이분 탐색으로 범위를 좁혀나감
	while (true)
	{
		int mid = start + (end-start)/2;
		if (canReachAll(mid)) start = mid;
		else end = mid;

		if (start + 1 == end) break;
	}
	return start;
}


int main() {
  string tmpString;

  cin >> tmpString;
  N = stoi(tmpString);

  cin >> tmpString;
  C = stoi(tmpString);

  for (int i = 0; i < N; i++)
  {
    cin >> tmpString;
    point[i] = stoi(tmpString);
  }

  sort(point, point + N);
  int maxDist = getMaxDist();
  cout << maxDist << endl;
}