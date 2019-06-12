#include <iostream>
using namespace std;

int main()
{
	int num[10001];
	int n, q, t, k = 0;

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> t;
		for (int j=k; j<k+t; ++j)
			num[j] = i+1;
		k += t;
	}

	for (int i=0; i<q; ++i) {
		cin >> t;
		cout << num[t] << '\n';
	}

	return 0;
}
