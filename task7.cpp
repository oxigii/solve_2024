#include <iostream>
#include <string>
using namespace std;

int skip[1024];

void make_skip(const string& pat) {
    int m = pat.size();
    int pp = 0;
    skip[0] = 0;
    for (int pt = 1; pt < m; pt++) {
        if (pat[pt] == pat[pp]) {
            pp++;
            skip[pt] = pp;
        }
        else {
            if (pp != 0) {
                pp = skip[pp - 1];
                pt--;
            }
            else {
                skip[pt] = 0;
            }
        }
    }
}

int kmp(const string& txt, const string& pat) {
    int n = txt.size();
    int m = pat.size();
    int pt = 0;
    int pp = 0;

    while (pt < n) {
        cout << "txt: " << txt.substr(0, pt + 1) << endl;
        cout << "pat: " << pat.substr(0, pp + 1) << endl;

        if (txt[pt] == pat[pp]) {
            pt++;
            pp++;
        }

        if (pp == m) {
            return pt - pp;
        }
        else if (pt < n && txt[pt] != pat[pp]) {
            if (pp != 0) {
                pp = skip[pp - 1];
            }
            else {
                pt++;
            }
        }
    }

    return -1;
}

int main() {
    string txt, pat;

    cin >> txt;
    cin >> pat;

    make_skip(pat);
    for (int i = 0; i < pat.size()-1; i++) {
        cout << skip[i] << " ";
    }
    cout << endl;

    int pos = kmp(txt, pat);
    if (pos != -1) {
        cout << pos <<  endl;
    }
    else {
        cout << "패턴을 찾을 수 없습니다." << endl;
    }

    return 0;
}
