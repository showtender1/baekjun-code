#include <stdio.h>

int main(){
    char arr[50][51];
    int a, b, count = 3000;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++)
        scanf("%s", arr[i]);
    int temp1 = 0, temp2 = 0;
    for (int x = 0; x < a - 7; x++) {
        for (int y = 0; y < b - 7; y++) {
            for (int i = x; i < x + 8; i++) {
                for (int j = y; j < y + 8; j++) {
                    if (((i - x + j - y) % 2) == 0) {
                        if (arr[i][j] != 'W')
                            temp1++;
                    }
                    else {
                        if (arr[i][j] != 'B')
                            temp1++;
                    }
                }
            }
            for (int i = x; i < x + 8; i++) {
                for (int j = y; j < y + 8; j++) {
                    if (((i - x + j - y) % 2) == 0) {
                        if (arr[i][j] != 'B')
                            temp2++;
                    }
                    else {
                        if (arr[i][j] != 'W')
                            temp2++;
                    }
                }
            }
            int res = temp1 < temp2 ? temp1 : temp2;
            if (res < count) count = res;
            temp1 = 0;
            temp2 = 0;
        }
    }
    printf("%d", count);
    return 0;
}