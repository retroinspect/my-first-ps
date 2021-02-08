#include <string>
#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>

using namespace std;

const int MAX_INPUT_NUM = 100000;

int distance(int suppler, int cand)
{
  return abs(suppler - cand);
}


int get_closest_from_two(int suppler, int cand1, int cand2)
{
  int dist1 = distance(suppler, cand1);
  int dist2 = distance(suppler, cand2);

  if (dist1 < dist2) return cand1;
  return cand2;
}


// input 배열에 suppler가 있다고 가정했을 때, 그 위치를 반환
int find_pos(int suppler, int *input, int len) {
  // binary search
  int low = 0;
  int high = len-1;
  int mid;

  if (input[low] > suppler) return low;
  if (input[high] < suppler) return high;

  // loop invariant: input[low] <= suppler <= input[high]
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (suppler == input[mid]) return mid;
    else if (input[mid] < suppler) {
      low = mid + 1; // 하한선 올리기
      if (input[low] > suppler) return low; // mid+1 과 mid 사이가 적합한 위치인 경우
    }
    else {
      high = mid - 1; // 상한선 내리기
      if (input[high] < suppler) return high; // mid-1 과 mid 사이가 적합한 위치인 경우
    }
  }

  return -1;
}

// index of first element such that suppler <= input[x]
int lower_insertion_point(int suppler, int *input, int len)
{
  if (suppler < input[0]) return 0;
  if (suppler > input[len-1]) return len;
  
  int lowerPoint = 0;
  int i = 1;

  while (i < len && input[i] < suppler)
  {
    lowerPoint = i;
    i = i*2;
  }

  while (lowerPoint < len && input[lowerPoint] < suppler)
    lowerPoint++;
  
  return lowerPoint;
}


// input 배열의 숫자 중 suppler와 차이가 가장 작은 값 출력
int get_closest(int suppler, int *input, int len) {
  int pos = lower_insertion_point(suppler, input, len);
  
  if (pos == 0) return input[0];
  if (pos == len) return input[len-1];
  return get_closest_from_two(suppler, input[pos], input[pos-1]);

  // int pos = find_pos(suppler, input, len);
  // assert(pos >= 0);
  // if (pos == 0) return get_closest_from_two(suppler, input[0], input[1]);
  // if (pos == len-1) return get_closest_from_two(suppler, input[len-1], input[len-2]);
  
  // int candidate = get_closest_from_two(suppler, input[pos+1], input[pos-1]);
  // return get_closest_from_two(suppler, input[pos], candidate);
}

void two_solution(int N, int *input) {
  int pivot;
  int num1 = input[0];
  int num2 = input[1]; // num1 < num2
  int sum = abs(num1 + num2);
  int tmp; 

  for (int i = 0; i < N-1; i++) {
    pivot = input[i];
    tmp = get_closest((-1) * pivot, input + i + 1, N-i-1); // 합이 0에 가장 가까운 수를 구한다
    // cout << pivot << " " << tmp << " " << abs(pivot + tmp) << endl;

    if (abs(pivot + tmp) <= sum ) {
      num1 = pivot;
      num2 = tmp;
      sum = abs(pivot + tmp);
    }
  }
  cout << num1 << " " << num2 << endl;
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
  two_solution(N, input);
}
