#include <iostream>
using namespace std;

int n;
int sequence[11];
int operators[4];
int minnum = 1000000001;
int maxnum = -1000000001;
void calculate(int res, int idx){
    if(idx == n){
        if(res > maxnum)
            maxnum = res;
        if(res < minnum)
            minnum = res;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0)
                calculate(res + sequence[idx], idx+1);
            else if(i == 1)
                calculate(res - sequence[idx], idx+1);
            else if(i == 2)
                calculate(res * sequence[idx], idx+1);
            else
                calculate(res / sequence[idx], idx+1);
            operators[i]++;
        }
    }
    return;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sequence[i];
    for(int i = 0; i < 4; i++)
        cin >> operators[i];
    calculate(sequence[0],1);
    cout << maxnum << '\n';
    cout << minnum;
}
