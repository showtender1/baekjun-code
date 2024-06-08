#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a;
vector<int >v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	reverse(v.begin(), v.end());
	int dp[2000];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxnum = 0;
	for (int i = 0; i < n; i++) {
		maxnum = max(maxnum, dp[i]);
	}
	cout << n - maxnum;
}