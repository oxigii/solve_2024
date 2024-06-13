#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX 8
int chess[MAX][MAX];

int cnt = 0;
int cnt1 = 0;
char memo[92][MAX * 2 + 1];

void prt() {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d", chess[i][j]);
        }
        printf("\n");
    }
    printf("%d _____________\n", cnt);
}

int promise(int row, int col) {
    int i;
    if (row >= MAX || col >= MAX) {
        return 0;
    }
    else {
        for (i = 1; row - i >= 0; i++) {
            if (chess[row - i][col] == 1) return 0;
            else if (col - i >= 0 && chess[row - i][col - i] == 1) return 0;
            else if (col + i < MAX && chess[row - i][col + i] == 1) return 0;
        }
    }
    return 1;
}

void queen(int row) {
    int i;
    if (row == MAX) {
        cnt++;
        prt();
    }

    if (row < MAX) {
        for (i = 0; i < MAX; i++) {
            if (promise(row, i)) {
                chess[row][i] = 1;
                queen(row + 1);
                chess[row][i] = 0;
            }
        }
    }
}

// 5주차 과제
void prt1() {
    for (int i = 0; i < cnt1; i++) {
        printf("[%d] : %s\n", i, memo[i]);
    }
}

int promise1(int row, int col) {
    int i;
    if (row >= MAX || col >= MAX) {
        return 0;
    }
    else {
        for (i = 1; row - i >= 0; i++) {
            if (chess[row - i][col] == 1) return 0;
            else if (col - i >= 0 && chess[row - i][col - i] == 1) return 0;
            else if (col + i < MAX && chess[row - i][col + i] == 1) return 0;
        }
    }
    return 1;
}

void queen2(int row) {
    if (row == MAX) {
        char result[MAX * 2 + 1];
        memset(result, 0, sizeof(result));
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (chess[i][j] == 1) {
                    char temp[3];
                    sprintf(temp, "%d ", j);
                    strcat(result, temp);
                }
            }
        }
        strcpy(memo[cnt1], result);
        cnt1++;
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (promise1(row, i)) {
            chess[row][i] = 1;
            queen2(row + 1);
            chess[row][i] = 0;
        }
    }
}

int main()
{
    queen(0);
    queen2(0);
    prt1();
    return 0;
}