#include <stdio.h>
#include <algorithm>
// 진정한 의미의 DP는 아님

using namespace std;

int n, m;
int arr[1002][1002];

int solution() {
  int maxSquare[n+1][m+1];
  // maxSquare: (0, 0) 부터 (i, j) 까지의 배열에서 (i, j)를 포함하는, 1로 된 가장 큰 정사각형의 한 변 길이
  int maxV = 0;

  for (int i=0; i<=n; i++)
    maxSquare[i][0] = 0;
  
  for(int j=0; j<=m; j++)
    maxSquare[0][j] = 0;

  for(int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (arr[i][j] == 0) maxSquare[i][j] = 0;
      else {
        maxSquare[i][j] = min({maxSquare[i-1][j-1], maxSquare[i][j-1], maxSquare[i-1][j]}) + 1;
      }

      if (maxSquare[i][j] > maxV) maxV = maxSquare[i][j];
    }
  }

  return maxV*maxV; // 넓이를 반환해야하므로 제곱 반환
}

int main()
{
  scanf("%d %d", &n, &m);
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }

  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<m; j++) {
  //     printf("%d", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  int ans = solution();
  printf("%d\n", ans);

  return 0;
}