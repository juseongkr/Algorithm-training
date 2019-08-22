#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long t;
	vector<long long> a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		a.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		b.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		auto it = upper_bound(b.begin()+i, b.end(), a[i]) - (b.begin()+i);
		cout << it-1 << ' ';
	}

	return 0;
}
