#include <iostream>
using namespace std;

int m[10];

int main()
{
	int l, r;

	cin >> l >> r;
	for (int i=l; i<=r; ++i) {
		fill(m, m+10, 0);
		bool flag = true;
		int num = i;
		while (num) {
			m[num%10]++;
			num /= 10;
		}
		for (int j=0; j<10; ++j) {
			if (m[j] >= 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}
