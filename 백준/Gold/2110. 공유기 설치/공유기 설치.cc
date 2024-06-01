#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, c;
    int num;
    int st;
    int r; 
    int start, end, mid;
    int ans = 0;
	cin >> n >> c;
	vector<int> pos;
	for (int i = 0; i < n; i++){
		cin >> num;
		pos.push_back(num);
	}
	sort(pos.begin(), pos.end());
	start = 1;
	end = pos[n - 1] - pos[0];
	while (start <= end){
		r = 1;
		mid = (start + end) / 2;
		st = pos[0];
		for (int i = 1; i < n; i++)
		{
			if (pos[i] - st >= mid)
			{
				r++;
				st = pos[i];
			}
		}
		if (r >= c)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << ans;
	return 0;
}
