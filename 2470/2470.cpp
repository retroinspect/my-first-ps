#include <string>
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>

using namespace std;

const int MAX_INPUT_NUM = 100000;
int get_closest(int suppler, int prevMidInput, int midInput)
{
  // cout << suppler << ", " << prevMidInput << ", " << midInput << endl;
  if (abs(suppler - prevMidInput) < abs(suppler - midInput)) return prevMidInput;
  else return midInput;
}
// input 배열의 숫자 중 suppler와 차이가 가장 작은 값 출력
int binary_search(int suppler, int *input, int len) {
  int low = 0;
  int high = len-1;
  int mid = -1;
  int prevMid;

  while (low <= high) {
    prevMid = mid;
    mid = (low + high) / 2;
    if (input[mid] < suppler) {
      low = mid + 1;
    }
    else if (input[mid] > suppler) {
      high = mid - 1;
    }
    else break;
  }

  if (prevMid == -1) {
      // cout << suppler << ", " << input[mid] << endl;
    return input[mid];
    }
  return get_closest(suppler, input[prevMid], input[mid]);
}


int main() {
  string tmpString;
  int N;
  int input[MAX_INPUT_NUM];

  cin >> tmpString;
  N = stoi(tmpString);

  for (int i = 0; i < N; i++)
  {
    cin >> tmpString;
    input[i] = stoi(tmpString);
  }

  sort(input, input + N);

  int pivot;
  int num1 = input[0];
  int num2 = input[1]; // num1 < num2
  int sum = abs(num1 + num2);
  int tmp; 

  for (int i = 0; i < N-1; i++) {
    pivot = input[i];
    tmp = binary_search((-1) * pivot, input + i + 1, N-i-1); // 합이 0에 가장 가까운 수를 구한다
    // cout << pivot << " " << tmp << " " << abs(pivot + tmp) << endl;

    if (abs(pivot + tmp) <= sum ) {
      num1 = pivot;
      num2 = tmp;
      sum = abs(pivot + tmp);
    }
  }
  cout << num1 << " " << num2 << endl;
}
