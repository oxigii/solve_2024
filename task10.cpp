#include<iostream>
using namespace std;
#define MAX 11
int gold[MAX][MAX], cell[MAX][MAX], path[MAX][MAX];

int main() {
	int R, C, i, j;
	cin >> R >> C;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cin >> gold[i][j];
		}
	}
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
				if (cell[i - 1][j] >= cell[i][j - 1]) cell[i][j] = cell[i - 1][j] + gold[i][j];
				else cell[i][j] = cell[i][j - 1] + gold[i][j];
		}
	}

	cout << cell[R][C] << endl;
	i = R, j = C;
	while (i > 0 && j > 0) {
		if (cell[i - 1][j] > cell[i][j - 1] || j == 1) { path[i][j] = 1; i--; }
		else { path[i][j] = 1; j--; }
	}

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) cout << path[i][j] << " ";
		cout << endl;
	}
}