#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pattern_2[4] = {1, 3, 4, 5};
int pattern_3[5] = {3, 1, 2, 4, 5};

vector<int> firstA;
vector<int> secondA;
vector<int> thirdA;

void print(vector<int> v) {
  for (int i=0; i<v.size(); i++)
    cout << v[i] << " ";
    cout << endl;
}

// 1번 수포자의 답안
int first(int idx) {
    return (idx%5 + 1);
}

int second(int idx) {
    if (idx % 2 == 0) return 2;
    int order = ((idx-1)/2) % 4;
    return pattern_2[order];
}

int third(int idx) {
    int order = (idx / 2) % 5;
    return pattern_3[order];
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int f = 0;
    int s = 0;
    int t = 0;
    for (int i=0; i<answers.size(); i++) {
        int a = answers[i];

        firstA.push_back(first(i));
        secondA.push_back(second(i));
        thirdA.push_back(third(i));

        if (first(i) == a) f++;
        if (second(i) == a) s++;
        if (third(i) == a) t++;
    }
    
    int maxV = max({f, s, t});
    if (f == maxV) answer.push_back(1);
    if (s == maxV) answer.push_back(2);
    if (t == maxV) answer.push_back(3);

    print(firstA);
    print(secondA);
    print(thirdA);


    return answer;
}

int main() {
  int N, tmp;
  vector<int> input;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> tmp;
    input.push_back(tmp);
  }

  print(solution(input));
  return 0;
}