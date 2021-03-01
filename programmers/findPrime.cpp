#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> answers;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void make(string s, int n)
{
    // cout << "n: " << n << endl;
    if (isPrime(n)) answers.push_back(n);
    for (int i=0; i<10; i++) {
        if (s.at(i) == '0') continue;
        string ns = s; ns.at(i) -= 1;
        int nn = n*10 + i;
        make(ns, nn);
    }
    return;
}


int solution(string numbers) {
    string info = "0000000000";
    for (int i=0; i<numbers.length(); i++) {
        int number = numbers.at(i) - '0';
        info.at(number) += 1;
    }

    make(info, 0);

    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(),answers.end()), answers.end());

    int answer = answers.size();
    return answer;
}

int main() {
  string s;
  cin >> s;
  cout << solution(s) << endl;
}