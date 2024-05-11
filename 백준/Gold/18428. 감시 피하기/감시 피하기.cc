#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char map[7][7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool flag;
vector<pair<int,int>> t, blank;

bool watch(int nx, int ny, int dir){
    while(1){
        nx += dx[dir];
        ny += dy[dir];
        if(map[nx][ny] == 'O' || nx < 0 || nx >= n || ny < 0 || ny >= n){
            break;
        }
        if(map[nx][ny] == 'S')
            return true;
    }
    return false;
}

bool dodge(){
    for(int i = 0; i < t.size(); i++){
        int x = t[i].first;
        int y = t[i].second;
        for(int j = 0; j < 4; j++){
            if(watch(x,y,j)){
                return false;
            }
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt == 3){
        if(dodge()) flag = true;
        return;
    }
    for(int i = 0; i < blank.size(); i++){
        int x = blank[i].first;
        int y = blank[i].second;
        if(map[x][y] == 'X'){
            map[x][y] = 'O';
            dfs(cnt + 1);
            map[x][y] = 'X';
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 'T')
                t.push_back({i,j});
            else if(map[i][j] == 'X')
                blank.push_back({i,j});
        }
    }
    dfs(0);
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
