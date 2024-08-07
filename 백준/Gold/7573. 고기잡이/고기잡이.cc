#include <stdio.h>

const int MAX_n = 10000;
const int MAX_m = 100;
int ans, n, l, m, idx;
char section[MAX_n + 5][MAX_n + 5];
struct Node {
    int x, y;
}fish[MAX_m], chk[MAX_m * MAX_m];

void fishing(int sx, int sy, int l1, int l2) {
    int cnt = 0;
    int ex = sx + l1, ey = sy + l2;
    for (int i = 0; i < m; ++i) {
        if (sx <= fish[i].x && fish[i].x <= ex && sy <= fish[i].y && fish[i].y <= ey){
            cnt++;
        }
    }
    if (ans < cnt){
        ans = cnt;
    } 
    else{
        ans = ans;
    }
}

int main(){
    scanf("%d %d %d", &n, &l, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &fish[i].x, &fish[i].y);
        section[fish[i].x][fish[i].y] = 'Y';
        chk[idx++] = {fish[i].x, fish[i].y};
    }
    for(int i = 0; i < m - 1; ++i){
        for(int j = i; j < m; ++j){
            if(section[fish[i].x][fish[j].y] != 'Y'){
                chk[idx++] = {fish[i].x, fish[j].y};
                section[fish[i].x][fish[j].y] = 'Y';
            }
            if (section[fish[j].x][fish[i].y] != 'Y'){
                chk[idx++] = {fish[j].x, fish[i].y};
                section[fish[j].x][fish[i].y] = 'Y';
            }
        }
    }
    int a = 1, l2 = (l - 2) / 2;
    while (l2 > 0){
        for (int i = 0; i < idx; ++i){
            fishing(chk[i].x, chk[i].y, a, l2);
        }
        a++; l2--;
    }
    printf("%d\n", ans);
}