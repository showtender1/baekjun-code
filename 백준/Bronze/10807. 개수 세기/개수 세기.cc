#include <stdio.h>

int main(){
    int n;
    int cnt = 0;
    int v;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &v);
    for(int i = 0; i < n; i++){
        if(arr[i] == v){
            cnt++;
        }
    }
    printf("%d", cnt);
}