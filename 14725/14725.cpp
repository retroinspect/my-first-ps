#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 이렇게 하면 출력할 때 시간복잡도가 너무 커짐 (N배)
// class Node {
//   vector<Node*> children;
//   string s; 
// }


class Node {
  // int children[10] 
  public: map<string, Node> children; // 가장 고민 많았던 부분
  // 
};

void insert(Node &v, vector<string> &arr, int i) {
  if (i == arr.size()) return;
  string cur = arr[i];
  if (!v.children.count(cur)) v.children[cur] = Node();
  insert(v.children[cur], arr, i+1);
}

void print(Node &v, int dep = 0)
{
  for (auto i: v.children) {
    for (int j=0; j<dep; j++) cout << "--";
    cout << i.first << endl;
    print(i.second, dep+1);
  }
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  Node root;
  while (N--) {
    int K; cin >> K;
    vector<string> v(K);
    for (int i=0; i<K; i++) cin >> v[i];
    insert(root, v, 0);
  }

  print(root);
  return 0;
}