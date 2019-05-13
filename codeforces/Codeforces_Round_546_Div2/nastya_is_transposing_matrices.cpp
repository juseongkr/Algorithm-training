#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> before[1001], after[1001];
	int n, m, t;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> t;
			before[i+j].push_back(t);
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> t;
			after[i+j].push_back(t);
		}
	}

	for (int i=0; i<=(n-1)+(m-1); ++i) {
		sort(before[i].begin(), before[i].end());
		sort(after[i].begin(), after[i].end());

		if (before[i] != after[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	
	return 0;
}
