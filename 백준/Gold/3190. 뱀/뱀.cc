#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;
int map[101][101] = { 0, };

int main(){
	queue<pair<int, int>> snake;
	queue<pair<int, char>> qdir;
	int N, K;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++){
		int input_x, input_y;
		cin >> input_x >> input_y;
		map[input_x][input_y] = 1;
	}
	int L;
	cin >> L;
	for (int i = 0; i < L; i++){
		int time;
		char dir;

		cin >> time >> dir;

		qdir.push(make_pair(time, dir));
	}
	int x = 1;
	int y = 2;
	int ndir = 1;
	int cnt = 1;
	int dirX[4] = { 1, 0, -1, 0 };
	int dirY[4] = { 0, 1, 0, -1 };
	snake.push(make_pair(1, 1));
	map[1][1] = 2;
	while (1){
		if (x > N || y > N || x < 1 || y < 1)
			break;
		if (map[x][y] == 2)
			break;
		if (!qdir.empty()){
			if (cnt == qdir.front().first){
				if (qdir.front().second == 'L')
					ndir = (ndir + 1) % 4;
				else if (qdir.front().second == 'D')
					ndir = (ndir + 3) % 4;
				qdir.pop();
			}
		}

		if (map[x][y] == 0){
			snake.push(make_pair(x, y));
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		else if (map[x][y] == 1){
			snake.push(make_pair(x, y));
		}
		map[x][y] = 2;
		x = x + dirX[ndir];
		y = y + dirY[ndir];
		cnt++;
	}
	cout << cnt;
	return 0;
}
