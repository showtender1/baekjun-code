#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int arr2[500001];
int arr3[500001] = {0,};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < m; i++){
        int right = n - 1;
        int left = 0;
        while (left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] == arr2[i]){
                arr3[i] = 1;
                break;
            }
            if(arr[mid] > arr2[i]){
                right = mid - 1;
            }
            else left = mid + 1;
        }
    }
    for(int i = 0; i < m; i++){
        cout << arr3[i] << '\n'; 
    }
}