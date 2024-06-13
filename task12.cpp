#include<iostream>
#include<cstring>
using namespace std;

#define MAX 30
char str1[MAX];
char str2[MAX];
int cnt[MAX][MAX];
char same[MAX];

int main() {
	int i, j;
	int len1, len2;
	cout << "first string: ";
	cin >> str1;
	cout << "second string: ";
	cin >> str2;
	len1 = strlen(str1); len2 = strlen(str2);
	if (str1[0] == str2[0]) cnt[0][0] = 1;
	else cnt[0][0] = 0;
	for (j = 1; j < len2; j++) {
		if (str1[0] == str2[j])cnt[0][j] = 1;
		else cnt[0][j] = cnt[0][j - 1];
	}

	for (i = 1; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (str1[i] == str2[j]) { 
				if (j - 1 < 0) cnt[i][j] = 1;
				else cnt[i][j] = cnt[i - 1][j - 1] + 1;
			}
			else {
				if (cnt[i - 1][j] > cnt[i][j - 1] || j - 1 < 0) cnt[i][j] = cnt[i - 1][j];
				else cnt[i][j] = cnt[i][j - 1];
			}
		}
	}

	cout << "      ";
	for (i = 0; i < len1; i++) cout << str2[i] << "  ";
	cout << endl;

	for (i = 0; i < len1; i++) {
		cout << str1[i] << "  :  ";
		for (j = 0; j < len2; j++) {
			cout << cnt[i][j] << "  ";
		}
		cout << endl;
	}

	int index = cnt[len1 - 1][len2 - 1];
	same[index] = '\0';
	i = len1 - 1;  j = len2 - 1;
	while (i >= 0 && j >= 0) {
		if (str1[i] == str2[j]) {
			same[--index] = str1[i];
			i--; j--;
		}
		else if (i > 0 && cnt[i - 1][j] >= cnt[i][j - 1]) i--;
		else j--;
	}

	cout << same << endl;
}