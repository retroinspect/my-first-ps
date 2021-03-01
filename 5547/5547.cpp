#include <iostream>
#include <string>
#include <vector>
#include <utility> // pair 사용할 수 있게 하는 라이브러리
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

const int MAX_INPUT_NUM = 101;

// 전역 변수
int W = 0;
int H = 0;
int wallLen = 0;

int dx[6] = {-1, 0, 1, 0, -1, -1};
int dy[6] = {-1, -1, 0, 1, 1, 0};

bool buildingTable[MAX_INPUT_NUM][MAX_INPUT_NUM];
int visited[MAX_INPUT_NUM][MAX_INPUT_NUM];

int marked[MAX_INPUT_NUM][MAX_INPUT_NUM];
int townNum = 0;

vector<int> towns;
const int INVALID_BUILDING = -1;
const int UNVISITED = 0;
const int ROOT = 1000;
const int VISITED = 1;

int surrounded[MAX_INPUT_NUM][MAX_INPUT_NUM];
const int hetero = -1;
const int undefined = -2; // if [x][y] is building


void visitAndFillHeteroConnected(pair<int, int> vacant)
{
  // find connected nodes and fill it with surrounded[][] = hetero
}

bool isSurroundedWithSameTown(pair<int, int> vacant, int marker)
{
  bool flag = true;
  vector<pair<int, int>> surrounds = getSurrounds(vacant);
  vector<pair<int, int>>::iterator iter;
  for (iter = surrounds.begin(); iter != surrounds.end(); iter++)
  {
    if (getTownNum(surroundBuilding) != marker) {
      visitAndFillHeteroConnected(vacant);
      return false;
    }
  }
}

int inspectVacant(pair<int, int> curVacant)
{
  int curX = curVacant.first;
  int curY = curVacant.second;

  queue <pair<int, int>> q;
  q.push(curVacant);


  while(!q.empty())
  {
    pair<int, int> vacant = q.front();
    q.pop();

    vector<pair<int, int>> incidentVacants = getIncidentVacants(vacant);
    for (vector<pair<int, int>>:: iterator iter = incidentVacants.begin(); iter != incidentVacants.end(); iter++)
    {
      int x = iter -> first;
      int y = iter -> second;
    }
  }

  return 0;
}

  // towns.insert(towns.begin(), 1);
  // townNum++;

  // marked[curX][curY] = townNum;




void printParentTable()
{
  cout << "PARENT TABLE" << endl;
  for (int i=0; i<W; i++) {
    for (int j=0; j<W; j++) {
      if (visited[i][j] == INVALID_BUILDING) cout << "X"; 
      else if (visited[i][j] == ROOT) cout << "R"; 
      else if (visited[i][j] == VISITED) cout << "V";
      else if (visited[i][j] == UNVISITED) cout << "";

    }
    cout << endl;
  }
}

void printHouseTable()
{
  cout << "HOUSE TABLE" << endl;
  for (int i=0; i<W; i++) {
    for (int j=0; j<W; j++) {
      cout << buildingTable[i][j];
    }
    cout << endl;
  }
}

bool isValidHouse(pair<int, int> point)
{
	bool isInbound = (point.first >= 0 && point.first < W && point.second >= 0 && point.second < W);
	return isInbound && buildingTable[point.first][point.second];
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

void BFS(pair<int, int> entry) {
  int entryX = entry.first;
  int entryY = entry.second;

  queue< pair<int,int> > q; 
  q.push(entry);

  visited[entryX][entryY] = ROOT;
  int numOfBuildings = 1;
  int numOfTotalIncidents = 0;

  while(!q.empty()){
      // 큐의 현재 원소를 꺼내기
      pair<int,int> house = q.front();
      q.pop();
      vector<pair<int, int>> incidents = getIncidents(house);
      numOfTotalIncidents += incidents.size();
      for (vector<pair<int, int>>::iterator iter = incidents.begin(); iter != incidents.end(); iter++)
      {
        int x = iter -> first;
        int y = iter -> second;
        if (visited[x][y] == UNVISITED) { // 아직 방문하지 않은 노드 방문
          visited[x][y] = townNum;
          numOfBuildings++;
          q.push(*iter);
        }
      }
	}

  wallLen += 6*numOfBuildings - numOfTotalIncidents;
}

void getWallLen() {
	// 입력 받기
	string tmpString;
	cin >> tmpString;
	W = stoi(tmpString);

  cin >> tmpString;
	H = stoi(tmpString);
	
	for (int i=0; i<H; i++) {
    cin >> tmpString;
		for (int j=0; j<W; j++) {
      int tmpInt = tmpString.at(j) - '0';
			buildingTable[i][j] = tmpInt == 1;
			if (buildingTable[i][j]) visited[i][j] = UNVISITED;
      else visited[i][j] = INVALID_BUILDING;
		}
	}

	for (int i=0; i<W; i++) {
			for (int j=0; j<W; j++) {
				if (visited[i][j] == UNVISITED)
				{
					pair<int, int> entry = make_pair(i, j);
					BFS(entry);
				}
			}
	}

  cout << wallLen << endl;
}

int main()
{
  getWallLen();
  return 0;
}