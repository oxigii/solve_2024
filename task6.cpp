#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void makes(char s[]) {
	int i = 0, j = strlen(s) - 1;
	int r = 0;
	char p[50];
	while (true) {
		if (s[i] == s[j]) { i++; j--; }
		else if (s[i] != s[j]) { p[r] = s[i]; i++; r++; j = strlen(s) - 1; }
		if (i >= j) break;
	}
	p[r] = '\0';
	int len = strlen(p);
	for (int k = len - 1; k >= 0; k--) {
		strncat(s, &p[k], 1);
	}
}

int main() {
	char str[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		makes(str);
		cout << str << endl;
	}
}

bool ispal(char s[]) {
	int i, len = strlen(s);
	for (i = 0; i < len / 2; i++) {
		if (s[i] != s[len - 1 - i]) return false;
	}
	return true;
}