#include <iostream>
using namespace std;

int main()
{
	string a, b;
	int idx_a, idx_b;
	bool flag = false;

	cin >> a >> b;
	for (int i=0; i<a.length(); ++i) {
		for (int j=0; j<b.length(); ++j) {
			if (a[i] == b[j]) {
				idx_a = i;
				idx_b = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	for (int i=0; i<b.length(); ++i) {
		for (int j=0; j<a.length(); ++j) {
			if (i == idx_b && j == idx_a)
				cout << a[j];
			else if (idx_b == i)
				cout << a[j];
			else if (idx_a == j)
				cout << b[i];
			else
				cout << ".";
		}
		cout << '\n';
	}

	return 0;
}
