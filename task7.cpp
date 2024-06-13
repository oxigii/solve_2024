#include<iostream>
#include<cstring>
using namespace std;

int bf_match(const char* txt, const char* pat) {
	int pt = 0;
	int pp = 0;
	int count = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++; pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
		/*if (pp == strlen(pat)) { 
			count++; pp = 0;
		}*/
	}
	//return count;
	if (pp == strlen(pat)) return pt - pp;
	else return -1;
}

int main() {
	char text[256];
	char pattern[256];
	int idx;

	cout << "input text: ";
	cin >> text;
	cout << "input pattern: ";
	cin >> pattern;
	idx = bf_match(text, pattern);
	if (idx == -1) cout << "텍스트에 패턴이 없음" << endl;
	else cout << "인덱스에 패턴이 있음 -> " << idx << endl;
//	else cout << "인덱스에 있는 패턴 개수 -> " << idx << endl;
	return 0;
}