#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 함수 d
int d(int number) {
	int sum = number;
	while (number != 0)
	{
		sum = sum + (number % 10); //첫번째 자리수
		number = number / 10; // 10을 나누어서 첫째 자리가 없어진다.
		// 567
	}
	return sum;
}


int main() {
	bool check[10001] = { false, };
	for (int i = 1; i < 10001; i++)
	{
		int n = d(i); //sum을 해줘서 return한 값이 n에 대입
		if (n < 10001) {
			check[n] = true;
		}
	}

	for (int i = 1; i < 10001; i++)
	{
		if (!check[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}