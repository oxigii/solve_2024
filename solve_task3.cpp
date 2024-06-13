#include<iostream>
using namespace std;

int stairs(int n) {
	if (n <= 1) return 1;
	else return stairs(n - 1) + stairs(n - 2); //피보나치수열
}

int main() {
	int n;
	cin >> n;
	cout << "경우의 수: " << stairs(n);

	return 0;
}