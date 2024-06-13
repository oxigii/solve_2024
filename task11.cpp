#include<iostream>
#include<cstdlib>
using namespace std;

#define cMAX 20
#define mMAX 1001
int coin[cMAX];
int money[cMAX][mMAX];
int cnt[cMAX];

int main() {
	int n, nc, c;
	int i, j;
	cin >> n >> nc;
	for (i = 0; i < nc; i++)
		cin >> coin[i];
	c = coin[0];
	for (i = c; i <= n; i++) {
		money[0][i] = money[0][i - c] + 1;
	}
	
	for (i = 1; i <= nc; i++) {
		c = coin[i];
		for (j = 0; j <= n; j++) {
			if (j < c || money[i - 1][j] < money[i][j - c] + 1) money[i][j] = money[i - 1][j];
			else money[i][j] = money[i][j - c] + 1;
		}
	}

	cout << "   ";
	for (i = 1; i <= n; i++) cout << i << " ";
	cout << endl;
	for (i = 0; i < nc; i++) {
		cout << coin[i] << ": ";
		for (j = 1; j <= n; j++) cout << money[i][j] << " ";
		cout << endl;
	}

	int k = n;
	for (i = nc - 1; i >= 0; i--) {
		c = coin[i];
		while (k >= c && money[i][k] == money[i][k - c] + 1) {
			cnt[i]++;
			k -= c;
		}
	}

	for (i = 0; i < nc; i++) {
		cout << coin[i] << ": " << cnt[i] << endl;
	}
}