#include <string>
#include <iostream>
using namespace std;

const int MAX_INPUT_NUM = 100000;

int main() {
  string tmpString;
  int N;
  int input[MAX_INPUT_NUM];

  cin >> tmpString;
  N = stoi(tmpString);

  cout << "number: " << N << endl;

  for (int i = 0; i < N; i++)
  {
    cin >> tmpString;
    input[i] = stoi(tmpString);
  }

}