#include <stdio.h>
#include <stdlib.h>

int n, m;
int arr[1000001];
int arr2[1000001];

void merge(int* arr, int start, int mid, int end){
	int i, j, k;
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end){
		if (arr[i] >= arr[j])
			arr2[k++] = arr[j++];
		else
			arr2[k++] = arr[i++];
	}
	if (i > mid){
		for (int idx = j; idx <= end; idx++){
			arr2[k++] = arr[idx];
		}
	}
	else{
		for (int idx = i; idx <= mid; idx++){
			arr2[k++] = arr[idx];
		}
	}
	for (int idx = start; idx <= end; idx++){
		arr[idx] = arr2[idx];
	}
}

void sort(int* arr, int start, int end){
	int mid;
	if (start < end){
		mid = (start + end) / 2;
		sort(arr, start, mid);
		sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
int search(int* arr, int num){
	int left = 0;
	int right = n;
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] == num)
			return 1;
		else if (arr[mid] > num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		scanf("%d", &n);
		for (int j = 0; j < n; j++){
			scanf("%d", &arr[j]);
		}
		sort(arr, 0, n);
		scanf("%d", &m);
		int num;
		for (int j = 0; j < m; j++){
			scanf("%d", &num);
			printf("%d\n", search(arr, num));
		}
		for (int j = 0; j < n; j++){
			arr[j] = 0;
		}
	}
	return 0;
}