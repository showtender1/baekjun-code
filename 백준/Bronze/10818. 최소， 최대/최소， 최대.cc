#include <iostream>
#include <algorithm>

 

using namespace std;

 

int main() {

 

    cin.tie(NULL);
    ios::sync_with_stdio(false);

 

    int n;
    int arr[2000000];
    cin >> n;

 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

 

    sort(arr, arr + n);

 

    cout << arr[0] << " " << arr[n - 1];
    return 0;
}