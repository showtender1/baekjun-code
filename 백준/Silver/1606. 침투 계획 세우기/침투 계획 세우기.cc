#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int x, y;
    cin >> x >> y;
    
    long long ans = 1;
    
    for(int i = 1; i < x+y+(y ? 0 : 1); i++) {
        ans += 6 * i;
    }
    
    cout << ans+y;
}