#include<iostream>
using namespace std;

int stairs(int n) {
	if (n <= 1) return 1;
	else return stairs(n - 1) + stairs(n - 2); //�Ǻ���ġ����
}

int main() {
	int n;
	cin >> n;
	cout << "����� ��: " << stairs(n);

	return 0;
}