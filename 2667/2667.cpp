#include <iostream>
#include <string>
#include <vector>
#include <utility> // pair 사용할 수 있게 하는 라이브러리
#include <algorithm>
#include <cassert>

using namespace std;

// 전역 변수
int N = 0; // table의 크기
bool houseTable[30][30];
int parentTable[30][30];
int townNum = 0;
vector<int> towns;
const int INVALID_TOWN = -1;
const int NOT_ASSIGNED = 0;
const int ROOT = 1000;

void printParentTable()
{
  cout << "PARENT TABLE" << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (parentTable[i][j] == INVALID_TOWN) cout << "X"; 
      else if (parentTable[i][j] == ROOT) cout << "R"; 
      else cout << parentTable[i][j];
    }
    cout << endl;
  }
}

void printHouseTable()
{
  cout << "HOUSE TABLE" << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << houseTable[i][j];
    }
    cout << endl;
  }
}

bool isValidHouse(pair<int, int> point)
{
	bool isInbound = (point.first >= 0 && point.first < N && point.second >= 0 && point.second < N);
	return isInbound && houseTable[point.first][point.second];
}

vector<pair<int, int>> getIncidents(pair<int, int> curHouse)
{
	int curX = curHouse.first;
	int curY = curHouse.second;
	vector<pair<int, int>> incidents;

	pair<int, int> up = pair<int, int>(curX, curY-1);
	pair<int, int> down = pair<int, int>(curX, curY+1);
	pair<int, int> left = pair<int, int>(curX-1, curY);
	pair<int, int> right = pair<int, int>(curX+1, curY);

	if (isValidHouse(up)) incidents.push_back(up);
	if (isValidHouse(down)) incidents.push_back(down);
	if (isValidHouse(left)) incidents.push_back(left);
	if (isValidHouse(right)) incidents.push_back(right);
	
	return incidents;
}

// DFS
void DFS(pair<int, int> curHouse) {
	int curX = curHouse.first;
	int curY = curHouse.second;

	if (parentTable[curX][curY] == NOT_ASSIGNED) {// 트리의 루트
    parentTable[curX][curY] = ROOT;
		towns.insert(towns.begin(), 1);
    townNum += 1;
  }
	else {
    *(towns.begin()) += 1; 
  } 

	vector<pair<int, int>> incidents = getIncidents(curHouse);

	for (vector<pair<int, int>>::iterator iter = incidents.begin(); iter != incidents.end(); iter++)
	{
		int x = iter -> first;
		int y = iter -> second;
		if (parentTable[x][y] == NOT_ASSIGNED) { // 아직 방문하지 않은 노드 방문
			parentTable[x][y] = townNum;
			DFS(*iter);
		}
	}
}

void getTowns() {
	// 입력 받기
	string tmpString;
	cin >> tmpString;
	N = stoi(tmpString);
	
	for (int i=0; i<N; i++) {
    cin >> tmpString;
		for (int j=0; j<N; j++) {
      int tmpInt = tmpString.at(j) - '0';
			houseTable[i][j] = tmpInt == 1;
			if (houseTable[i][j]) parentTable[i][j] = NOT_ASSIGNED;
      else parentTable[i][j] = INVALID_TOWN;
		}
	}

	for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (parentTable[i][j] == NOT_ASSIGNED)
				{
					pair<int, int> townEntry = make_pair(i, j);
					DFS(townEntry);
				}
			}
	}

	// 결과 출력
  assert(townNum == towns.size());
	cout << townNum << endl;

	sort(towns.begin(), towns.end());

	for (vector<int>::iterator iter = towns.begin(); iter != towns.end(); iter++)
	{
		cout << *iter << endl;
	}
}

int main()
{
  getTowns();
  // printParentTable();
  return 0;
}