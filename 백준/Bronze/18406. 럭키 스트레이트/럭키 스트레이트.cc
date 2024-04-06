#include <stdio.h>

int main(){
    int n;
    int cnt = 0;
    int i = 0;
    int lowadd = 0;
    int highadd = 0;
    scanf("%d", &n);
    int arr[10];
    while(n != 0){
      arr[i] = n % 10;
      n /= 10;
      cnt++;
      i++;
    }
    for(int i = 0; i < cnt; i++){
        if(i < cnt/2){
            lowadd += arr[i];
        }
        else highadd += arr[i];
    }
    if(lowadd == highadd){
        printf("LUCKY");
    }
    else printf("READY");
    return 0;
}
