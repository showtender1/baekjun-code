#include <stdio.h>
#include <stdbool.h>

bool p(int board[15][15], int n, int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

void l(int board[15][15], int n, int col, int *cnt) {
    if (col >= n) {
        (*cnt)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (p(board, n, i, col)) {
            board[i][col] = 1;
            l(board, n, col + 1, cnt);
            board[i][col] = 0;
        }
    }
}

int k(int n) {
    int board[15][15] = {0};
    int cnt = 0;
    l(board, n, 0, &cnt);
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = k(n);
    printf("%d\n", m);
    return 0;
}

