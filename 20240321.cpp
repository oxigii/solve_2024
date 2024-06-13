#include <iostream>
using namespace std;

int power(int x, int n) {
	if (n == 0) return 1;
	if (n >= 1)	return x * power(x, n - 1);
}

int reGcd(int a, int b) {
	if (a % b == 0) return b;
	if (a % b != 0) return reGcd(b, a % b);
}

int gcd(int a, int b) {
	while (true) {
		int r = a % b;
		if (r == 0) return b;
		a = b;
		b = r;
	}
}

int main() {
	/*int n, x;
	cin >> x >> n;
	cout << power(x, n);*/
	int a, b;
	cin >> a >> b;
	cout << reGcd(a, b) << "\n" << gcd(a, b);
	return 0;
}