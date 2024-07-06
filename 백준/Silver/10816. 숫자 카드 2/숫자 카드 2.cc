#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define MAX 500001

int n, m;
int arr[MAX];
int arr2[MAX];

int L(int* arr, int key, int len) {
	int mid;
	int start = 0, fin = len - 1;
	while (start < fin) {
		mid = (start + fin) / 2;
		if (key <= arr[mid])
			fin = mid;
		else
			start = mid + 1;
	}
	return fin;
}

int U(int* arr, int key, int len) {
	int mid;
	int start = 0, fin = len - 1;

	while (start < fin) {
		mid = (start + fin) / 2;
		if (key < arr[mid])
			fin = mid;
		else
			start = mid + 1;
	}
	if (arr[fin] == key) {
		return fin + 1;
	}
	return fin;
}

int cmp(const void* lhs, const void* rhs) {
	if (*(int*)lhs > *(int*)rhs) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}
	qsort(arr, n, sizeof(int), cmp);
	int lower;
	int upper;
	for (int i = 0; i < m; i++) {
		lower = L(arr, arr2[i], n);
		upper = U(arr, arr2[i], n);
		printf("%d ", upper-lower);
	}
	return 0;
}