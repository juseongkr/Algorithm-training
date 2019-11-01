#include <iostream>
using namespace std;

int main()
{
	int n, m, l, x, sum = 0;

	cin >> n >> m >> l;
	for (int i=0; i<n; ++i) {
		cin >> x;
		sum += x;
	}

	if (sum == m) {
		cout << "0\n";
	} else if ((sum < l && m - sum < l) || sum > m) {
		cout << "-1\n";
	} else {
		cout << "1\n";
	}

	return 0;
}
